////////////////////////////////////////////////////////////////////////////////
//
// Orifice.cpp - класс Отверстие
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Orifice.h"
#include <PArray.h>
#include <SafeArrayUtils.h>

extern ksAPI7::IApplicationPtr appl;
extern HINSTANCE g_hInstance;

//-------------------------------------------------------------------------------
// Структура параметров макрообъекта
// ---
struct MacroPar 
{
  double diam;
};


//-------------------------------------------------------------------------------
// Подсветить грани
// ---
void SelectFaces(ksAPI7::IModelObjectPtr face1, ksAPI7::IModelObjectPtr face2 )
{

  ksAPI7::IKompasDocument3DPtr doc3D(appl->ActiveDocument);
  if ( doc3D )
  {
    ksAPI7::IChooseManagerPtr chMng(doc3D->ChooseManager);
    if ( chMng )
    {
      chMng->UnchooseAll();

      chMng->Choose((LPDISPATCH) face1 );
      chMng->Choose((LPDISPATCH) face2 );
    }  
  } 
}


//-------------------------------------------------------------------------------
// Подсветить грани
// ---
void UnSelectAll()
{
  ksAPI7::IKompasDocument3DPtr doc3D(appl->ActiveDocument);

  if (doc3D)
  {
    // Получаем указатель на менеджер выбора
    ksAPI7::IChooseManagerPtr ChoiseManager(doc3D->ChooseManager);
    if (ChoiseManager)
      ChoiseManager->UnchooseAll();
  }
}


//-------------------------------------------------------------------------------
// Конструктор
// ---
Orifice::Orifice( bool forProp )
  : m_refCount ( 0 )
  , m_diameter ( 5 )
  , m_face1    ( 0 )
  , m_face2    ( 0 )

{
  IDocument3DPtr doc( ksGetActive3dDocument(), false );
  if ( doc )
  {
    IEntityPtr editMacro(doc->GetEditMacroObject(), false);
    m_macroObject = ksAPI7::IMacroObject3DPtr( IUnknownPtr(ksTransferInterface(editMacro, ksAPI7Dual, 0 ) ));
    if ( (bool)m_macroObject && m_macroObject->Valid) 
    {
      GetUserData();
      if ( !forProp )
      {
        if ( m_face1 || m_face2 )
        {
          if ( (bool)m_face1 && !m_face1->Valid )
            m_face1 = NULL;
          if ( (bool)m_face2 && !m_face2->Valid )
            m_face2 = NULL;

          SelectFaces( m_face1, m_face2 );
        }
      }
    }
  }  
}  


//-------------------------------------------------------------------------------
// Установить первую грань
// ---
void Orifice::SetFace1(ksAPI7::IModelObjectPtr  face )
{
  m_face1 = face;
}


//-------------------------------------------------------------------------------
// Установить вторую грань
// ---
void Orifice::SetFace2(ksAPI7::IModelObjectPtr face )
{
  m_face2 = face;
}

//-------------------------------------------------------------------------------
// Получить первую грань
// ---
ksAPI7::IModelObjectPtr Orifice::GetFace1()
{
  return m_face1;
}


//-------------------------------------------------------------------------------
// Получить вторую грань
// ---
ksAPI7::IModelObjectPtr Orifice::GetFace2()
{
  return m_face2;
}


//-------------------------------------------------------------------------------
//
// ---
_bstr_t GetFeatureName(ksAPI7::IModelObjectPtr entity)
{
  _bstr_t name(_T(""));

  if (entity && entity->ModelObjectType == o3d_face)
  {
    name = _T("Грань.");
    ksAPI7::IFeature7Ptr Owner(entity->Owner);
    if (Owner)
      name += Owner->Name;
  }
  return name;
}


