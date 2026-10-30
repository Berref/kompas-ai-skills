unit Base;
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

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
 uses  Windows,  Sysutils, LtDefine, LibTool, LibDB, LDefin2D, forms, controls,
       classes, LibHpPar, ManagerEvents, GaykaRC,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksApi7;
{$ENDIF}

type



////////////////////////////////////////////////////////////////////////////////
// Указатели на отношения к БД
// ---
SimpleBase = record
  bg       : reference;	// Указатель базы
  rg1, rg2 : reference; // Указатель отношения
end;

BaseMakroParam  = packed record
  version  : Byte;     // Версия
  drawType : smallInt; // Тип отрисовки
  flags    : Byte;     // Флаги
  {
    BOOL attr      : 1;   // Создавать объекты спецификации
    BOOL simple    : 1;   // Упрощенно
    BOOL axis      : 1;   // Рисовать ось
    BOOL dimension : 1;   // Рисовать размеры
  }

end;

// базовый класс параметров
PCPar = ^CPar;
CPar  = class ( PropertyManagerObject )
protected
  m_command   : integer;    // Номер команды
  m_refMacr   : reference;  // Референсе макро
  m_spcObject : reference;  // Референсе объекта спецификации

  // Координаты точки вставки макрообъекта
  m_x, m_y, m_angle : Double;
  // Параметры подключения к БД
  m_base      : SimpleBase;
  // Базовые параметры элемента сохраняемые в макропараметры
  m_baseParam : BaseMakroParam;

public

  constructor Create( comm     : integer; ref : reference ); // Конструктор
  procedure   Assign( other    : CPar );  virtual;           // оператор присваивания

// HOT_POINTS ##################################################################
  // Работа с Hot точками
  function GetHotPoints(  point : PHotPointDescription; index : Integer ) : LongBool; virtual; // Параметры для Hot точек
  function SetHotPoint (  point : PHotPointDescription; index : Integer ) : LongBool; virtual; // Изменение положения Hot точек
  function GetCursorText( index : Integer;          Var text  : PAnsiChar ) : LongBool; virtual; // Текст для Hot точек
  function EditComplete(  index : Integer;            success : LongBool) : LongBool; virtual; // Редактирование и вставка объекта спецификации, если он был создан
// HOT_POINTS ##################################################################

  procedure  Draw1;
  function   DrawSpcObj( group : reference ) : Boolean;      // процедура создания объекта спецификации

protected
  function    GetCParSize      : Integer;                    // возвр-ет размер структуры параметров
  function    GetSize          : Integer; virtual;                   // возвр-ет размер структуры параметров
// Свойства :
  function    GetVersion       : Integer; virtual;           // Последняя версия элемента

//  function   GetChanged        : Boolean;                    // Признак изменения параметров элемента
//  procedure  SetChanged;

  // функции для работы с BaseMakroParam
  function   GetAttr           : Boolean;                    // Признак создания атрибута
  procedure  SetAttr     ( val : Boolean );

  function   GetSimple         : Boolean;                    // Упрощенно
  procedure  SetSimple   ( val : Boolean );

  function   GetAxis           : Boolean;                    // Рисовать ось
  procedure  SetAxis     ( val : Boolean );

  function   GetDimension      : Boolean;                    // Выводить размеры
  procedure  SetDimension( val : Boolean );

//  function   GetDrawType      : smallInt;                    // Текущий вид
//  procedure  SetDrawType( tip : smallInt );

  // Параметры штриховки
  function   GetHatchAngle        : Double;   virtual;       // угол штриховки
  function   GetHatchStep         : Double;   virtual;       // шаг штриховки
  procedure  SetHatchAngle( hatch : Double ); virtual;       // угол штриховки
  procedure  SetHatchStep(  step  : Double ); virtual;       // шаг штриховки

  function   GetHatchEnable: Boolean;         virtual;       // признак раличия штриховки для текущего вида

  function   GetMassa  : Double;             virtual;        // Масса

public
  property  Size       : Integer  read GetSize;


  property  Attr       : Boolean  read GetAttr              write SetAttr;
  property  Simple     : Boolean  read GetSimple            write SetSimple;
  property  Axis       : Boolean  read GetAxis              write SetAxis;
  property  Dimension  : Boolean  read GetDimension         write SetDimension;
  property  DrawType   : SmallInt read m_baseParam.drawType write m_baseParam.drawType;
  property  Massa      : Double   read GetMassa;

  property  HatchEnable: Boolean  read GetHatchEnable;
  property  HatchAngle : Double   read GetHatchAngle        write SetHatchAngle;
  property  HatchStep  : Double   read GetHatchStep         write SetHatchStep;

