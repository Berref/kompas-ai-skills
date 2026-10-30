////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для элементов
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <Libhppar.h>
#include "CPar.h"
#include <map>
#include <PARRAY.H>
#include <SafeArrayUtils.h>

CPar * procObj = nullptr;
bool   repeat = false;              // Процесс прерван но его нужно продолжить
// Placement на Cursor


extern ksAPI7::IApplicationPtr newKompasAPI; // Интерфейс Приложения Компас 

extern unsigned int WINAPI LIBRARYID();


//-------------------------------------------------------------------------------------
// Базовые параметры элемента
//---
BaseMacroParam::BaseMacroParam()
{
  memset(&version, 0, sizeof(BaseMacroParam));
  drawType = ID_VIEW;
}

//-------------------------------------------------------------------------------------
// Конструктор
//---
CPar::CPar(unsigned int _command, reference _ref, bool fromDB)
  : PropertyManagerObject()
  , command(_command)
  , refMacr(_ref)
  , x(0)
  , y(0)
  , angle(0)
  , spcObject(0)
  , changed(false)
  , fromDataBase(fromDB)
{
  if (_ref)
  {
    flagMode = true;
    GetMacroPlacement(_ref, &x, &y, &angle);
  }
  else
    m_baseParam.version = GetVersion();
}


//-------------------------------------------------------------------------------------
// Сообшение о ошибке 
//---
void CPar::_MessageBoxResult()
{
  long res = ReturnResult();
  if (res)
  {
    if (res != etError10) //  10 - Ошибка! Вырожденный объект
      MessageBoxResult();
    ResultNULL();
  }
}


//-------------------------------------------------------------------------------------
// оператор присваивания
//---
void CPar::Assign(const CPar & other)
{
  command = other.command;
  refMacr = other.refMacr;
  flagMode = other.flagMode;
  //  objError    = other.objError;
  angle = other.angle;
  m_baseParam = other.m_baseParam;
}


//-------------------------------------------------------------------------------------
// Создание объекта спецификации
//---
bool CPar::DrawSpcObj(reference _group)
{
  spcObject = 0;
  if (m_baseParam.flags.flagAttr && IsSpcObjCreate())
  {
    _MessageBoxResult();
    spcObject = EditSpcObj(_group);
  }
  return !!spcObject;
}


//-------------------------------------------------------------------------------------
// Запуск процесса Placement
//---
void CPar::PlacementProcess()
{
  ksAPI7::IKompasDocument2D1Ptr doc2D(newKompasAPI->ActiveDocument);

  if (doc2D)
  {
    ksAPI7::IProcess2DPtr process2D;
    process2D = doc2D->LibProcess[ksProcess2DPlacement];
    process = process2D;

    m_process2D = process2D;
    ksAPI7::IPhantom2DPtr phantom(process2D->Phantom2D);

    if (process)
    {
      process->ProcessParam = procParam;
      process2D->X = x;
      process2D->Y = y;
      process2D->Angle = angle;

      process->ProcessParam = procParam;

      process->ProcessParam = procParam;

      Draw1();
      new Process2DEvent(process, *this, true);
      process->Run(false, false);
    }
  }
}


//----------------------------------------------------------------------------------------------
// Зaгрузить строку из ресурсов
//---
char * _LoadString(int ID)
{
  static char buf[255];
  ksConvertLangStrEx(StepDLL.hModule, ID, buf, 255);
  return buf;
}


//-------------------------------------------------------------------------------------
// Перерисовать фантом, слайд, вывести новые параметры  
//---
void CPar::RedrawPhantom()
{
  if (Changed())
  {

    if (process)
      process->Update();

    // Перезаполняем грид
    if (paramGrid)
    {
      rowIndex = 1;
      ShowParam();
      paramGrid->RowCount = rowIndex;
      paramGrid->UpdateParam();
    }
    // Перерисовываем группу в окне
    if (slideBox)
    {
      // Удаляем старую группу
      reference gr = (long)slideBox->DrawingSlide;
      if (gr)
        DeleteObj(gr);
      // Рисуем новую
      gr = GetPreviewGroup();
      slideBox->DrawingSlide = _variant_t(gr);
      slideBox->UpdateParam();
    }
  }
}