//----------------------------------------------------------------------------------------------
//ksPlacementChanged     Изменение положения.
// ---
int Orifice::PlacementChanged(LPDISPATCH object)
{
  int res = 0;
  ksAPI7::IModelObjectPtr ModelObject(object);
  ksAPI7::IKompasDocument3DPtr doc3D(appl->ActiveDocument);

  if ((bool)doc3D && ModelObject && ModelObject->ModelObjectType == o3d_face)
  {
    // Получаем указатель на менеджер выбора
    // Записываем имя выбранной грани в Edit
    int index = m_objectIndex;

    ksAPI7::IPropertyControlPtr edit = GetPropertyControl(index ? ID_FACE2 : ID_FACE1);
    if (edit)
    {
      ksAPI7::IPropertyEditPtr PropEdit(edit);
      edit->Value = GetFeatureName(ModelObject);
      PropEdit->WithCheck = TRUE;
      PropEdit->CheckState = ksCheckCurrent;
      // Грань 2
      if (index == 1)
      {
        // Текущее поле вода активно
        PropEdit->CheckState = ksCheckCurrent;

        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE1));
        // Предыдущее поле ввода неактивно
        PropertyEditAnother->CheckState = ksCheckUndefined;

        SetFace2(ModelObject);
        if (ModelObject == GetFace1())
          SetFace1(nullptr);
      }
      // Грань 1
      else if ( index == 0 )
      {
        // Текущее поле вода неактивно
        PropEdit->CheckState = ksCheckUndefined;

        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE2));
        // Следующее поле ввода активно
        PropertyEditAnother->CheckState = ksCheckCurrent;

        SetFace1(ModelObject);
        m_objectIndex = 1;
        if (ModelObject == GetFace2())
          SetFace2(nullptr);
      }
      res = 1;
    }
    SelectFaces(GetFace1(), GetFace2());
  }
  return res;
}


//---------------------------------------------------------------
// ksFilterProc    -Фильтрация объектов
// ---
BOOL Orifice::FilterProc(LPDISPATCH object)
{
  ksAPI7::IModelObjectPtr ModelObject(object);
  return TRUE; // ModelObject && ModelObject->ModelObjectType == o3d_face;
}


//----------------------------------------------------------------------------------------------
// Наполнение контролов элемента
// ---
void Orifice::ShowControls()
{
  // Создаем Edit для ввода диаметра
  ksAPI7::IPropertyControlPtr  diameter(CreateControl(ksControlSpinReal));

  if (diameter)
  {
    InitPropertyControl(diameter, ID_DIAMETER, ID_DIAMETER, ID_DIAMETER, TRUE, ksNameAlwaysVisible, TRUE);
    diameter->Value = m_diameter;
  }

  CreateSeparator(ksSeparatorDownName);

  // Грань 1
  ksAPI7::IPropertyEditPtr edit(m_curentCollection->Add(ksControlEditCheckBox));
  ksAPI7::IPropertyEditCheckBoxPtr editCheckBox(edit);
  ksAPI7::IPropertyControl1Ptr Control(edit);

  if ( edit )
  {
    InitPropertyControl( edit, ID_FACE1, ID_FACE1, ID_FACE1, TRUE, ksNameNoVisible );
    edit->ReadOnly = FALSE;
    edit->WithCheck = TRUE;
    // Установка значения по умолчанию 
    editCheckBox->DefaultValue = _bstr_t(LoadStr(IDP_DEFAULTNAME));
    editCheckBox->EnableDeleteValue = TRUE;
    // Поле ввода активно
    edit->CheckState = ksCheckCurrent;
    Control->HyperLinkNameStyle = TRUE;
    ksAPI7::IModelObjectPtr face1(GetFace1());

    if (face1)
      edit->Value = GetFeatureName(face1);

  }
  CreateSeparator(ksSeparatorDownName);

  // Грань 2
  edit = m_curentCollection->Add(ksControlEditCheckBox);
  editCheckBox = edit;
  Control = edit;

  if ( edit )
  {
    InitPropertyControl( edit, ID_FACE2, ID_FACE2, ID_FACE2, TRUE, ksNameNoVisible );
    edit->ReadOnly = FALSE;
    edit->WithCheck = TRUE;
    // Установка значения по умолчанию 
    editCheckBox->DefaultValue = _bstr_t(LoadStr(IDP_DEFAULTNAME));
    editCheckBox->EnableDeleteValue = TRUE;
    // Поле ввода неактивно
    edit->CheckState =ksCheckUndefined;
    Control->HyperLinkNameStyle = TRUE;
    ksAPI7::IModelObjectPtr face2(GetFace2());

    if (face2)
      edit->Value = GetFeatureName(face2);
  }
}