protected
//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************
  // виртуальные функции для работы  с элементом
  procedure GetGroup       ;            virtual;             // создание геометрии элемента
  procedure SetParam       ;            virtual;             // сохраняет параметры эл-та в макро
  function  OpenBase       : Boolean;   virtual;             // открыть БД
  procedure CloseBase      ;            virtual;             // закрыть БД
  procedure _CloseBase( bd : reference );                    // закрыть БД
  function  AttrNumber     : Double;    virtual;             // номер атрибута
  function  IsSpcObjCreate : Boolean;   virtual;             // функция проверки подключения атрибутов или нет
  function  _EditSpcObj    : Boolean;   virtual;             // заполнение объекта СП
  function  GetPromptID    : Integer;   virtual;
//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************
public
// Менеджер свойств ##################################################################
  // События
  // prButtonClick - Нажатие кнопки.
  procedure OnButtonClick( buttonID : LongInt ); override;

  //prChangeControlValue - Изменение значения контрола
  procedure OnChangeControlValue( {var cntrl : IPropertyControl,} ctrlID : LongInt; const Val: Variant ); override;

  // puCreateOCX - Cобытие создания пользовательского контрола
  procedure  OnCreateOCX( ctrlID : LongInt; var control : IDispatch ); override;
    // Перерисовка фантома
  procedure  RedrawPhantom(); override;

//    //prControlCommand Нажатие кнопки контрола
// function OnControlCommand(var ctrl : IUncnown );  override;

//    //prButtonUpdate        - Установка состояния кнопки спецпанели.
// function OnButtonUpdate(long buttonID, long* check, BOOL* _enable);  override;
          // Инициализация параметров процесса

  // Виртуальная функция наполнения контролов элемента
  procedure ShowControls;  override;

  // Виртуальная функция вывода контрола параметров штриховки
  procedure ShowHatchControl;  override;

  // Функция установки доступности контрола штриховки
  procedure SetHatchControlEnable( enable : Boolean );

// Менеджер свойств ##################################################################
protected
  function   GetAddr          : pointer;                    // адрес начала блока данных
  procedure  DrawGroup( var gr : Reference );                // создание геометрии элемента
  procedure  DrawPosLeader;
  procedure  SetPlacement( x, y, angl : Double );
  function   EditSpcObj( _group : reference ) : reference;   // создание объекта СП
  function   GetPreviewGroup    : reference;              override;
  procedure  RedrawPreview;                               virtual;

end;

// Установка битовых флагов
procedure SetBitFlag( var flags, mask : byte; fSet : boolean );

// Процесс вставки объектов
//function  CallBackP( _dynamic : integer; phantom : pointer; info : PRequestInfo;
//                     var angl : double;  var y, x : double;  com : integer ) : integer;  pascal ;

function CallBackP( com      : integer;
                    var x, y, angl : Double;                 // Координаты курсора
                    info     : PRequestInfo;                 // Параметры запроса
                    phantom  : Pointer;                      // Фантом
                    _dynamic : Integer                      // Признак динамического процесса


                     ) : Integer; stdcall; // Номер команды

// Процесс указания линии выноски
function  LeaderCallBack( com : integer;
                          var x,y : double;
                          info : PRequestInfo;
                          phantom : pointer;
                          _dynamic : integer ) : integer;  stdcall;

procedure _MessageBoxResult;
function  LoadStr_( id: Integer ): AnsiString;
function  LoadStrW( id: Integer ): WideString;
procedure CheckDecimelPart(s : PChar; pointToComma : Byte);
function  GetFullName(  name : PAnsiChar; fName:PAnsiChar  ): integer;
function  _ConnectDB(bd : reference; name : PAnsiChar ): integer;

// procedure ConvertComponentLang( component: TComponent ); // Функция перевода компонента

implementation
  uses
    ksConstTLB;

var
  obj     : PCPar   = nil;
  rub     : Phantom;
  fRepeat : boolean = false;     // Процесс прерван но его нужно продолжить
                                 // Placement на Cursor
  oldPosLeader : reference = 0;
  posLeater    : reference = 0; // 0 - нет линии выноски, -1 - ввод новой линии выноски

//------------------------------------------------------------------------------
// Конструктор
//---
constructor CPar.Create( comm : integer; ref : reference );
begin
  m_flagMode  := false;    // признак редактирования объекта
  // Координаты точки вставки макрообъекта
  m_x         := 0;
  m_y         := 0;
  m_angle     := 0;

  m_spcObject := 0;  // Референсе объекта спецификации

  // Параметры подключения к БД
  FillChar( m_base, sizeof(m_base), 0 );
  // Базовые параметры элемента сохраняемые в макропараметры
  FillChar( m_baseParam, sizeof(m_baseParam), 0 );

  with m_baseParam do
  begin
    version  := 1;
    flags    := 0;
    drawType := ID_VIEW;
  end;
  m_refMacr            := ref;
  m_command            := comm;
  if m_refMacr <> 0 then
    GetMacroPlacement( m_refMacr, m_x, m_y, m_angle )
  else begin
  end
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetAddr: pointer;
begin
  result := Addr(m_baseParam);