//---------------------------------------------------------------------------
// Отрисовка фантома
//---
void CPar::DrawPhantom(double x, double y, double angle, BOOL dynamic)
{
  if (!dynamic)
  {
    // Создание временной группы
    reference gr1 = NewGroup(1);
    EndGroup();

    // Меняем местами две группы
    ::AddObjGroup(gr1, refMacr);

    SetParam();

    ::SetMacroPlacement(refMacr, x, y, angle, 0);
    ::StoreTmpGroup(gr1);

    DrawSpcObj(gr1);

    if (m_baseParam.flags.flagAttr && spcObject)
    {
      newKompasAPI->StopCurrentProcess(TRUE, NULL);
    }
    else
      Draw1();
  }
}


//---------------------------------------------------------------------------
// Завершение процесса
//---
BOOL CPar::EndProcess()
{
  BOOL res = FALSE;
  if (processState == ProcessState::processPlacement)
  {
    if (m_baseParam.flags.flagAttr && spcObject)
    {
      EditSpcObject();
    }
    else
      res = PropertyManagerObject::EndProcess();
  }
  else
  {
    if (processState == ProcessState::processCreateLeader)
    {
      posLeater = ksCreateViewObject(POSLEADER_OBJ);
      DrawPosLeader();
      flagMode = 0;
    }
    processState = ProcessState::processPlacement;
    spcObject = 0;

    if (!flagMode)
    {
      Draw1();
      process->Run(VARIANT_FALSE, VARIANT_TRUE);
    }
  }
  return res;
}

//---------------------------------------------------------------------------
// Отписаться от событий процесса
//---
void CPar::UnadviseEvents()
{
  ABaseEvent::TerminateEvents(posLiaderParam);
  ABaseEvent::TerminateEvents(leaderProcess);
  PropertyManagerObject::UnadviseEvents();
}

//---------------------------------------------------------------------------
// Создать группу параметров штриховки
//---
void CPar::CreatePropertyGroup()
{
  if (curentCollection)
  {
    if (hatchCtrl = curentCollection->Add(ksControlGroupBegin))
    {
      InitPropertyControl(hatchCtrl, IDP_HATCH_PARAM, ID_PROP_HATCH_PARAM);

      angleEdit = curentCollection->Add(ksControlEditAngle);
      if (angleEdit)
      {
        InitPropertyControl(angleEdit, IDP_HATCHANG_ANGLE, ID_PROP_HATCH_ANGLE/*hint*/, ID_PROP_HATCH_ANGLE/*tips*/, TRUE, ksNameAlwaysVisible, FALSE);
        angleEdit->Value = 45.0;
        angleEdit->SetValueRange(-360.0, 360.0);

        stepEdit = curentCollection->Add(ksControlEditLength);
        if (stepEdit)
        {
          InitPropertyControl(stepEdit, IDP_HATCHANG_STEP, ID_PROP_HATCH_STEP/*hint*/, ID_PROP_HATCH_ANGLE/*tips*/, TRUE, ksNameAlwaysVisible, FALSE);
          stepEdit->Value = 2.0;
          stepEdit->SetValueRange(1.e-002, 100.0);
        }
      }

      curentCollection->Add(ksControlGroupEnd);
    }
  }
}


//---------------------------------------------------------------------------
// Редактирование объекта спецификации
//---
void CPar::EditSpcObject()
{
  // редактирование объекта спецификации
  if (m_baseParam.flags.flagAttr && spcObject)
  {
    if (ksEditWindowSpcObject(spcObject))
      LeaderCall();                         // Создание линии выноски
  }
}


//-------------------------------------------------------------------------------------
// ksPlacementChanged    -Изменено положения объекта
// ---
BOOL CPar::PlacementChanged(double x, double y, double angle, BOOL dynamic)
{
  ::ksUndoContainer(true);
  if (IsEditMode()) // Редактирование
  {
    refMacr = m_editMode;
    ::ksSetMacroPlacementEx(refMacr, x, y, angle, 0/*relative*/, 0);
    RedrawMacro();
    m_phantomGroup->Clear(false);
  }
  else if (processState == ProcessState::processPlacement)
  {
    DrawPhantom(x, y, angle, dynamic);
  }
  else
  {
    PosLeater(x, y, dynamic);
    if (!dynamic)
      DrawPosLeader();
  }
  return TRUE;
}