//----------------------------------------------------------------------------------------------
// Получение типа контекстного меню
// ---
BOOL Orifice::GetContextMenuType(long LX, long LY, long * ContextMenuType)
{
  if ( ContextMenuType )
    *ContextMenuType = ksProcessContextPanel;
  return TRUE;
}


//----------------------------------------------------------------------------------------------
// Накачка контекстной панели параметрами
// ---
BOOL Orifice::FillContextPanel(LPDISPATCH ContextPanel)
{
  ksAPI7::IProcessContextPanelPtr Panel(ContextPanel);
  if ( Panel )
  {
    ksAPI7::IPropertyEditPtr diameter(GetPropertyControl(ID_DIAMETER));
    if ( diameter )
      Panel->AddControl(diameter);
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
// Выбор грани
// ---
void Orifice::ChoiceFaces()
{
  // Получаем указатель на активный документ
  ksAPI7::IKompasDocument3D1Ptr doc3D(appl->ActiveDocument);

  if ( doc3D )
  {
    ksAPI7::IProcessPtr process(doc3D->LibProcess[ksProcess3DPlacementAndEntity]);
    m_process3D = process;
    if (m_process3D)
    {
      process->ProcessParam = m_procParam;
      new Process3DEvent(m_process3D, *this);
      process->Run(false, false);
    }
  }
}


//-----------------------------------------------------------------------------
// prControlCommand Нажатие кнопки контрола
// ---
BOOL Orifice::ControlCommand(LPDISPATCH ctrl, long buttonID)
{
  ksAPI7::IPropertyEditPtr PropertyEdit(ctrl);
  switch (buttonID)
  {
    case 0:
    {
      ksAPI7::IPropertyControlPtr Control(PropertyEdit);
    
      if (Control->Id == ID_FACE1)
      {
        PropertyEdit->CheckState = ksCheckCurrent;
        m_objectIndex = 0;
        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE2));
        PropertyEditAnother->CheckState = ksCheckUndefined;
      }
      else
      {
        PropertyEdit->CheckState = ksCheckCurrent;
        m_objectIndex = 1;
        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE1));
        PropertyEditAnother->CheckState = ksCheckUndefined;
      }
      break;
    }
    // Нажатие на "крестик"
    case ksListItemDelete:
    {
      ksAPI7::IPropertyEditPtr PropertyEdit(ctrl);
      ksAPI7::IPropertyEditCheckBoxPtr Checkbox(PropertyEdit);
      ksAPI7::IPropertyControlPtr Control(PropertyEdit);

      if (int index = m_objectIndex == 1)
      {
        PropertyEdit->CheckState = ksCheckCurrent;
        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE1));
        PropertyEditAnother->CheckState = ksCheckUndefined;
        SetFace2(nullptr);
      }
      else
      {
        PropertyEdit->CheckState = ksCheckCurrent;
        ksAPI7::IPropertyEditPtr PropertyEditAnother(GetPropertyControl(ID_FACE2));
        PropertyEditAnother->CheckState = ksCheckUndefined;
        SetFace1(nullptr);
      }
      SelectFaces(GetFace1(), GetFace2());
      break;
    }
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
//prChangeControlValue - Изменение значения контрола
// ---
bool Orifice::OnChangeControlValue(long ctrlID, const VARIANT & newVal)
{
  bool res = false;
  switch (ctrlID)
  {
    case ID_DIAMETER: m_diameter = newVal.dblVal; res = true; break;
  }
  return res;
}


//----------------------------------------------------------------------------------------------
// Завершение процесса
// ---
void Orifice::EndProcess()
{
  // Скрываем панель
  UnSelectAll();
  PropertyManagerObject::EndProcess();
}