end;

//------------------------------------------------------------------------------
// оператор присваивания
//---
procedure CPar.Assign( other : CPar );
begin
  m_command   := other.m_command;
  m_refMacr   := other.m_refMacr;
  m_flagMode  := other.m_flagMode;
  m_angle     := other.m_angle;
  m_baseParam := other.m_baseParam;
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetCParSize: integer;
begin
  result := SizeOf(m_baseParam);
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetSize: integer;
begin
  result := GetCParSize;
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetHatchAngle : Double;
begin
  Result := 0;
end;

//------------------------------------------------------------------------------
//
//---
procedure CPar.SetHatchAngle( hatch : Double );
begin
end;

//------------------------------------------------------------------------------
//
//---
function CPar.GetHatchStep : Double;
begin
  Result := 0;
end;

//------------------------------------------------------------------------------
//
//---
procedure CPar.SetHatchStep(  step  : Double );
begin
end;

//------------------------------------------------------------------------------
// признак раличия штриховки для текущего вида
//---
function CPar.GetHatchEnable: Boolean;
begin
  Result := DrawType = ID_SEC;
end;

//------------------------------------------------------------------------------
// Установить флаг в битовой комбинации
//---
procedure SetBitFlag( var flags, mask : byte; fSet : boolean );
begin
  if fSet then
    flags := flags or mask
  else
    flags := flags or mask xor mask;
end;

//------------------------------------------------------------------------------
// Упрощенное
//---
procedure CPar.SetSimple( val : Boolean );
begin
  SetBitFlag( m_baseParam.flags, BF_SIMPLE, val );
end;

//------------------------------------------------------------------------------
// Упрощенное
//---
function CPar.GetSimple : Boolean;
begin
  Result := ( m_baseParam.flags and BF_SIMPLE ) <> 0;
end;

//------------------------------------------------------------------------------
// Адрес
//---
function  CPar.GetAttr : Boolean;
begin
  Result := ( m_baseParam.flags and BF_ATTR ) <> 0;
end;

//------------------------------------------------------------------------------
// Признак созданя атрибутов
//---
procedure CPar.SetAttr( val : boolean );
begin
  SetBitFlag( m_baseParam.flags, BF_ATTR, val );
end;

//------------------------------------------------------------------------------
// Оси
//---
function CPar.GetAxis : boolean;
begin
  Result := ( m_baseParam.flags and BF_AXIS ) <> 0;
end;

//------------------------------------------------------------------------------
// Оси
//---
procedure CPar.SetAxis( val : boolean );
begin
  SetBitFlag( m_baseParam.flags, BF_AXIS, val );
end;

//------------------------------------------------------------------------------
// Размеры
//---
function CPar.GetDimension : boolean;
begin
  Result := ( m_baseParam.flags and BF_DIMENSION ) <> 0;
end;

//------------------------------------------------------------------------------
// Размеры
//---
procedure CPar.SetDimension( val : boolean);
begin
  SetBitFlag( m_baseParam.flags, BF_DIMENSION, val );
end;

//------------------------------------------------------------------------------
// Масса
//---
function CPar.GetMassa : Double;
begin
  Result := 0;
end;
{
//------------------------------------------------------------------------------
//
//---
function  CPar.GetDrawType: smallInt;
begin
  GetDrawType := m_baseParam.drawType;
end;

//------------------------------------------------------------------------------
//
//---
procedure  CPar.SetDrawType( tip : smallInt );
begin
  m_baseParam.drawType := tip;
end;
}

//------------------------------------------------------------------------------
// Редактирование объекта спецификации
//---
function CPar.EditSpcObj( _group : reference ) : reference;
var
  massaTmp : Double;
  buf      : AnsiString;