//-------------------------------------------------------------------------------------
// Отрисовать фантом
//---
void CPar::Draw1()
{
  ksAPI7::IProcess2DPtr process2D(process);

  if (process2D)
  {
    ksAPI7::IPhantom2DPtr phantom(process2D->Phantom2D);
    if (phantom)
    {
      bool newPh = !m_phantomGroup;
      if (newPh)
      {
        phantom->PhantomType = ksMoveGroupPhantom;

        reference gr = NewGroup(1);
        EndGroup();
        m_phantomGroup = IUnknownPtr(ksTransferReference(gr, 0), false);
        phantom->PhantomGroup = m_phantomGroup;
      }

      if (m_phantomGroup)
      {
        m_phantomGroup->Clear(VARIANT_TRUE);
        m_phantomGroup->Open();
        ::Macro(0);
        refMacr = ::EndObj();
        ksOpenMacro(refMacr);
        GetGroup();
        refMacr = ::EndObj();
        m_phantomGroup->Close();
      }
      if (!newPh)
      {
        phantom->Update();
      }
    }
  }
}


//-------------------------------------------------------------------------------------
// Отрисовка группы
//---
void CPar::DrawGroup(reference & gr)
{
  if (::ExistObj(gr))  // Если группа уже существует
    ::DeleteObj(gr);  // удаляем её

  gr = ::NewGroup(1/*временный тип группы*/); // Создаём новую группу
  refMacr = 0;
  ::Macro(0);

  GetGroup();                                   // геометрия эл-та
  if (!refMacr)
    refMacr = ::EndObj();

  ::EndGroup();                                 // Запомнить группу
  _MessageBoxResult();
  changed = false;
}


//-------------------------------------------------------------------------------------
// Группа для отрисовки в окне
//---
void CPar::RedrawMacro()
{
  if (procObj)
    RedrawPhantom();
  else if (refMacr)
  {
    reference gr = ::NewGroup(1/*временный тип группы*/); // Создаём новую группу
    GetGroup();                                             // геометрия эл-та
    ::EndGroup();                                           // Запомнить группу
    ksUpdateMacro(refMacr, gr);
    ksClearGroup(gr, 0);
    DeleteObj(gr);
    SetParam();
  }
  changed = false;
}


//-------------------------------------------------------------------------------------
// Группа для отрисовки в окне
//---
reference CPar::GetPreviewGroup()
{
  reference gr = ::NewGroup(1/*временный тип группы*/); // Создаём новую группу
  RedrawPreview();
  //GetGroup();
  ::EndGroup(); // Запомнить группу
  return gr;
}


//----------------------------------------------------------------------------------------------
// Копирование параметров из reference другой гайки
// ---
void CPar::AssignRef(reference ref)
{
  GetMacroParam(ref, *this, Size());
}


// HOT_POINTS ##################################################################

//-------------------------------------------------------------------------------------
// Изменение положения и угла поворота
//---
bool CPar::SetHotPoint(HotPointDescription * point, int index)
{
  switch (index)
  {
  case 0: // Хотточка перемещения 
  {
    SetPlacement(point->x, point->y, 0.0);
    break;
  }
  case 1: // Хотточка перемещения  
  {
    double angle = ::Angle(0, 0, point->x, point->y);
    SetPlacement(0, 0, angle);
    break;
  }
  }
  return index < 2;
}

// HOT_POINTS ##################################################################

//-------------------------------------------------------------------------------
// Параметры макро
// ---
void CPar::SetParam()
{
  if (refMacr)
  {
    m_baseParam.version = GetVersion();
    ksSetMacroParam(refMacr, *this, Size(), 0, 0, command, MP_HOTPOINTS | MP_PROPERTY_OBJECT);
  }
}


//-------------------------------------------------------------------------------
// Положение макро
// ---
void CPar::SetPlacement(double newX, double newY, double newAng)
{
  if (refMacr)
  {
    ::SetMacroPlacement(refMacr, newX, newY, newAng, 1);
    ::GetMacroPlacement(refMacr, &x, &y, &angle);
  }
}