BOOL Orifice::ProcessRun()
{
  if ( m_process3D )
  {
    ksAPI7::IPropertyControlPtr diameter( GetPropertyControl(ID_DIAMETER) );
    if ( diameter )
    {
      ksAPI7::IProcessWithVariablesPtr varProc( m_process3D );
      if ( varProc )
      {
        if ( m_varName.length() > 0 )
          varProc->SetControlExpression( diameter, m_varName, GetVariableExpression() );
        else
          varProc->SetControlExpression( diameter, _T("newTempLen"), _bstr_t(m_diameter) );
      }
    }
  }
  return TRUE;
}

_bstr_t Orifice::GetVariableExpression()
{
  _bstr_t res;
  ksAPI7::IFeature7Ptr macroFeature( m_macroObject );
  if (  macroFeature )
  {
    _variant_t SubFeatures = macroFeature->GetSubFeatures( ksOperTree, true, true );
    PArray< ksAPI7::IModelObjectPtr> objects;
    FillObjects( SubFeatures, objects );

    if ( objects.Count() >= 2 )
    {
      // Получаем объект дерева посторения
      ksAPI7::ISketchPtr    sketch( *objects[0] );
      ksAPI7::IFeature7Ptr sketchFeat( sketch );
      if ( sketchFeat )
      {
        ksAPI7::IVariable7Ptr var( sketchFeat->GetVariable( false, false, (LPCTSTR)m_varName ) );
        if ( var )
          res = var->Expression;
      }
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// prChangeControlValue - Событие изменения значения контрола 
// ---
BOOL Orifice::ButtonClick( long buttonID )
{
  BOOL res = TRUE;
  // Создаем панель
  if ( buttonID == pbEnter )
  {
    res = FALSE;
    ksAPI7::IModelObjectPtr face1 = GetFace1();
    ksAPI7::IModelObjectPtr face2 = GetFace2();
    if (face1 && face2 && face1 != face2)
    {
      Create(false);
      res = TRUE;
    }
  }

  // Завершаем процесс
  if (buttonID == pbHelp)
  {
    CommandHelp(0);
  }
  return res;
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
BOOL Orifice::ButtonUpdate(long buttonID, long * check,
                           VARIANT_BOOL * enable)
{
  if ( buttonID == pbEnter && enable )
  {
    ksAPI7::IModelObjectPtr face1 = GetFace1();
    ksAPI7::IModelObjectPtr face2 = GetFace2();
    *enable = face1 && face2 && face1 != face2;
  }
  return TRUE;
}


//-------------------------------------------------------------------------------
// Запись параметров макрообъекта в хранилище
// ---
void Orifice::SetUserData()
{
  if ( !(bool)m_params )
  {
    ksAPI7::IKompasDocument3DPtr doc = appl->ActiveDocument;
    if ( doc )
    {
      ksAPI7::IUserDataStoragesMngPtr storageMng = doc->UserDataStoragesMng;
      if ( storageMng )
      {
        if ( m_macroObject )
        {
          ksAPI7::IPropertyKeeperPtr propertyKeeper( m_macroObject->Parent );
          if ( propertyKeeper )
          {
            ksAPI7::IUserDataStoragesMngPtr storageMng1 = propertyKeeper->GetUserDataStoragesManager( TRUE );
            if ( storageMng1 )
              storageMng = storageMng1;
            if ( storageMng )
            {
              ksAPI7::IUserDataStoragesPtr storages = storageMng->Add( m_macroObject );
              if ( storages )
              {
                ksAPI7::IUserDataStoragePtr macroPars = storages->Add( _bstr_t(LoadStr(IDS_CAPTION)) );
                if ( macroPars )
                {
                  m_params = macroPars;
                }
              }
            }
          }
        }  
      }
    }
  }

  if ( m_params )
  {
    m_params->Clear( _bstr_t("") );
    m_params->AddObject( _bstr_t(""), m_diameter, _bstr_t(LoadStr(ID_DIAMETER)) );
 
    if ( m_face1 )
    {  
      _variant_t f1 = (IDispatch*)m_face1;
      m_params->AddObject( _bstr_t(""), f1, _bstr_t(LoadStr(ID_FACE1)) );
    }
 
    if ( m_face2 )
    {  
      _variant_t f2 = (IDispatch*)m_face2;
      m_params->AddObject( _bstr_t(""), f2, _bstr_t(LoadStr(ID_FACE2)) );
    }
    m_params->AddObject( _bstr_t(""), m_varName, _bstr_t(LoadStr(ID_VARIABLE_NAME)) );
  }
}


//-------------------------------------------------------------------------------
// Получить параметры макрообъекта из хранилища
// ---
void Orifice::GetUserData()
{
  ksAPI7::IKompasDocument3DPtr doc = appl->ActiveDocument;
  if ( doc )
  {
    ksAPI7::IUserDataStoragesMngPtr storageMng = doc->UserDataStoragesMng;
    if ( storageMng )
    {
      if ( m_macroObject )
      {
        ksAPI7::IPropertyKeeperPtr propertyKeeper( m_macroObject->Parent );
        if ( propertyKeeper )
        {
          ksAPI7::IUserDataStoragesMngPtr storageMng1 = propertyKeeper->GetUserDataStoragesManager( TRUE );
          if ( storageMng1 )
            storageMng = storageMng1;

          if ( storageMng )
          {
            ksAPI7::IUserDataStoragesPtr storages = storageMng->GetItem( (LPDISPATCH)m_macroObject );
            if ( storages )
            {
              ksAPI7::IUserDataStoragePtr macroPars = storages->GetItem( _bstr_t(LoadStr(IDS_CAPTION)) );
              if ( macroPars )
              {
                long numb;
                {
                  _variant_t obj;
                  macroPars->GetObject( _bstr_t(LoadStr(ID_DIAMETER)), &obj, &numb );
                  m_diameter = (double)obj;
                  macroPars->GetObject( _bstr_t(LoadStr(ID_FACE1)), &obj, &numb );
                  if ( obj.vt == VT_DISPATCH )
                    m_face1 = (LPDISPATCH)obj;
                }
                {
                  _variant_t obj1;
                  macroPars->GetObject( _bstr_t(LoadStr(ID_FACE2)), &obj1, &numb );
                  if ( obj1.vt == VT_DISPATCH )
                    m_face2 = (LPDISPATCH)obj1;
                }
                {
                  _variant_t obj2;
                  macroPars->GetObject( _bstr_t(LoadStr(ID_VARIABLE_NAME)), &obj2, &numb );
                  m_varName = obj2;
                }
                m_params = macroPars;
              }
            }
          }
        }
      }
    }
  }
}

#define KS_MAXDOUBLE (1.0E+300) // 1.7976931348623158E+308


//-------------------------------------------------------------------------------
// Удалить все объекты из текущего эскиза
// ---
void ClearCurrentSketch()
{  
  reference gr = NewGroup( 1 );
  EndGroup();
  SelectGroup( gr, 3, -KS_MAXDOUBLE, -KS_MAXDOUBLE, KS_MAXDOUBLE, KS_MAXDOUBLE );
  DeleteObj( gr );
}


//-------------------------------------------------------------------------------
// Создать макрообъект - отверстие
// ---
void Orifice::Create( bool forProp )
{
  m_objectIndex = -1;

  //Получаем диаметр отверстия
  double rad = m_diameter * 0.5;
  //Грани должны быть указаны
  if ((bool)m_face1 && (bool)m_face2)
  {
    //Получаем интерфейс активного 3D документа
    ksAPI7::IKompasDocument3DPtr doc3D( appl->ActiveDocument );
    if ( doc3D )
    {
      // Если нет макрообъекта, создаем
      if (!(bool)m_macroObject)
      {
        //Получаем интерфейс детали
        ksAPI7::IPart7Ptr part(doc3D->TopPart);
        if (part)
        {
          //Создаем эскиз
          ksAPI7::IModelContainerPtr Container(part);
          ksAPI7::ISketchsPtr Sketchs(Container->Sketchs);
          //Получаем интерфейс нового эскиза
          ksAPI7::ISketchPtr sketch(Sketchs->Add());
          if ( sketch )
          {
            //Базовая плоскость - одна из указанных граней
            sketch->Plane = m_face1;
            //Угол поворота эскиза
            sketch->Angle = 0;
            //Эскиз создан
            sketch->Update();
            //Редактируем эскиз
            if (sketch->BeginEdit())
            {
              //Создаем в эскизе окружность
              reference  c = Circle(0, 0, rad, 1/*тип линии - основная*/);
              m_varName = CreateVariable(c);
              sketch->EndEdit();
            }
            ksAPI7::IFeature7Ptr sketchFeat( sketch );
            ksAPI7::IProcessWithVariablesPtr varProc( m_process3D );
            if ( sketchFeat && varProc )
            {
              if ( varProc )
              {
                ksAPI7::IPropertyControlPtr diameter( GetPropertyControl( ID_DIAMETER ) );
                ksAPI7::IVariable7Ptr var( sketchFeat->GetVariable( false, false, (LPCTSTR)m_varName ) );
                if ( diameter && var )
                {
                  _bstr_t expression = varProc->GetControlExpression( diameter );
                  if ( expression.length() )
                    var->Expression = expression;
                }
              }
            }
            //Создаем операцию вырезания выдавливанием
            ksAPI7::IExtrusionsPtr Extrusions(Container->Extrusions);
            ksAPI7::IExtrusionPtr cutExtrusion(Extrusions->Add(o3d_cutExtrusion));
            if ( cutExtrusion )
            {
              int resCreate = 0;
              //Получаем интерфейс параметров вырезанного элемента выдавливания 
                            //Направление выдавливания - прямое
              cutExtrusion->Direction = dtNormal;
              //Устанавливаем эскиз
              cutExtrusion->Sketch = sketch;

              cutExtrusion->SetSideParameters(TRUE, etUpToSurfaceTo, 0, 0, FALSE, m_face2);

              //Операция вырезания выдавливанием создана
              resCreate = cutExtrusion->Update();

              //Если операция создана
              if (resCreate)
              {
                //Создаем макрообъект
                ksAPI7::IMacroObjects3DPtr MacroObjects3D(Container->MacroObjects3D);
                m_macroObject = MacroObjects3D->Add();
                if ( m_macroObject )
                {
                  //Макрообъект создан
                  m_macroObject->Update();
                  //Получаем интерфейс параметров макрообъекта

                  if ( m_macroObject )
                  {
                    //Устанавливаем видимость объекта
                    m_macroObject->StaffVisible = FALSE;
                    //Добавляем в макро вырезанный элемент выдавливания
                    PArray< ksAPI7::IModelObjectPtr> objects;
                    objects.Add(new ksAPI7::IModelObjectPtr(sketch));
                    objects.Add(new ksAPI7::IModelObjectPtr(cutExtrusion));
                    _variant_t Objects(CreateDispSafeArray(objects));

                    m_macroObject->Objects = Objects;

                    MacroPar pars;
                    pars.diam = m_diameter;
                    TCHAR buf[255];
                    GetModuleFileName(g_hInstance, buf, sizeof(buf));

                    ksAPI7::IUserParametersPtr userParam(m_macroObject);
                    userParam->Command = 1;
                    userParam->LibraryName = _bstr_t(LoadStr(IDR_LIBID));
                    userParam->LibraryFileName = buf;

                    _variant_t params;
                    GetMacroParamToSAFEARRAY(&pars, sizeof(pars), params);

                    userParam->UserParams = params;
                    // macroObject->DoubleClickEditable = TRUE; // Запретить редактирование библиотекой
                    m_macroObject->PropertyObjectEditable = true;
                  }
                  m_macroObject->Update();
                  // Записываем параметры макрообъекта в хранилище
                  SetUserData();
                }
              }
            }
          }
        }
      }
      // Если редактируем макрообъект
      else
      {
        ksAPI7::IPart7Ptr part( m_macroObject->Parent );
        if (part)
        {
          // Получаем интерфейс параметров макрообъекта
          ksAPI7::IFeature7Ptr macroFeature( m_macroObject );
          _variant_t SubFeatures = macroFeature->GetSubFeatures(ksOperTree, true, true);
          PArray< ksAPI7::IModelObjectPtr> objects;
          FillObjects(SubFeatures, objects);

          if (objects.Count() >= 2)
          {
            // Получаем объект дерева посторения
            ksAPI7::ISketchPtr    sketch(*objects[0]);
            ksAPI7::IExtrusionPtr cutExtrusion(*objects[1]);

            if (sketch)
            {
              sketch->Plane = m_face1;
              sketch->Update();
              //Создаем в эскизе окружность
              if (!UpdateVariable(sketch))
              {
                if (sketch->BeginEdit())
                {
                  ClearCurrentSketch();
                  reference c = Circle(0, 0, rad, 1/*тип линии - основная*/);
                  m_varName = CreateVariable(c);
                  sketch->EndEdit();
                }
              }
              ksAPI7::IFeature7Ptr sketchFeat( sketch );
              ksAPI7::IProcessWithVariablesPtr varProc( m_process3D );
              if ( sketchFeat && varProc )
              {
                if ( varProc )
                {
                  ksAPI7::IPropertyControlPtr diameter( GetPropertyControl( ID_DIAMETER ) );
                  ksAPI7::IVariable7Ptr var( sketchFeat->GetVariable( false, false, (LPCTSTR)m_varName ) );
                  if ( diameter && var )
                  {
                    _bstr_t expression = varProc->GetControlExpression( diameter );
                    if ( expression.length() )
                      var->Expression = expression;
                  }
                }
              }

              // Устанавливаем глубину выдавливания
              cutExtrusion->Direction = dtNormal;
              cutExtrusion->SetSideParameters(TRUE, etUpToSurfaceTo, 0, 0, FALSE, m_face2);

              cutExtrusion->Update();


            }
          }
          // Обновляем макрообъект
          m_macroObject->Update();
          SetUserData();
          doc3D->RebuildDocument();
        }
      }
    }
  }
}



//-----------------------------------------------------------------------------
//
// ---
_bstr_t Orifice::CreateVariable( reference c )
{
  _bstr_t res;
  if ( c )
  {
    CircleParam par;
    GetObjParam( c, &par, sizeof(par), ALLPARAM_T );
//    IDrawingObjectPtr obj( IUnknownPtr(ksTransferReference(c, activeDoc->Reference), false/*addref*/) ); 

    RDimParam parRDim; // Структура параметров диаметрального и обычного радиального размера
    memset( &parRDim, 0, sizeof( parRDim ) );
    parRDim.dPar.pt1      = 1;   // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
    parRDim.dPar.pt2      = 1;   // Тип стрелки у второй выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )

    // Параметры изображения размера
    parRDim.tPar.sign    = 1; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
    // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
 
    parRDim.tPar.bitFlag = _AUTONOMINAL; 
  
    // Привязка диаметрального размера
    parRDim.sPar.xc  = par.xc;  // Координаты центра
    parRDim.sPar.yc  = par.yc; 
    parRDim.sPar.rad = par.rad; // Радиус
    
    // Создание диаметрального размера
    reference rDiamDimension = DiamDimension( &parRDim );

  ksAPI7::IKompasDocument2DPtr activeDoc( appl->ActiveDocument );
     
    if ( activeDoc )
    {
      // Получаем интерфейс объекта API7 по его reference
    ksAPI7::IDrawingObject1Ptr obj( IUnknownPtr(ksTransferReference(rDiamDimension, activeDoc->Reference), false/*addref*/) );
      if ( obj )
      {
        obj->Associate(); 
    ksAPI7::IParametriticConstraintPtr constraint( obj->NewConstraint() );
        if ( constraint )
        {
          constraint->ConstraintType = ksCFixedDim;
          constraint->Comment        = _bstr_t( "Фиксированный размер" );
          
          constraint->Create();
        }  
        constraint = obj->NewConstraint();
        if ( constraint )
        {
          constraint->ConstraintType = ksCDimWithVariable;
          constraint->Comment        = _bstr_t( "Диаметр" );
          
          BOOL r = constraint->Create();
          if ( r )
            res = constraint->Variable;
        }  
      }
    }                         
  } 
  return res;
}


//-----------------------------------------------------------------------------
//
// ---
bool Orifice::UpdateVariable( ksAPI7::IModelObjectPtr sketch )
{
  bool res = false;

  ksAPI7::IFeature7Ptr sketchFeat( sketch );
  if ( sketchFeat )
  {
    ksAPI7::IVariable7Ptr var(sketchFeat->GetVariable( false, false, (LPCTSTR)m_varName) );
    if ( var )
    {
      var->Value = m_diameter;
      res = true;
    }
  }
  return res;
}


// ILibPropertyObject
//-----------------------------------------------------------------------------
// Имя группы объектов по умолчанию макроэлементы
// ---
LPOLESTR _IFUNC Orifice::GetGroupName()
{
  CString res(_T("Отверстия"));
  return res.AllocSysString();
}


//-----------------------------------------------------------------------------
// Добавить свойство в список свойств
// ---
BOOL _IFUNC Orifice::GetProperty( int index, PropertyParam * param )
{
  if ( param )
  {
    param->propertyId = GetPropertyID ( index );
    param->propertyInstance = g_hInstance;
    switch ( param->propertyId )
    {
      case IDS_CAPTION: 
      {
        param->propertyType = ksOPControlGroup;      // Группа
        param->enable = true;
        break;
      }
      case ID_DIAMETER:
      {
        param->propertyType = ksOPControlEditDouble;
        param->enable = true;
        break;
      }
    }
  }
  return param && param->propertyId;
}


//-----------------------------------------------------------------------------
// Обновить параметры свойства
// ---
BOOL _IFUNC Orifice::UpdateProperty( PropertyParam * param )
{
  BOOL res = FALSE;
  if ( param )
  {
    switch ( param->propertyId )
    {
      case ID_DIAMETER:
      {
        param->propertyValue.dblVal = m_diameter;
        res = TRUE;
        break;
      }
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// Изменить свойство
// ---
int _IFUNC Orifice::ApplyProperty( PropertyParam * param )
{
  BOOL res = FALSE;
  if ( param )
  {
    switch ( param->propertyId )
    {
      case ID_DIAMETER:
      {
        m_diameter = param->propertyValue.dblVal;
        Create( true );
        break;
      }
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// Выдать идентификатор свойства по индексу
// ---
int Orifice::GetPropertyID ( int index )
{
  int res = 0;
  switch ( index )
  {
    case 0 : res = IDS_CAPTION; break;
    case 1 : res = ID_DIAMETER; break;
  }
  return res;
}


//------------------------------------------------------------------------------
// AddRef
// ---
unsigned long _IFUNC Orifice::AddRef() 
{
  m_refCount++;
  return m_refCount;
}

//------------------------------------------------------------------------------
// Release
// ---
unsigned long _IFUNC Orifice::Release() 
{
  if ( m_refCount ) 
    m_refCount--;
  if( !m_refCount )
  {
    delete this;
    return 0;
  }
  return m_refCount;
}

//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC Orifice::QueryInterface( const GUID far& iid, void far*far* iface )
{
  if ( iid == IID_IUnknown || iid == IID_ILibraryObject )
  {
    *iface = static_cast<ILibraryObject*>(this);
    AddRef();
    return S_OK;
  }
  if ( iid == IID_ILibPropertyObject ) 
  {
    *iface = static_cast<ILibPropertyObject*>(this);
    AddRef();
    return S_OK;
  }

  *iface = NULL;
  return E_NOINTERFACE;
}


//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC Orifice::LtQueryInterface( int idType, void far*far* iface )
{
  if ( idType == idd_ILibPropertyObject3D ) 
  {
    *iface = static_cast<ILibPropertyObject*>(this);
    AddRef();
    return S_OK;
  }

  *iface = NULL;
  return E_NOINTERFACE;
}


//-------------------------------------------------------------------------------
// Создает соответствующий объект для работы с Hot точками
// ---
void WINAPI LibObjInterfaceEntry( int idType, unsigned int comm, void** object ) 
{
  if ( object ) 
  {
    if ( comm == 1 && idType == idd_ILibPropertyObject3D ) { // Если не Hot точки обнулить
      Orifice * obj = new Orifice( true );
      obj->LtQueryInterface( idType, object );
    }
  }
}  