begin
  m_spcObject := 0;
  if m_flagMode then begin
    m_spcObject := ksGetSpcObjForGeomWithLimit( nil,              // имя библиотеки типов
                                                0,                // номер типа спецификации
                                                _group,
                                                0,                // 1 - присланная геометрия идентична геометрии объекта СП; 0- входит в объект СП
                                                1,                // 1 -первый объект 0- следующий объект
                                                STANDART_SECTION, // GetElementSpcSection // номер раздела
                                                AttrNumber
                                              );
    if not Attr then begin
      Result := 0;
      Exit;
    end;

    if ( ( m_spcObject <> 0 ) and ( ksSpcObjectEdit(m_spcObject) = 0 ) ) then // включение режима редактирования
      m_spcObject := 0;

  end;

  // создание спецификации
  if ( m_spcObject or
       ksSpcObjectCreate( nil,                               // имя библиотеки типов
                          0,                                 // номер типа спецификации
                          STANDART_SECTION,
                          0,                                 // GetElementSpcSection //  номер раздела и подраздела
                          AttrNumber,
                          0) <> 0 ) then begin                // тип атрибута

    _EditSpcObj();                                           // заполним объект СП

    massaTmp := Massa;

    if massaTmp > 1e-5 then  begin
      buf := Format( '%g', [Massa] );
      ksSpcMassa(    PAnsiChar(buf)    );                          // масса детали
    end;

    if _group <> 0 then                                      // подключим геометрию
      ksSpcIncludeReference( _group, 1 );

    m_spcObject := ksSpcObjectEnd();                         // завершить процесс редактирования
  end;
  Result := m_spcObject;
end;

//------------------------------------------------------------------------------
// Процесс вставки и редактирования элемента
//---
procedure CPar.Draw1;
var
  j    : integer;         // Признак продолжения процесса
  info : RequestInfo;     // Параметры процесса
begin
  j               := 1;
  // Пераметры фантома
  FillChar( rub, sizeof(rub), 0 );
  rub.type1.scale := 1;              // Масштаб
  rub.phType      := 1;              // Тип - группа

  if ( ReturnResult = 0 ) then       // Признак ошибки
  begin
    m_flagMode := EditMacroMode > 0; // - Режиm режим редактирования макрообъекта
    obj := Addr(self);               // Указатель на себя
    if OpenBase then                 // Открытие БД
    begin
      // Инициализация параметров процесса
      if ( InitProcessParam( m_command + 4000,  m_command + 4000, pnEnterEscHelp ) ) then
      begin
        while ( j<>0 ) do
        begin
          fRepeat := false;
          DrawGroup( rub.type1.gr );                        // нарисовать элемент
          rub.type1.ang := m_angle;                         // угол поворота элемента

          // Параметры процесса
          FillChar(info, sizeof(info), 0 );
          info.commands := PAnsiChar( GetPromptID() );          // подсказка
          info._dynamic := 1;                               // 1 - динамический процесс
          info.callBack := Addr(CallBackP);                 // функция обратной связи

          // процесс вставки элемента
          j := PlacementEx( Addr(info), m_x, m_y, m_angle, Addr(rub), PIUnknown(procParam) );

          // редактирование объекта спецификации
          if Attr and ( m_spcObject <> 0 ) then begin
            if ksEditWindowSpcObject( m_spcObject ) <> 0 then
              DrawPosLeader();                 // Создание линии выноски
            m_spcObject := 0;
          end;

          if m_flagMode then
            j := 0
          else
            if fRepeat then begin         // Если процесс продолжается то
              j := 1;
              DrawGroup( rub.type1.gr );  // Рисуем новую группу
            end;
        end;
      end;
      EndProcess;                         // Завершение процесса
      CloseBase();                        // закрыть БД
    end;
  end;
end;

//------------------------------------------------------------------------------
// Функция обратной связи для редактирования элемента
//---
//function CallBackP( _dynamic : Integer;                      // Признак динамического процесса
//                    phantom  : Pointer;                      // Фантом
//                    info     : PRequestInfo;                 // Параметры запроса
//                    var angl, y, x : Double;                 // Координаты курсора
//                    com      : integer ) : Integer; pascal ; // Номер команды

function CallBackP( com      : integer;
                    var x, y, angl : Double;                 // Координаты курсора
                    info     : PRequestInfo;                 // Параметры запроса
                    phantom  : Pointer;                      // Фантом
                    _dynamic : Integer                      // Признак динамического процесса
                  ) : Integer; stdcall; // Номер команды
var
  rub : PPhantom;
begin

  rub := PPhantom (phantom);
  if( _dynamic = 0 ) then                               // Фиксация
  begin
    case ( com ) of
      -1 : begin                                        // Поставить в модель
//        obj^.angle := angl;
        obj^.SetParam();                                // Сохранение параметров
        obj^.SetPlacement( x, y, angl );                // Установка
        StoreTmpGroup( rub^.type1.gr );                 // Сохранение группы
        fRepeat := obj^.DrawSpcObj( rub^.type1.gr );
        ClearGroup( rub^.type1.gr );                    // Удаление группы
        if ( fRepeat or obj^.m_flagMode ) then          // Создание объекта спецификации
        begin
          result  := 0;                                 // Требуется прервать процесс
          exit;
        end;
      end;
    end;

    obj^.DrawGroup ( rub^.type1.gr );                   // Перерисовка группы
  end;