//------------------------------------------------------------------------------
// создание спецификации
//
reference CPar::EditSpcObj(reference _group)
{
  spcObject = 0;

  ksAPI7::ISpecificationBaseObjectPtr obj1;

  ksAPI7::IKompasDocumentPtr kompasDoc = newKompasAPI->ActiveDocument;

  ksAPI7::IKompasDocument1Ptr kompasDoc1(kompasDoc);
  ksAPI7::ISpecificationObjectCreateParamPtr ObjectCreateParam(kompasDoc1->GetInterface(ksSpecificationObjectCreateParam));

  if (m_spcBaseObjects == NULL)
  {
    ksAPI7::ISpecificationDescriptionsPtr descriptions = kompasDoc->SpecificationDescriptions;
    ksAPI7::ISpecificationDescriptionPtr description = descriptions->Active;

    if (!description)
      description = descriptions->Add(_T(""), 0, _T(""));

    if (description)
      m_spcBaseObjects = description->BaseObjects;
  }

  ksAPI7::IMacroObjectPtr macro(IUnknownPtr(ksTransferReference(refMacr, 0), false/*AddRef*/));

  if (macro)
  {
    macro->Name = GetObjName();

    ksAPI7::IPropertyKeeperPtr propertyKeeperIn1(macro);

    ObjectCreateParam->Section = STANDART_SECTION;
    ObjectCreateParam->AttributeNumber = AttrNumber();

    if (flagMode && m_spcBaseObjects)
    {
      _variant_t var = m_spcBaseObjects->GetSpecificationObjectsForGeom((LPDISPATCH)propertyKeeperIn1, FALSE, STANDART_SECTION, AttrNumber());
      PArray<ksAPI7::ISpecificationBaseObjectPtr> arr;
      FillObjects(var, arr);
      if (arr.Count() > 0)
        obj1 = *arr[0];
    }

    if (m_spcBaseObjects && !flagMode)
    {
      if (!obj1)
      {
        // Базовый объект добавляется.
        obj1 = m_spcBaseObjects->AddWithParam(ObjectCreateParam, propertyKeeperIn1, FALSE, (LPDISPATCH)propertyKeeperIn1);
      }
    }

    if (obj1)
    {
      _EditSpcObj(obj1);
      obj1->Update();
    }
  }

  return obj1 ? obj1->Reference : 0;
}


//------------------------------------------------------------------------------
// Отключиться от БД
// ---
void CPar::CloseBase(reference bd)
{
  DeleteDB(bd);
}


//------------------------------------------------------------------------------
// Отключиться от БД
// ---
void CPar::CloseBase()
{
  if (base.bg)
    CloseBase(base.bg);
}


//-------------------------------------------------------------------------------
// Наполнить панель контролами
// ---
void CPar::ShowControls()
{
  // Создавать объект спецификации
  if (IsSpcObjCreate())
  {
    ksAPI7::IPropertyCheckBoxPtr checkBox(CreateCheckBox(m_baseParam.flags.flagAttr));
    if (checkBox)
      InitPropertyControl(checkBox, IDP_SPC_OBJ, IDS_SPC_OBJ_TIPS/*hint*/, IDS_SPC_OBJ_TIPS/*tips*/);
  }
}


//-------------------------------------------------------------------------------
// Вывод контрола параметров штриховки
// ---
void CPar::ShowHatchControl()
{
  if (IsHatchObject())
    CreatePropertyGroup();
}

void CPar::SetControlVisible(int ctrlId, bool visible)
{
  ksAPI7::IPropertyControlPtr control(GetPropertyControl(ctrlId));
  if (control)
    control->Visible = visible;
}

//-------------------------------------------------------------------------------
// Изменение доступности контрола параметров штриховки
// ---
void CPar::SetHatchControlVisible(bool visible)
{
  SetControlVisible(IDP_HATCHANG_ANGLE, visible);
  SetControlVisible(IDP_HATCHANG_STEP, visible);
}


//-------------------------------------------------------------------------------
// Отработка изменений значения контрола
// ---
bool CPar::OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT & newVal)
{
  bool res = false;
  switch (ctrlID)
  {
  case IDP_HATCHANG_ANGLE:
    SetHatchAngle(newVal.dblVal);
    res = true;
    changed = true;
    break;
  case IDP_HATCHANG_STEP:
    SetHatchStep(newVal.dblVal);
    res = true;
    changed = true;
    break;
  case IDP_SPC_OBJ:
    m_baseParam.flags.flagAttr = !m_baseParam.flags.flagAttr;
    res = true;
    break;
  }
  return res;
}


