#ifndef __CPAR_H
#define __CPAR_H
////////////////////////////////////////////////////////////////////////////////
//
// CPar.h
// <CPar.cpp>
//
// CPar           - Базовый класс элемента
// SimpleBase     - Параметры соединения с базой данных
// BaseMacroParam - Основные параметры элемента
// 
////////////////////////////////////////////////////////////////////////////////
#include "resource.h"

#include "cPropMen.h"
#include "SArray.h"

#define LIB_HELP           _T("Gayka.chm")      // файл помощи
#define LIB_LAT            _T("Spc.lat")        // файл атрибутов
#define LIB_VER            02                   // версия библиотеки

#define _SHOW_ERRORS         // флаг - показывать сообщения об ошибках

//название колонок для спецификации
#define SPC_FORMAT         1 // формат
#define SPC_ZONA           2 // зона
#define SPC_POSITION       3 // позиция
#define SPC_MARKER         4 // обозначение
#define SPC_NAME           5 // наименование
#define SPC_COUNT          6 // количество
#define SPC_NOTE           7 // примечание

#define BASE_LINE          1 // тип основной линии
#define SLIM_LINE          2 // тонкая линия
#define AXIS_LINE          3 // тип осевой линии
#define SHTRIH_LINE        4 // тип штриховой линии
#define AXIS_END           3 // величина выступания осевой линии за габарит тела
#define BREAK_LINE        11 // тип линии обрыва

// параметы штриховки
#define MIN_H_ANG         -360             // минимальный угол
#define MAX_H_ANG          360             // максимальный угол
#define MIN_H_STEP         0.01            // минимальный шаг
#define MAX_H_STEP         100             // максимальный шаг
#define MAX_COUNT_SPCOBJ   4               // максимальное число объектов СП за раз

#define EPSILON            0.001           // погрешность при сравнении с нулем типа float
#define STANDART_SECTION   25              // Номер раздела и подраздела спецификации

#define SPCOBJ_CREATE  true                // признак подключения объекта к спецификации
#define COUNT_MASSA        1000   // количество элементов для которых задана масса
#define WORKWINDOWCOLOR    -1 // признак назначенности цвета рабочего окна
#define MODSTEP_REAL       0.5412765877 

typedef unsigned char uint8;

struct RequestInfo;
struct HotPointDescription;
struct HotPointDescription1;
struct PropertyParam;



////////////////////////////////////////////////////////////////////////////////
// Указатели на отношения к БД
// ---
struct SimpleBase
{
  reference bg;        // Указатель базы
  reference rg1, rg2; // Указатель отношения
  SimpleBase() { ::memset(&bg, 0, sizeof(SimpleBase)); }
};

////////////////////////////////////////////////////////////////////////////////
// Базовые параметры объекта
///
struct BaseMacroParam {
  BYTE version;                // Версия элемента
  union {
    struct {
      uint8 flagAttr : 1;      //0x01 создать объект СП
      uint8 flagAxis : 1;      //0x02 рисовать ось
      uint8 flagSimp : 1;      //0x04 упрощенное изображение
    } flags;
    uint8 bitVector;
  };

  short          drawType;     // тип отображения
  BaseMacroParam();
  BaseMacroParam(BaseMacroParam & other);
};

////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс элемента
//
////////////////////////////////////////////////////////////////////////////////
class CPar : public PropertyManagerObject {

  ksAPI7::IProcessPtr        process;
  ksAPI7::IProcess2DPtr      m_process2D;
  ksAPI7::IDrawingGroupPtr   m_phantomGroup;
  ksAPI7::ISpecificationBaseObjectsPtr m_spcBaseObjects;

protected:
  ksAPI7::IProcessPtr        leaderProcess;
  ksAPI7::IProcessParamPtr   posLiaderParam;   // Параметры процесса указания линии выноски

  unsigned int      command = 0;  // Номер команды
  reference         spcObject = 0;  // Референсе объекта спецификации
  reference         refMacr = 0;  // Референсе макро
  reference         oldPosLeader = 0;
  reference         posLeater = 0;

  reference           m_editMode = 0;  // Признак редактирования по дабл-клику

  // Признак редактирования по дабл-клику
  int  IsEditMode() { return m_editMode; }

  enum class ProcessState
  {
    processPlacement,
    processSelectLeader,
    processCreateLeader,
  };

  ProcessState processState = ProcessState::processPlacement;  // Признак запуска процесса Placement