//  else begin
//    obj^.angle := angl;
//    obj^.RedrawPahtom;
//  end;
  result := 1;
end;

//------------------------------------------------------------------------------
// Отрисовка группы
//---
procedure CPar.DrawGroup( var gr : reference );
begin
  if ExistObj(gr) <> 0 then  // Если группа уже существует
    DeleteObj(gr);           // Удаляем её

  gr := NewGroup( 1{временный тип группы} ); // Создаём новую группу
    m_refMacr := 0;
    Macro(0);

    GetGroup;                                // геометрия эл-та
    m_refMacr := EndObj();

  EndGroup();                                // Запомнить группу
  _MessageBoxResult();
  changed := false;
end;

//------------------------------------------------------------------------------
// Перерисовать фантом, слайд, вывести новые параметры
//---
procedure CPar.RedrawPhantom;
var
  gr : reference;
begin
  if Changed then
  begin
    DrawGroup( rub.type1.gr );
    ksChangeObjectInLibRequest( nil, Addr(rub) );

    // Перезаполняем грид
    if paramGrid <> nil then
    begin
      rowIndex := 1;                   // Начнем с первой строчки
      ShowParam();                     // Выводим параметры
      paramGrid.RowCount := rowIndex;  // Устанавливаем новое количество строк
      paramGrid.UpdateParam();         // Перерисовка грида
    end;

    // Перерисовываем группу в окне
    if slideBox <> nil then
    begin
      // Удаляем старую группу
      gr := LongInt( slideBox.DrawingSlide );
      if gr <> 0 then
        DeleteObj( gr );
      // Рисуем новую
      gr := GetPreviewGroup();
      slideBox.DrawingSlide := gr;
      slideBox.UpdateParam;      // Перерисовываем
    end
  end
end;


//------------------------------------------------------------------------------
// Процесс указания линии выноски
//---
function LeaderCallBack ( com : integer;
                          var x,y : double;
                          info : PRequestInfo;
                          phantom : pointer;
                          _dynamic : integer) : integer;  stdcall;
var
  newPosLeater : reference;
begin
  if ( posLeater <> -1 ) then begin

    // Ищем объект в текущих координатах курсора
    newPosLeater := FindObj( x, y, ksGetCursorLimit ); // Величина стороны окошка-ловушки с центром x,y
    // Если объект найден проверяем - является ли он линией выноски
    if ( newPosLeater <> 0) and ( GetObjParam(newPosLeater, nil, 0, ALLPARAM) <> POSLEADER_OBJ )  then
      newPosLeater := 0;                        // Найденный объект не линия выноски

    if _dynamic = 0 then                       //  Фиксация
    begin
      if newPosLeater = 0 then
        Error( PAnsiChar(LoadStr_(ID_ERROR_LEADER)) )       // Сообщение о ошибке
      else begin                                // Если линия выноски найдена
        posLeater := newPosLeater;              // Запоминаем уазатель на линию выноски

        if oldPosLeader <> 0 then
          LightObj( oldPosLeader, 0 );          // Убрать подсветку со старой линии выноски

        Result := 0;                            // Остановить процесс
        Exit;
      end

    end
    else begin
      // Если нашли новую линию выноски
      if newPosLeater <> oldPosLeader then begin
        if oldPosLeader <> 0 then
          LightObj( oldPosLeader, 0 );          // Убираем подсветку со старой линии выноски

        oldPosLeader := newPosLeater;

        if oldPosLeader <> 0 then
          LightObj( oldPosLeader, 1 );          // Подсвечиваем новую линию связи
      end
    end;
  end;
  result := 1;
end;

//-------------------------------------------------------------------------------
// Отрисовать позиционную линию выноски
// Функцию нужно запускать вне Cursor и Placement
// ---
procedure CPar.DrawPosLeader;
var
  info : RequestInfo;
  x, y : Double;
  comm : Integer;
begin
  oldPosLeader := 0;
  posLeater    := 0;

  if IsSpcObjCreate and InitPosLeaderParam then
  begin
    FillChar( info, sizeof(info), 0 );
    info.prompt   := PAnsiChar(ID_INDICATE_LEADER);
    info._dynamic := 1;
    info.callBack := Addr(LeaderCallBack);          // функция обратной связи
    comm := ksCursorEx( Addr(info), x, y, nil, PIUnknown(posLiaderParam) );
    if ( comm <> 0 ) and ( oldPosLeader > 0 ) then
      LightObj( oldPosLeader, 0 );          // Снятие подсветки с объекта если нажали отмену (Esc)
  end;

  if posLeater < 0 then
    posLeater := ksCreateViewObject( POSLEADER_OBJ );

  // Линия выноски есть, подключим ее к объекту спецификации
  if posLeater > 0 then
  begin
    // Ввойдем в режим редактирования объекта спецификации
    if ksSpcObjectEdit( m_spcObject ) <> 0 then
    begin
      // Подключим линию выноски
      ksSpcIncludeReference( posLeater, 1 );
      // Закроем объект спецификации
      ksSpcObjectEnd();
    end
  end;
  posLeater := 0;