//---------------------------------------------------------------------------------------------------- 
// Обработка нажатия кнопок
// ---
bool CPar::OnButtonClick(long buttonID)
{
  bool res = false;
  bool oldSec = HatchEnable(); // Изменен тип отображения
  switch (buttonID)
  {
    // Отображение
  case ID_VIEW: // Вид 
  case ID_LEFT: // Cбоку 
  case ID_TOP: // Cверху
  case ID_SEC: // Вид/разрез  
    m_baseParam.drawType = (short)buttonID;
    Draw1();
    SetChange();
    res = true;
    break;

  case ID_SIMPLE: // Упрощенно
    m_baseParam.flags.flagSimp = !m_baseParam.flags.flagSimp;
    Draw1();
    SetChange();
    res = true;
    break;

  case ID_AXIS: // Рисовать ось
    m_baseParam.flags.flagAxis = !m_baseParam.flags.flagAxis;
    res = true;
    break;
  case ID_LEADER_CREATE: // Создать новую линию выноски
  {
    if (newKompasAPI)
    {
      // Остановка текущего процесса.
      newKompasAPI->StopCurrentProcess(TRUE, NULL);// Должно быть true
      processState = ProcessState::processCreateLeader;
    }
    break;
  }
  }

  if (res)
  {
    // Если переключили тип отрисовки на штриховку
    if (oldSec != HatchEnable())
    {
      SetHatchControlVisible(HatchEnable());
    }
    changed = true;
  }
  return res;
}


//-------------------------------------------------------------------------------------
// Нажата ли кнопка
//---
bool CPar::IsButtonChecked(long buttonID)
{
  bool res = false;
  switch (buttonID)
  {
  case ID_VIEW: // Вид 
  case ID_LEFT: // Cбоку 
  case ID_TOP: // Cверху
  case ID_SEC: // Вид/разрез  
    res = m_baseParam.drawType == (short)buttonID;
    break;
  case ID_SIMPLE: // Упрощенно
    res = m_baseParam.flags.flagSimp;
    break;

  case ID_AXIS: // Рисовать ось
    res = m_baseParam.flags.flagAxis;
    break;
  }
  return res;
}


//-------------------------------------------------------------------------------------
// Запуск процесса выбора линии-выноски
//---
int CPar::LeaderCall()
{
  if (IsSpcObjCreate() && InitPosLeaderParam())
  {
    processState = ProcessState::processSelectLeader;
    if (!leaderProcess)
    {
      ksAPI7::IKompasDocument2D1Ptr cursordoc2D(newKompasAPI->ActiveDocument);
      leaderProcess = cursordoc2D->LibProcess[ksProcess2DCursor];
      leaderProcess->ProcessParam = posLiaderParam;

      new Process2DEvent(leaderProcess, *this, false);
    }
    leaderProcess->Run(false, true);
  }
  return 1;
}