  bool              changed;  // Признак изменения параметров
  bool         fromDataBase;  // Признак создания объета для работы внешней базы данных

  // Координаты точки вставки макрообъекта
  double         x;
  double         y;
  double         angle;
  // Параметры подключения к БД
  SimpleBase     base;
  // Обязательно последний параметр т. к. начиная с него пишем область памяти в макро параметры
  BaseMacroParam m_baseParam;

public:

  // Конструкторы 
  CPar(unsigned int command, reference ref = 0, bool fromDataBase = false);
  CPar(CPar & other);
  virtual   CPar & DublicateObj() = 0;

  void SetEdit(reference A) { m_editMode = A; }
  // Отрисовка фантома
  void DrawPhantom(double x, double y, double angle, BOOL dynamic);
  // Редактирование объекта спецификации
  void EditSpcObject();
  // Завершить процесс редактирования
  virtual BOOL EndProcess();
  virtual void UnadviseEvents();
  // Создать группу параметров штриховки
  virtual void CreatePropertyGroup() override;

  // ksPlacementChanged    -Изменено положения объекта
  BOOL PlacementChanged(double x, double y, double angle, BOOL dynamic);
  // Запуск процесса выбора линии-выноски
  int LeaderCall();
  // Поиск линии-выноски
  int PosLeater(double x, double y, BOOL dynamic);

  bool Changed() { return changed; }  // Признак изменения параметров
  void SetChange() { changed = true; }  // Признак изменения параметров
  bool DrawSpcObj(reference _group);  // Создание объектов спецификации

  virtual  int  GetCommand() { return command; } // Номер команды


  void      SetFromDataBase(bool set) { fromDataBase = set; }
  // Основные общие параметры элементов
// BaseMacroParam&     GetBaseParam() { return m_baseParam; }

//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************
  // виртуальные функции для работы  с элементом
  virtual  void  GetGroup() = 0;                        // создание геометрии элемента
  virtual  void  SetParam();                            // сохраняет параметры эл-та в макро
  void  RedrawMacro();
  virtual  int   Size() { return sizeof(m_baseParam); } // возвр-ет размер структуры параметров
  virtual  bool  IsSpcObjCreate() { return true; }     // функция проверки подключения атрибутов или нет
  virtual  bool  _EditSpcObj(ksAPI7::ISpecificationBaseObjectPtr & obj1) { return true; }         // заполнение объекта СП
  virtual  bool  OpenBase() = 0; //{ return false; }  // открыть БД
  virtual  void  CloseBase();//  = 0; //{}                 // закрыть БД
  void  CloseBase(reference bd);
  // позволяет использовать аттрибут уже существующего объекта СП - возвращает номер
  // команды элемента для которого этот объект СП определён в CfgDlg
  virtual  long  GetPromptID() { return 0; }   // возвр-ет идентификатор строки подсказки в процессе постановки объектов
  virtual  bool  IsSpcGostSection() { return true; }   // Объект создается в разделе стандартизованных изделий
  // вызывается после изменения типа отображения через меню во время процесса постановки в модель
  virtual  double AttrNumber() { return 0; }

  // Все длля задания параметров штриховки
  // функции вызываемые в процессе постановки эл-та в документ и при его редактировании
  virtual  double    HatchAngle() { return 0; }             // угол штриховки  
  virtual  double    HatchStep() { return 0; }             // шаг штриховки  
  virtual  void      SetHatchAngle(double hatch) {}       // угол штриховки
  virtual  void      SetHatchStep(double step) {}       // шаг штриховки
  // (для панели инструментов)
  // Если штриховка в одном из режимов есть то нужно вернуть true  

  // true - в текущем режиме штриховка есть
  virtual  bool      HatchEnable() { return m_baseParam.drawType == ID_SEC; }
  // Установка доступности контрола
  void      SetHatchControlVisible(bool visible);
  // Функции для вывода контрола параметров штриховки        
  virtual  void      ShowHatchControl();
  // Установить видимость контрола
  void SetControlVisible(int ctrlId, bool visible);
  // Инициализация параметров процесса указания позиционной линии выноски
  /*virtual*/ bool InitPosLeaderParam();

  //******************************************************************************