end;

//-------------------------------------------------------------------------------------
// Группа просмотра
//---
function CPar.GetPreviewGroup: Reference;
begin
  Result := NewGroup( 1 ); // Создаём новую группу
    GetGroup();
  EndGroup();            // Запомнить группу
end;

//------------------------------------------------------------------------------
// Установка точки привязки
// ---
procedure CPar.SetPlacement( x, y, angl : Double );
begin
  if m_refMacr <> 0 then
    SetMacroPlacement( m_refMacr, x, y, angl, 0 );
end;

//------------------------------------------------------------------------------
// Создание объекта спецификации
//---
function CPar.DrawSpcObj( group : reference  ): boolean;
begin
  m_spcObject := 0;
  if Attr and IsSpcObjCreate then
  begin
    if ReturnResult = etError10 then    //  10  "Ошибка! Вырожденный объект"
      ResultNULL();

    m_spcObject := EditSpcObj( group );
  end;
  result := m_spcObject <> 0;
end;

// HOT_POINTS ##################################################################
// Работа с Hot точками

//------------------------------------------------------------------------------
// Параметры для Hot точек
//---
function CPar.GetHotPoints( point : PHotPointDescription; index : integer ) : LongBool;
begin
  Result := false;
end;

//------------------------------------------------------------------------------
// Изменение положения и угла поворота
//---
function CPar.SetHotPoint( point : PHotPointDescription; index : integer ) : LongBool;
var
  ang : Double;
begin
  case index of
    0 : SetPlacement( point^.x, point^.y, 0.0 ); // Хотточка перемещения
    1 : // Хотточка перемещения
      begin
        ang := Angle( 0, 0, point^.x, point^.y );
        SetPlacement( 0, 0, ang );
      end;
  end;
  Result := index < 2;
end;

//------------------------------------------------------------------------------
// Текст для Hot точек
//---
function CPar.GetCursorText( index : Integer; var text : PAnsiChar ) : LongBool;
begin
  Result := false;
end;

//------------------------------------------------------------------------------
// Редактирование и вставка объекта спецификации, если он был создан
//---
function CPar.EditComplete( index : Integer; success : LongBool ) : LongBool;
begin
  Result := true;
end;

//------------------------------------------------------------------------------
// Версия
//---
function CPar.GetVersion : Integer;
begin
  result := 1;
end;

// HOT_POINTS ##################################################################

//------------------------------------------------------------------------------
// открыть БД
//---
function CPar.OpenBase : Boolean;
begin
  Result := false;
end;

//------------------------------------------------------------------------------
// закрыть БД
//---
procedure CPar._CloseBase( bd : reference );
begin
  DeleteDB( bd );
end;

//------------------------------------------------------------------------------
// закрыть БД
//---
procedure CPar.CloseBase;
begin
  if m_base.bg <> 0 then
    _CloseBase( m_base.bg );
end;

//------------------------------------------------------------------------------
// номер атрибута
//---
function CPar.AttrNumber : Double;
begin
  Result := 0;
end;

//------------------------------------------------------------------------------
// функция проверки подключения атрибутов или нет
//---
function CPar.IsSpcObjCreate : Boolean;
begin
  Result := false;
end;

//------------------------------------------------------------------------------
// заполнение объекта СП
//---
function CPar._EditSpcObj : Boolean;
begin
  Result := true;
end;

//------------------------------------------------------------------------------
// заполнение объекта СП
//---
function CPar.GetPromptID: Integer;
begin
  Result := 0;
end;

//------------------------------------------------------------------------------
// заполнение объекта СП
//---
procedure CPar.RedrawPreview;
begin
end;

// Менеджер свойств ############################################################
//-------------------------------------------------------------------------------
// Наполнить панель контролами
// ---
procedure CPar.ShowControls;
var
  checkBox : IPropertyCheckBox;
begin
  if IsSpcObjCreate then
  begin
    checkBox := CreateCheckBox( Attr ) As IPropertyCheckBox;
    if checkBox <> nil then
      InitPropertyControl( IPropertyControl(checkBox), IDP_SPC_OBJ, IDS_SPC_OBJ_TIPS, IDS_SPC_OBJ_TIPS, ksNameAlwaysVisible, true, true );
  end
end;


procedure CPar.ShowHatchControl;
begin
  if IsHatchObject then
  begin
//    CreateTab( IDP_HATCH_PAGE );
//    CreateSeparator( 0, ksSeparatorDownName );

    CreateUserControl( IDP_HATCH_PARAM, 100, 150 );