//----------------------------------------------------------------------------------------------------------------------------------
// Поиск линии-выноски
//---
int CPar::PosLeater(double x, double y, BOOL dynamic) {

  oldPosLeader = 0;
  posLeater = 0;
  // Ищем объект в текущих координатах курсора
  reference newPosLeater = ::FindObj(x, y, ::ksGetCursorLimit()); // Величина стороны окошка-ловушки с центром x,y
  // Если объект найден проверяем - является ли он линией выноски
  if (newPosLeater && ::GetObjParam(newPosLeater, 0, 0, ALLPARAM_T) != POSLEADER_OBJ)
    newPosLeater = 0;                        // Найденный объект не линия выноски

  if (!dynamic)                              // Фиксация 
  {
    if (!newPosLeater)
      ::ErrorT(::LoadStr(ID_ERROR_LEADER));  // Сообщение о ошибке  
    else
    {                                        // Если линия выноски найдена
      posLeater = newPosLeater;              // Запоминаем уазатель на линию выноски

      if (oldPosLeader)
        ::LightObj(oldPosLeader, 0);         // Убираем подсветку со старой линии выноски     

      return 0; // Остановить процесс
    }
  }
  else
  {
    // Если нашли новую линию выноски
    if (newPosLeater != oldPosLeader)
    {
      if (oldPosLeader)
        ::LightObj(oldPosLeader, 0);         // Убираем подсветку со старой линии выноски

      oldPosLeader = newPosLeater;

      if (oldPosLeader)
        ::LightObj(oldPosLeader, 1);         // Подсвечиваем новую линию связи
    }
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Отрисовать позиционную линию выноски
// ---
void CPar::DrawPosLeader()
{
  // Линия выноски есть, подключим ее к объекту спецификации 
  if (posLeater > 0)
  {
    // Ввойдем в режим редактирования объекта спецификации
    if (::ksSpcObjectEdit(spcObject))
    {
      // Подключим линию выноски
      ::ksSpcIncludeReference(posLeater, true);
      // Закроем объект спецификации
      ::ksSpcObjectEnd();
      newKompasAPI->StopCurrentProcess(TRUE, NULL);
    }
  }
}

//-------------------------------------------------------------------------------
// Создать закладку параметров создания
// Позиционной линии выноски  
// ---
bool CPar::InitPosLeaderParam()
{
  // Если для объекта есть возможность создания объекта спецификации
  if (newKompasAPI != NULL && posLiaderParam == NULL) {
    try {

      posLiaderParam = newKompasAPI->CreateProcessParam();                 // newKompasAPI->CreateProcessParam();  // Получаем параметры процессы
      if (posLiaderParam) {
        new PropertyManagerEvent(posLiaderParam, *this);                 // Подписываемся на события процесса 
        posLiaderParam->SpecToolbar = pnEnterEscHelp;                         // Тип кнопок на панели свойств
        // Получаем коллекцию закладок панели свойств
        ksAPI7::IPropertyTabsPtr liaderPropTabs = posLiaderParam->PropertyTabs;
        if (liaderPropTabs) {
          _bstr_t tmpBstr(::LoadStr(IDP_POS_LEADER));

          ksAPI7::IPropertyTabPtr propTab = liaderPropTabs->Add(tmpBstr);
          if (propTab) {

            ksAPI7::IPropertyControlsPtr ctrlCollection = propTab->PropertyControls;
            if (ctrlCollection) {

              ksAPI7::IPropertyMultiButtonPtr buttons(ctrlCollection->Add(ksControlMultiButton));
              if (buttons) {
                InitPropertyControl(buttons, ID_LEADER_CREATE, IDS_LEADER_HINT/*hint*/, IDS_LEADER_TIPS/*tips*/);
                buttons->ButtonsType = ksPushButton;
                buttons->ResModule = (LONG_PTR)StepDLL.hModule;
              }
            }
          }
        }
      }
    }

    // Перехват исключений
    catch (_com_error & e)
    {
      DumpError(e);                            // Вывод сообщений о ошибке
    }

    catch (TCHAR * mes) {
      LibMessage(mes, MB_ICONERROR | MB_OK); // Вывод сообщений о ошибке
    }
  }
  //     CreateTab( ID_POS_LEADER );
  //     IPropertyMultiButtonPtr simpleButtons( CreateMultiButton( ksPushButton, IDP_LEADER_BUTTONS ), false /*AddRef*/ // );
  //      // Упрощенно
  //      AddButton( simpleButtons, ID_LEADER_CREATE );
  //     }   
  return posLiaderParam != nullptr;
}
//--------------------------------------------------------------------------
// Считать параметры элемета
//---
int CPar::_GetMacroParam(void * value, unsigned int size)
{
  return ::GetMacroParam(0, value, size);
}


// Окно свойств ##################################################################
//--------------------------------------------------------------------------
// По индексу свойства получить идентификатор
//---
int CPar::GetPropertyID(int index)
{
  int res = 0;
  return res;
}


//--------------------------------------------------------------------------
// Добавить свойство в список свойств
//---
BOOL CPar::GetProperty(int index, PropertyParam & param)
{
  param.propertyId = GetPropertyID(index);
  if (param.propertyId)
  {
    param.propertyInstance = StepDLL.hModule;
    switch (param.propertyId)
    {
    case ID_PROP_ELEMENT_PARAM: // Параметры элемента
    case ID_PROP_HATCH_PARAM:   // Параметры штриховки
    case ID_PROP_VIEW_PARAM:    // Вид
    case ID_PROP_OTHER_PARAM:   // Справочные данные
    {
      param.propertyType = ksOPControlGroup;      // Группа
      param.enable = true;
      break;
    }
    case ID_PROP_DIAM:        // Диаметр резьбы
    {
      param.propertyType = ksOPControlListDouble;   // Вещественный комбобокс   
      param.propertyValue.vt = VT_R8;
      param.propertyValue.dblVal = 0.0;
      param.enable = true;
      param.readOnly = true;
      break;
    }
    case ID_PROP_HATCH_STEP:  // Шаг штриховки
    {
      param.propertyType = ksOPControlEditDouble;   // Вещественное значение   
      param.propertyValue.vt = VT_R8;
      param.propertyValue.dblVal = 0.0;
      param.propertyMinValue = 1.e-002;
      param.propertyMaxValue = 100.0;
      break;
    }
    case ID_PROP_HATCH_ANGLE: // Угол штриховки
    {
      param.propertyType = ksOPControlEditDouble;   // Вещественное значение   
      param.propertyValue.vt = VT_R8;
      param.propertyValue.dblVal = 0.0;
      param.propertyMinValue = -360.0;
      param.propertyMaxValue = 360.0;
      break;
    }
    case ID_PROP_VIEW: // Вид
    case ID_PROP_ISPOLN: // Исполнение
    {
      param.propertyType = ksOPControlListBmp; // Список с иконками      
      param.propertyValue.vt = VT_I4;
      param.propertyValue.lVal = 0;
      param.enable = true;
      break;
    }
    case ID_PROP_SIMPLE: // Упрощенно
    case ID_PROP_AXIS:   // Ось
    {
      param.propertyType = ksOPControlListCheck; // Логическое значение Да \ Нет     
      param.propertyValue.vt = VT_BOOL;
      param.propertyValue.boolVal = VARIANT_FALSE;
      param.enable = true;
      break;
    }
    }
  }
  return !!param.propertyId;
}


//--------------------------------------------------------------------------
// Обновить параметры свойства
//---
BOOL CPar::UpdateProperty(PropertyParam & param)
{
  BOOL res = FALSE;

  if (refMacr && param.propertyId == GetPropertyID(0))
    GetMacroParam(refMacr, *this, Size()); // Возможно элемент уже изменили через всплывающую панель или както еще нужно перечитать параметры

  param.propertyInstance = StepDLL.hModule;
  switch (param.propertyId)
  {
  case ID_PROP_HATCH_STEP:  // Шаг штриховки
  {
    param.enable = HatchEnable();
    param.propertyValue.dblVal = HatchStep();
    res = TRUE;
    break;
  }
  case ID_PROP_HATCH_ANGLE: // Угол штриховки
  {
    param.enable = HatchEnable();
    param.propertyValue.dblVal = HatchAngle();
    res = TRUE;
    break;
  }
  case ID_PROP_VIEW: // Вид
  {
    long view = IDB_ID_VIEW;
    switch (m_baseParam.drawType)
    {
    case ID_VIEW: view = IDB_ID_VIEW;    break; // Вид 
    case ID_TOPVID: view = IDB_ID_TOPVID;  break; // Вид сверху
    case ID_LEFT: view = IDB_ID_SIDEVID; break; // Вид сбоку
    case ID_VIDSEC: view = IDB_ID_VIDSEC;  break; // Вид разрез
    }
    param.propertyValue.lVal = view;
    res = TRUE;
    break;
  }
  case ID_PROP_SIMPLE: // Упрощенно
  {
    param.propertyValue.boolVal = !!m_baseParam.flags.flagSimp;
    res = TRUE;
    break;
  }
  case ID_PROP_AXIS:   // Ось
  {
    param.propertyValue.boolVal = !!m_baseParam.flags.flagAxis;
    res = TRUE;
    break;
  }
  }

  return res;
}


//--------------------------------------------------------------------------
// Изменить свойойство
//---
int CPar::ApplyProperty(PropertyParam & param)
{
  int res = 0;
  switch (param.propertyId)
  {
  case ID_PROP_HATCH_STEP:  // Шаг штриховки
  {
    SetHatchStep(param.propertyValue.dblVal);
    res = 1;
    break;
  }
  case ID_PROP_HATCH_ANGLE: // Угол штриховки
  {
    SetHatchAngle(param.propertyValue.dblVal);
    res = 1;
    break;
  }
  case ID_PROP_VIEW: // Вид
  {
    short view = ID_VIEW;
    switch (param.propertyValue.lVal)
    {
    case IDB_ID_VIEW: view = ID_VIEW;    break; // Вид 
    case IDB_ID_TOPVID: view = ID_TOPVID;  break; // Вид сверху
    case IDB_ID_SIDEVID: view = ID_LEFT;    break; // Вид сбоку
    case IDB_ID_VIDSEC: view = ID_VIDSEC;  break; // Вид разрез
    }
    m_baseParam.drawType = view;
    res = 1;
    break;
  }
  case ID_PROP_SIMPLE: // Упрощенно
  {
    m_baseParam.flags.flagSimp = !!param.propertyValue.boolVal;
    res = 1;
    break;
  }
  case ID_PROP_AXIS:   // Ось
  {
    m_baseParam.flags.flagAxis = !!param.propertyValue.boolVal;
    res = 1;
    break;
  }
  }
  if (res)
    changed = true;
  return res;
}
// Окно свойств ##################################################################


////////////////////////////////////////////////////////////////////////////////
// Прочее
//


//--------------------------------------------------------------------------
// отбросить дробную часть у строки если после "." нули
// "123.000" -> "123";   "123.10" -> "123.1"
// pointToComma =1 заменить '.' на ','
//--------------------------------------------------------------------------
void CheckDecimelPart(TCHAR * s, unsigned int pointToComma)
{
  if (s && ::_tcslen(s))
  {
    TCHAR * c = ::_tcschr(s, _T('.'));
    TCHAR * c1 = c;
    unsigned int flag = 0;
    if (c1)
    {
      c1++;
      while (*c1 != _T('\0') && !flag)
      {
        if (*c1 != _T('0'))
          flag = 1;
        c1++;
      }
      if (!flag)
        *c = _T('\0');
      else
      {
        c1 = &s[::_tcslen(s) - 1];
        while (*c1 == _T('0'))
        {
          *c1 = _T('\0');
          c1--;
        }
        if (pointToComma)
          *c = _T(',');
      }
    }
  }
}


//------------------------------------------------------------------------------
// возвращает полное имя файла (by AVR)
// ---
bool GetFullName(TCHAR * inName, TCHAR * outName, int outNameLen)
{
  bool     rez = false; // результат поиска файла name
  OFSTRUCT ofs;

  if (::GetModuleFileName(StepDLL.hModule, outName, outNameLen))
  {
    TCHAR * c = ::_tcsrchr(outName, _T('\\'));
    if (c)
    {
      *(c + 1) = _T('\0');
      ::_tcscat_s(outName, 255, inName);
      rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
      if (!rez)
      {
        *(c + 1) = _T('\0');
        ::_tcscat_s(outName, 255, _T("LOAD\\"));
        ::_tcscat_s(outName, 255, inName);
        rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
      }
    }
  }

  if (!rez)
  {
    ::ksGetFullPathFromSystemPathT(inName,         // относительный путь к файлу( без системного пути )
                                   outName,        // (результат) полный путь к файлу
                                   outNameLen,     // размер буфера
                                   sptSYSTEM_FILES // путь установленного типа см. ksSystemPath
    );

    rez = ::OpenFile(_bstr_t(outName), &ofs, OF_EXIST) != HFILE_ERROR;
  }

  return rez;
}


//------------------------------------------------------------------------------
// GetFullNameDB
//---
static int GetFullDBName(TCHAR * name, TCHAR * fName)
{
  return ::GetFullName(name, fName, _MAX_PATH);
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR LoadStr(int id)
{
  static TCHAR buf[10000];
  // Конвертировать строку в соответствии с текущим словарем
  ksConvertLangStrExT(StepDLL.hModule, id, buf, 10000);
  return buf;
}


//------------------------------------------------------------------------------
// _ConnectDB
//---
int _ConnectDB(reference db, TCHAR * name)
{
  TCHAR buf[_MAX_PATH];
  return ::GetFullDBName(name, buf) ? ::ConnectDBT(db, buf) : ::ConnectDBT(db, name);
}


//------------------------------------------------------------------------------
// Получить библиотечный шрифт
// ---
_bstr_t GetLibraryIconFont()
{
  static _bstr_t font;
  if (font.length() == 0 && newKompasAPI)
  {
    ::ksAPI7::ILibraryManagerPtr libMng(newKompasAPI->LibraryManager);
    if (libMng)
    {
      ::ksAPI7::IProceduresLibrariesPtr procLibs(libMng->ProceduresLibraries);
      if (procLibs)
      {
        ::ksAPI7::IProceduresLibraryPtr procLib(procLibs->Item[LoadStr(LIBRARYID())]);
        if (procLib)
          font = procLib->IconsFont;
      }
    }
  }
  return font;
}

//-------------------------------------------------------------------------------
// Получение файла помощи
// ---
void OpenHelp(int Id)
{
  //  TCHAR gaykaHlp[260] = _T("");
  //  if ( GetFullName( LIB_HELP, gaykaHlp, 260 ) )
  //    ksOpenHelpFileT( gaykaHlp, HELP_CONTEXT,  Id );

  if (newKompasAPI)
  {
    ::ksAPI7::ILibraryManagerPtr libMng(newKompasAPI->LibraryManager);
    if (libMng)
    {
      ::ksAPI7::IProceduresLibrariesPtr procLibs(libMng->ProceduresLibraries);
      if (procLibs)
      {
        ::ksAPI7::IProceduresLibraryPtr procLib(procLibs->Item[LoadStr(LIBRARYID())]);
        if (procLib)
          procLib->OpenHelp(Id);
      }
    }
  }
}
////////////////////////////////////////////////////////////////////////////////