  // HOT_POINTS ##################################################################
    // Работа с Hot точками
    /* ILibHPObject */
  virtual bool GetHotPoints(HotPointDescription * point, int index) { return false; } // Параметры для Hot точек
  virtual bool SetHotPoint(HotPointDescription * point, int index);                  // Изменение положения Hot точек
  virtual bool GetCursorText(int index, char ** text) { return false; } // Текст для Hot точек
  virtual bool Prepare() { return false; }
  virtual bool ExecuteCommand(int id) { return true; } // Выполнение команды
  virtual bool EditComplete(int index, BOOL success) { return true; } // Редактирование и вставка объекта спецификации, если он был создан
  virtual int  GetMenu(int index = -1) { return 0; }     // Меню
  virtual bool ChangeHotPointParam(double d) { return true; };// Параметры для Hot точек

  /* ILibHPObject1 */
  virtual bool     GetHotPointsEx(HotPointDescription1 * point, int index) { return false; } // Параметры для Hot точек
  // КВН K10   virtual bool GetViewData     ( HotPointDescription1 * point, int index ) { return false; };
  virtual LPOLESTR GetCursorTextEx(int index) { return NULL; }  // Текст для Hot точек
  virtual bool     UpdateCommand(int id) { return true; } // Установить состояния команд из меню, присланного по LibHotPnt_GetMenu() или LibHotPnt_GetMenuEx
  virtual bool     SelectHotPoint(int index) { return false; }
  virtual bool     UnselectHotPoint(int index) { return false; }
  // HOT_POINTS ##################################################################

  // Менеджер свойств ##################################################################
    // События     
    // prButtonClick - Нажатие кнопки.
  virtual bool OnButtonClick(long buttonID);

  virtual bool IsButtonEnable(long buttonID) { return true; } // Нажата ли кнопка
  virtual bool IsButtonChecked(long buttonID); // Нажата ли кнопка

  //prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT & newVal);

  // Перерисовка фантома
  virtual void RedrawPhantom();

  //    //prControlCommand Нажатие кнопки контрола
  //  virtual bool OnControlCommand(LPUNKNOWN  ctrl);

  //    //prButtonUpdate        - Установка состояния кнопки спецпанели.
  //  virtual bool OnButtonUpdate(long buttonID, long* check, BOOL* _enable);
            // Инициализация параметров процесса 

    // Виртуальная функция наполнения контролов элемента
  virtual void       ShowControls();
  // Менеджер свойств ##################################################################
  // Окно свойств     ##################################################################
    // Добавить свойство в список свойств
  virtual BOOL     GetProperty(int index, PropertyParam & param);
  // Обновить параметры свойства
  virtual BOOL     UpdateProperty(PropertyParam & param);
  // Изменить свойойство
  virtual int      ApplyProperty(PropertyParam & param);
  virtual int      GetPropertyID(int  index);
  virtual LPOLESTR GetGroupName() { return NULL; }
  virtual LPCTSTR  GetObjName() { return NULL; }

  void PlacementProcess();



  // Окно свойств     ##################################################################

  void      Assign(const CPar & other);   // оператор присваивания
  operator void * () { return &m_baseParam.version; } // оператор приведения по умолчанию к  void*

  void      DrawGroup(reference & gr);     // создание геометрии элемента
  void      Draw1();                        // процесс создания эл-та

  static   void      _MessageBoxResult();
  reference          EditSpcObj(reference _group); // заполнение объекта СП
  // Изменение положения объекта  
  void               SetPlacement(double x, double y, double angle);
  void               DrawPosLeader();
  virtual int        GetVersion() { return 1; }      // Версия
  // Установка параметров  
  virtual int        _GetMacroParam(void * value, unsigned int size);
  virtual reference  GetPreviewGroup();
  virtual void       RedrawPreview() {}
  virtual void       AssignRef(reference ref);  // Копирование параметров из reference другой гайки
  // Получить парметры для элемента XML дерева
  virtual void       GetXMLPartFamilyParam(CString & name, CString & id) = 0;
};

////////////////////////////////////////////////////////////////////////////////
// Прочее
//
bool GetFullName(TCHAR * inName, TCHAR * outName, int outNameLen);
int  _ConnectDB(reference db, TCHAR * name);

// отбросить дробную часть у строки если после "." нули
// "123.000" -> "123";   "123.10" -> "123.1"
// pointToComma =1 заменить '.' на ','
void CheckDecimelPart(TCHAR * s, unsigned int pointToComma);

extern CPar * NewCParObject(int command, reference ref, bool fromDataBase = false);


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR LoadStr(int id);
void   GetNewKompasAPI();

// Получить библиотечный шрифт
_bstr_t GetLibraryIconFont();
void OpenHelp(int Id);

extern AFX_EXTENSION_MODULE StepDLL;
#endif