//    CreateRealEdit( IDP_HATCHANG_ANGLE, HatchAngle, -360, 360, HatchEnable );
//    CreateRealEdit( IDP_HATCHANG_STEP, HatchStep, 0.01, 100, HatchEnable );
  end
end;

procedure CPar.SetHatchControlEnable( enable : Boolean );
begin
  if hatchCtrl <> nil then
  begin
//    SetControlEnable( IDP_HATCH_PARAM,  enable );
    hatchCtrl.Enable := enable;
  end
end;

//-------------------------------------------------------------------------------
// Инициализация параметров ActiveX Control-a
// ---
procedure CPar.OnCreateOCX( ctrlID : LongInt; var control : IDispatch );
begin
  if ctrlID = IDP_HATCH_PARAM then
  begin
    hatchCtrl := control As _DVCHatch;
    if hatchCtrl <> nil then
    begin
      hatchCtrl.Angle := HatchAngle;
      hatchCtrl.Step  := HatchStep;
      SetHatchControlEnable( HatchEnable );
    end;
  end;
end;

procedure CPar.OnChangeControlValue( {var cntrl : IPropertyControl;} ctrlID : LongInt; const val : VARIANT );
begin
  case ctrlID of
{
   case IDP_HATCHANG_ANGLE:
      SetHatchAngle( newVal.dblVal );
      changed = true;
      break;
    case IDP_HATCHANG_STEP:
      SetHatchStep( newVal.dblVal );
      changed = true;
      break;
}

    IDP_SPC_OBJ:
      Attr :=  not Attr;

  end;
end;

//----------------------------------------------------------------------------------------------------
// создание геометрии элемента
// ---
procedure CPar.GetGroup;
begin
end;

//----------------------------------------------------------------------------------------------------
// сохраняет параметры эл-та в макро
// ---
procedure CPar.SetParam;
begin
end;

//----------------------------------------------------------------------------------------------------
// Обработка нажатия кнопок
// ---
procedure CPar.OnButtonClick( buttonID : LongInt );
var
  oldSec : Boolean;
begin
  oldSec := HatchEnable; // Изменен тип отображения
  case buttonID of
    // Отображение
    ID_VIEW,     // Вид
    ID_LEFT,     // Cбоку
    ID_TOP,      // Cверху
    ID_SEC:      // Вид/разрез
      begin
        DrawType := buttonID;
        Changed  := true;
      end;

    ID_SIMPLE: // Упрощенно
      begin
        Simple  := not Simple;
        Changed := true;
      end;

    ID_AXIS: // Рисовать ось
      begin
        Axis     :=  not Axis;
        Changed  := true;
      end;

    ID_LEADER_CREATE: // Создать новую линию выноски
      begin
        if newKompasAPI <> nil then
        begin
          newKompasAPI.StopCurrentProcess( TRUE, nil );
          posLeater := -1;
        end;
      end;
  end;

  if Changed then
  begin
    // Если переключили тип отрисовки на штриховку
    if oldSec <> HatchEnable then
    begin
      SetHatchControlEnable( HatchEnable );
//      SetControlEnable( IDP_HATCHANG_ANGLE,  m_baseParam.drawType == ID_SEC );
//      SetControlEnable( IDP_HATCHANG_STEP,   m_baseParam.drawType == ID_SEC );
    end;
  end;

end;


// Менеджер свойств ############################################################

//------------------------------------------------------------------------------
// Вывод сообщений о ошибках
//---
procedure _MessageBoxResult;
begin
  if ( ReturnResult<>0 ) then
  begin
    if ( ReturnResult = etError10 ) then   //  10  "Ошибка! Вырожденный объект"
      ResultNULL()
    else
      MessageBoxResult();
  end;
end;

//--------------------------------------------------------------------------
// отбросить дробную часть у строки если после "." нули
// "123.000" -> "123";   "123.10" -> "123.1"
// pointToComma =1 заменить '.' на ','
//--------------------------------------------------------------------------
procedure CheckDecimelPart(s : PChar; pointToComma : Byte);
var
  pos  : integer;
  flag : boolean;
  i    : integer;
    //--------------------------------------------------------------------------
    function strchr ( s: PCHar; c : char ) : integer;
    var
      i   : integer;
    begin
      for i:=0 to strlen( s )-1 do
      begin
        if ( s[i] = c ) then
        begin
          result := i;
          exit;
        end;
      end;
      result := -1;
    end;
    //--------------------------------------------------------------------------
begin
  if( s<>nil) And (strlen(s)<>0 ) then
  begin
    pos := strchr( s, '.');
    flag := false;
    if ( pos<>-1 ) then
    begin
      i:=pos;
      inc(i);
      while( s[i] <> '0') And (flag=false ) do
      begin
        if ( s[i] <> '0' ) then
          flag := true;
        inc(i);
      end;
      if( flag=false )then
        s[pos] := char(0)
      else
      begin
        i :=  strlen(s)-1;
        while( s[i]='0' ) do
        begin
          s[i] := char(0);
          dec(i);
        end;
        if ( pointToComma<>0 ) then
          s[pos] := ',';
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Получить полное имя файла
//---
function GetFullName( name : PAnsiChar;  fName : PAnsiChar ): integer;
type
OFSTRUCT = record
   cBytes : byte;
   fFixedDisk:byte;
   nErrCode: word;
   Reserved1:word;
   Reserved2:word;
   szPathName: array [0..255] of AnsiChar;
end;

var
  //pos : integer;
  ofs : TOFSTRUCT;
  c   : PAnsiChar;
begin
  if( GetModuleFileNameA( HInstance, fName, 255)<>0 ) then
  begin
    c := strrscan( fName, '\');
    if ( c<>nil ) then
    begin
      StrCopy( c+1, '');
      strcat ( fName, name );
      if ( OpenFile(fName , ofs, OF_EXIST) <> HFILE_ERROR )then
      begin
        result:= 1;
        exit;
      end
      else begin
        StrCopy( c+1, '');
        strcat ( fName, 'LOAD\' );
        strcat ( fName, name );
        if ( OpenFile(fName , ofs, OF_EXIST) <> HFILE_ERROR )then
        begin
          result:= 1;
          exit;
        end;
      end;
    end;
  end;
  result := 0;
end;

//------------------------------------------------------------------------------
//
//---
function _ConnectDB(bd : reference; name: PAnsiChar ): integer;
var
  buf : array[0..255] of AnsiChar;
begin
  if ( GetFullName( name, buf  )=1 ) then
    result := ConnectDB( bd, buf )
  else
    result := ConnectDB( bd, name );
end;

//------------------------------------------------------------------------------
//
//---
function _GetMacroParam( value : pointer;  size : cardinal ): integer;
begin
  result := GetMacroParam( 0, value, size);
end;

{
//------------------------------------------------------------------------------
// функция перевода формы
//---
procedure ConvertLangForm( form : TForm );

var
  I: Integer;

  procedure ConvertLangControl( opControl : TOpenControl );
    var
    buf     : array[0..MAX_TEXT_LENGTH] of Char; //имя фонта
  begin
    if ( ksConvertLangStr( PChar(opControl.caption), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.caption := buf;
    if ( ksConvertLangStr( PChar(opControl.hint), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.hint := buf;
    if ( ksConvertLangStr( PChar(opControl.text), buf, MAX_TEXT_LENGTH ) <> 0  ) Then
      opControl.text := buf;
  end;

begin
  for I:= 0 to form.ControlCount -1 do
  begin
    if ( form.Components[I] is TControl ) then
      ConvertLangControl( TOpenControl(form.Components[I] as TControl) );
  end;
  //переводим радиогруппы и др оконные контролы
  ksConvertLangWindow( form.Handle );
end;
}

//------------------------------------------------------------------------------
// Функция перевода строки ресурса
//-
function LoadStr_( id: Integer ): AnsiString;
var
  bufRes: array[0..MAX_TEXT_LENGTH] of AnsiChar;
begin
  ksConvertLangStrEx( hInstance, id, bufRes, MAX_TEXT_LENGTH );
  result := bufRes;
end;

//------------------------------------------------------------------------------
// Функция перевода строки ресурса
//-
function LoadStrW( id: Integer ): WideString;
var
  bufRes: array[0..MAX_TEXT_LENGTH] of WideChar;
begin
  ksConvertLangStrExW( hInstance, id, bufRes, MAX_TEXT_LENGTH );
  result := bufRes;
end;

{
//------------------------------------------------------------------------------
// Функция перевода компонента
//-
procedure ConvertComponentLang( component: TComponent );
var
  control: TControl;
  buf: array[0..MAX_TEXT_LENGTH] of AnsiChar;
  i: Integer;

begin
  if component <> nil then
  begin
    if component is TControl then
    begin
      control := component as TControl;

      if ksConvertLangStr( PChar(control.Hint), buf, SizeOf(buf)) <> 0 then
        control.Hint := buf;

      control.GetTextBuf( buf, SizeOf(buf) );

      if ksConvertLangStr(buf, buf, SizeOf(buf)) <> 0 then
        control.SetTextBuf( buf );
    end;

    if component.ComponentCount > 0 then
      for i := 0 to component.ComponentCount - 1 do
        ConvertComponentLang( component.Components[i] );
  end;
end;
}


end.


