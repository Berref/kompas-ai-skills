////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения обозначений СПДС
//
////////////////////////////////////////////////////////////////////////////////
unit Step2_API7_2D_1;

interface
uses
  Sysutils, LDefin2D, ksAuto, Libtool, Windows;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LoadStr( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;
  procedure  CreateLineDimension;
  procedure  LineDimensionNavigation;
  procedure  EditLineDimension;
  procedure  RadialDimensionWork;
  procedure  DiametralDimensionWork;
  procedure  AngleDimensionWork;
  procedure  ArcDimensionWork;
  procedure  BreakLineDimensionWork;
  procedure  BreakRadialDimensionWork;
  procedure  BreakAngleDimensionWork;
  procedure  HeightDimensionWork;

implementation

uses
  LtDefine,
  ksApi7,
  ksConstTLB,
  forms;

const
  IDS_NODOC       = 200;
  IDS_COORDS      = 201;
  IDS_DIM         = 202;
  IDS_COMMAND1    = 203;
  IDS_NOTDIM      = 204;
  IDS_COMMAND2    = 205;
  IDS_NOOBJ       = 206;
  IDS_NOTCREATE1  = 207;
  IDS_UNIT        = 208;
  IDS_EDIT        = 209;
  IDS_NOTCREATE2  = 210;
  IDS_COMMAND3    = 211;
  IDS_COMMAND4    = 212;
  IDS_NOOBJS      = 213;
  IDS_NOTCREATE3  = 214;
  IDS_COMMAND5    = 215;
  IDS_COMMAND6    = 216;
  IDS_NOTCREATE4  = 217;
  IDS_UNIT2       = 218;
  IDS_COMMAND7    = 219;
  IDS_NOTCREATE5  = 220;
  IDS_NOMINAL     = 221;
  IDS_COMMAND8    = 222;
  IDS_COMMAND9    = 223;
  IDS_COMMAND10   = 224;

var
  newKompasAPI : IApplication;                                // Компас Application 7
  doc : IKompasDocument2D;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;


//-------------------------------------------------------------------------------
// Получить текущий документ
// ---
function GetCurrentDocument : IKompasDocument2D;

var
  kDoc : IKompasDocument;
begin
  Result := nil;

  if ( newKompasAPI <> nil ) then
     // Получить активный документ
     kDoc := newKompasAPI.ActiveDocument;
  Result := kDoc As IKompasDocument2D;
end;


//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;

var
  mes : WideString;
begin
  Application.Handle := GetHWindow;
  GetNewKompasAPI;
  doc := GetCurrentDocument;

  if ( doc <> nil ) then
  begin
    case command of
      1   : CreateLineDimension;
      2   : LineDimensionNavigation;
      3   : EditLineDimension;
      4   : RadialDimensionWork;
      5   : DiametralDimensionWork;
      6   : AngleDimensionWork;
      7   : ArcDimensionWork;
      8   : BreakLineDimensionWork;
      9   : BreakRadialDimensionWork;
      10  : BreakAngleDimensionWork;
      11  : HeightDimensionWork;
    end;
    newKompasAPI := nil;
  end
  else
  begin
    mes := LoadStr( IDS_NODOC );
    ksMessageW( PWideChar(mes) );
  end;
end;


//-------------------------------------------------------------------------------
//  Получить контейнер обозначений 2D
// ---
function GetSymbols2DContainer : ISymbols2DContainer;

var
  viewsMng  : IViewsAndLayersManager;
  views     : IViews;
  view      : IView;
begin
  Result := nil;

  if ( doc <> nil ) then
  begin
    // Получить менеджер для работы с видами и слоями
    viewsMng := doc.ViewsAndLayersManager;

    if ( viewsMng <> nil ) then
    begin
      // Получить коллекцию видов
      views := viewsMng.Views;

      if ( views <> nil ) then
      begin
        // Получить активный вид
        view := views.ActiveView;
        // Получить контейнер
        Result := view As ISymbols2DContainer;
      end;
    end
  end
end;


//-------------------------------------------------------------------------------
// Создать линейный размер
// ---
procedure CreateLineDimension;

var
  symbCont  : ISymbols2DContainer;
  dimCol    : ILineDimensions;
  newDim    : ILineDimension;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию линейных размеров
    dimCol := symbCont.LineDimensions;

    if ( dimCol <> nil ) then
    begin
      // Добавить объект в коллекцию
      newDim := dimCol.Add;

      if ( newDim <> nil ) then
      begin
        // Координаты первой точки привязки размера
        newDim.X1 := 50;
        newDim.Y1 := 150;
        // Координаты второй точки привязки размера
        newDim.X2 := 100;
        newDim.Y2 := 150;
        // Положение размерной линии
        newDim.X3 := 75;
        newDim.Y3 := 180;
        // Тип ориентации линейного размера
        newDim.Orientation := ksLinDHorizontal;
        // Применить параметры
        newDim.Update;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линейного размера
// ---
procedure GetLineDimensionParam( dim : ILineDimension );

var
  x1, y1, x2, y2  : double;
  mes             : WideString;
begin
  if ( dim <> nil ) then
  begin
    // Координаты первой точки привязки размера
    x1 := dim.X1;
    y1 := dim.Y2;
    // Координаты второй точки привязки размера
    x2 := dim.X2;
    y2 := dim.Y2;
    // Выдать сообщение с параметрами объекта
    mes := LoadStr( IDS_COORDS ) + #13#10 + 'X1 = ' + FormatFloat( '0.##', x1 ) + ', Y1 = ' + FormatFloat( '0.##', y1 ) + ', X2 = ' + FormatFloat( '0.##', x2 ) + ', Y2 = ' + FormatFloat( '0.##', y2 );
    ksMessageW( PWideChar(mes) );
  end;
end;


//-------------------------------------------------------------------------------
// Навигация по коллекции линейных размеров
// ---
procedure LineDimensionNavigation;

var
  symbCont  : ISymbols2DContainer;
  dimCol    : ILineDimensions;
  lineDim   : ILineDimension;
  i         : integer;
  dimRef    : reference;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию линейных размеров
    dimCol := symbCont.LineDimensions;

    if ( dimCol <> nil ) then
    begin
      for i := 0 to dimCol.Count - 1 do
      begin
        // Получить объект из коллекции по индексу
        lineDim := dimCol.LineDimension[ i ];

        if ( lineDim <> nil ) then
        begin
          dimRef := lineDim.Reference;
          // Подсветить объект
          LightObj( dimRef, 1{включить подсветку} );
          // Выдать сообщение с параметрами линейного размера
          GetLineDimensionParam( lineDim );
          // Погасить объект
          LightObj( dimRef, 0{выключить подсветку} );
        end;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Изменить параметры у линейного размера
// ---
procedure ChangeLineDimensionParam( dim : ILineDimension );

var
  dimPar : IDimensionParams;
begin
  if ( dim <> nil ) then
  begin
    // Получить интерфейс параметров размера
    dimPar := dim As IDimensionParams;

    if ( dimPar <> nil ) then
    begin
      // Направление полки - влево
      dimPar.ShelfDirection := ksLSLeft;
      // Тип стрелок - угол 90 град.
      dimPar.ArrowType1 := ksRightAngle;
      dimPar.ArrowType2 := ksRightAngle;
    end;
    // Координаты точки начала полки
    dim.ShelfX := 60;
    dim.ShelfY := 200;
  end;
end;


//-------------------------------------------------------------------------------
// Изменить текст у линейного размера
// ---
procedure CHangeLineDimensionText( dim : ILineDimension );

var
  dimText : IDimensionText;
  prefix  : ITextLine;
begin
  if ( dim <> nil ) then
  begin
    // Получить интерфейс текста размера
    dimText := dim As IDimensionText;

    if ( dimText <> nil ) then
    begin
      // Текст в рамке
      dimText.Rectangle := true;
      // Подчеркнуть текст
      dimText.Underline := true;
      // Получить интерфейс текста до значения размера
      prefix := dimText.Prefix;

      if ( prefix <> nil ) then
        // Изменить текст
        prefix.Str := LoadStr( IDS_DIM );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Изменить линейный размер
// ---
procedure LineDimChange( dim : ILineDimension );
begin
  if ( dim <> nil ) then
  begin
    // Изменить параметры размера
    ChangeLineDimensionParam( dim );
    // Изменить текст размера
    ChangeLineDimensionText( dim );
    // Применить изменения
    dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Редактирование линейного размера
// ---
procedure EditLineDimension;

var
  info    : RequestInfoW;
  x, y    : double;
  pObj    : reference;
  lineDim : ILineDimension;
  mes     : WideString;
begin
  // Обнулить структуру параметров запроса к системе
  FillChar( info, SizeOf(info), 0 );
  // Строка состава команд
  mes := LoadStr(IDS_COMMAND1);
  info.commands := PWideChar( mes );

  // Указать объект в документе
  if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
  begin
    // Найти объект по указанным координатам
    pObj := FindObj( x, y, ksGetCursorLimit );

    // Если это линейный размер, редактировать
    if ( GetObjParam(pObj, nil, 0, 0) = LDIMENSION_OBJ ) then
    begin
      // Получить интерфейс линейного размера из референса объекта
      lineDim := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As ILineDimension;
      // Изменить линейный размер
      LineDimChange( lineDim );
      lineDim._Release;
    end

    else
    begin
      mes := LoadStr( IDS_NOTDIM );
      ksMessageW( PWideChar(mes) );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Создать радиальный размер
// ---
procedure CreateRadDimension( dim : IRadialDimension );

var
  info    : RequestInfoW;
  x, y    : double;
  pObj    : reference;
  par     : CircleParam;
  circle  : IDrawingObject;
  mes     : WideString;
begin
  if ( dim <> nil ) then
  begin
    // Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    // Строка состава команд
    mes := LoadStr(IDS_COMMAND2);
    info.commands := PWideChar( mes );

    // указать объект в документе
    if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
    begin
      // Найти объект по указанным координатам
      pObj := FindObj( x, y, ksGetCursorLimit );

      // Является ли объект окружностью
      if ( GetObjParam(pObj, @par, SizeOf(par), ALLPARAM_W) = CIRCLE_OBJ ) then
      begin
        // Получить интерфейс графического объекта из референса
        circle := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

        if ( circle <> nil ) then
        begin
          // Задать базовый объект размера
          dim.BaseObject := circle;
          // Задать координаты центра размера, совпадающие с центром указанной окружности
          dim.Xc := par.xc;
          dim.Yc := par.yc;
          // Задать радиус размера, совпадающий с радиусом указанной окружности
          dim.Radius := par.rad;
          // Тип размера - от центра
          dim.DimensionType := true;
          // Угол наклона размерной линии
          dim.Angle := 30;
          // Применить параметры
          dim.Update;
          circle._Release;
        end

        else
        begin
          mes := LoadStr(IDS_NOOBJ);
          ksMessageW( PWideChar(mes) );
        end;
      end

      else
      begin
        mes := LoadStr(IDS_NOTCREATE1);
        ksMessageW( PWideChar(mes) );
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Изменить параметры и текст у радиального размера
// ---
procedure ChangeRadialDimensionParamText( dim : IRadialDimension );

var
  dimPar  : IDimensionParams;
  dimText : IDimensionText;
  tUnit   : ITextLine;
begin
  if ( dim <> nil ) then
  begin
    // Получить интерфейс параметров размера
    dimPar := dim As IDimensionParams;

    if ( dimPar <> nil ) then
    begin
      // Направление полки - вправо
      dimPar.ShelfDirection := ksLSRight;
      // Угол наклона полки
      dimPar.ShelfAngle := 180;
      // Длина полки
      dimPar.ShelfLength := 30;
      // Тип стрелки - засечка
      dimPar.ArrowType1 := ksNotch;
    end;

    // Получить интерфейс текстов размера
    dimText := dim As IDimensionText;

    if ( dimText <> nil ) then
    begin
      // Значок перед номиналом - радиусом
      dimText.Sign := 3;

      // Получить интерфейс текста единицы измерения
      tUnit := dimText.Unit_;
      // Изменить текст
      if ( tUnit <> nil ) then
        tUnit.Str := LoadStr( IDS_UNIT );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактировать радиальный размер
// ---
procedure EditRadialDimension( dim : IRadialDimension );
begin
  if ( dim <> nil ) then
  begin
    // Тип размера - не от центра
    dim.DimensionType := false;
    // Изменить параметры и текст размера
    ChangeRadialDimensionParamText( dim );
    // Применить изменения
    dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера
// ---
procedure RadialDimensionWork;

var
  symbCont              : ISymbols2DContainer;
  radCol                : IRadialDimensions;
  radDim, radDimension  : IRadialDimension;
  dimRef                : reference;
  mes                   : WideString;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию радиальных размеров
    radCol := symbCont.RadialDimensions;

    if ( radCol <> nil ) then
    begin
      // Добавить радиальный размер в коллекцию
      radDim := radCol.Add;

      if ( radDim <> nil ) then
      begin
        // Создать радиальный размер
        CreateRadDimension( radDim );
        // Получить референс размера
        dimRef := radDim.Reference;
        mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
        begin
          // Получить объект из коллекции по референсу
          radDimension := radCol.RadialDimension[ dimRef ];
          // Редактировать радиальный размер
          EditRadialDimension( radDimension );
        end;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Создать диаметральный размер
// ---
procedure CreateDiametralDimension( dim : IDiametralDimension );

var
  info    : RequestInfoW;
  x, y    : double;
  mes     : WideString;
  pObj    : reference;
  par     : CircleParam;
  circle  : IDrawingObject;
begin
  if ( dim <> nil ) then
  begin
    // Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND2 );
    // Строка состава команд
    info.commands := PWideChar( mes );

    // Указать объект в документе
    if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
    begin
      // Найти объект по указанным координатам
      pObj := FindObj( x, y, ksGetCursorLimit );

      // Является ли объект окружностью
      if ( GetObjParam(pObj, @par, SizeOf(par), ALLPARAM_W) = CIRCLE_OBJ ) then
      begin
        // Получить интерфейс графического объекта из референса
        circle := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

        if ( circle <> nil ) then
        begin
          // Задать базовый объект размера
          dim.BaseObject := circle;
          // Задать координаты центра размера, совпадающие с центром указанной окружности
          dim.Xc := par.xc;
          dim.Yc := par.yc;
          // Задать радиус размера, совпадающий с радиусом указанной окружности
          dim.Radius := par.rad;
          // Тип размера - полная размерная линия
          dim.DimensionType := true;
          // Угол наклона размерной линии
          dim.Angle := 45;
          // Применить параметры
          dim.Update;
          circle._Release;
        end

        else
        begin
          mes := LoadStr( IDS_NOOBJ );
          ksMessageW( PWideChar(mes) );
        end;
      end

      else
      begin
        mes := LoadStr( IDS_NOTCREATE2 );
        ksMessageW( PWideChar(mes) );
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Изменить параметры и текст у диаметрального размера
// ---
procedure ChangeDiametralDimensionParamText( dim : IDiametralDimension );

var
  dimPar  : IDimensionParams;
  dimText : IDimensionText;
  suffix  : ITextLine;
begin
  if ( dim <> nil ) then
  begin
    // Получить интерфейс параметров размера
    dimPar := dim As IDimensionParams;

    if ( dimPar <> nil ) then
    begin
      // Направление полки - вправо
      dimPar.ShelfDirection := ksLSRight;
      // Длина полки
      dimPar.ShelfLength := 20;
      // Тип стрелок - точка
      dimPar.ArrowType1 := ksPoint;
      dimPar.ArrowType2 := ksPoint;
    end;

    // Получить интерфейс текстов размера
    dimText := dim As IDimensionText;

    if ( dimText <> nil ) then
    begin
      // Значок перед номиналом - диаметр
      dimText.Sign := 1;
      // Подчеркнуть
      dimText.Underline := true;

      // Получить интерфейс текста единицы измерения
      suffix := dimText.Suffix;

      // Изменить текст
      if ( suffix <> nil ) then
        suffix.Str := LoadStr( IDS_UNIT );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактировать диаметральный размер
// ---
procedure EditDiametralDimension( dim : IDiametralDimension );
begin
  if ( dim <> nil ) then
  begin
    // Тип размера - размерная линия с обрывом
    dim.DimensionType := false;
    // Угол наклона размерной линии
    dim.Angle := 90;
    // Изменить параметры и текст размера
    ChangeDiametralDimensionParamText( dim );
    // Применить изменения
    dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование диаметрального размера
// ---
procedure DiametralDimensionWork;

var
  symbCont                : ISymbols2DContainer;
  diamCol                 : IDiametralDimensions;
  diamDim, diamDimension  : IDiametralDimension;
  dimRef                  : reference;
  mes                     : WideString;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию диаметральных размеров
    diamCol := symbCont.DiametralDimensions;

    if ( diamCol <> nil ) then
    begin
      // Добавить диаметральный размер в коллекцию
      diamDim := diamCol.Add;

      if ( diamDim <> nil ) then
      begin
        // Создать диаметральный размер
        CreateDiametralDimension( diamDim );
        // Получить референс размера
        dimRef := diamDim.Reference;
        mes := LoadStr( IDS_EDIT );

        if ( YesNoW( PWideChar(mes) ) = 1 ) then
        begin
          // Получить объект из коллекции по референсу
          diamDimension := diamCol.DiametralDimension[ dimRef ];
          // Редактировать диаметральный размер
          EditDiametralDimension( diamDimension );
        end;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Создать угловой размер
// ---
procedure CreateAngleDimension( dim : IAngleDimension );

var
  {info                : RequestInfoW;
  x, y                : double;
  pObj1, pObj2        : reference;
  type1, type2        : integer;
  mes                 : WideString;}
  line1, line2        : reference;
  baseObj1, baseObj2  : IDrawingObject;
  dimPar              : IDimensionParams;
begin
  if ( dim <> nil ) then
  begin

    {// Построение размера на объектах, указанных в чертеже
    // Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND3 );
    // Строка состава команд
    info.commands := PWideChar( mes );

    // Указать первый базовый объект в документе
    if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
    begin
      // Найти объект по указанным координатам
      pObj1 := FindObj( x, y, ksGetCursorLimit );
      // Получить тип первого объекта
      type1 := GetObjParam( pObj1, nil, 0, 0 );

      // Если для объекта можно построить угловой размер
      if ( type1 = LINESEG_OBJ ) or ( type1 = POLYLINE_OBJ ) or ( type1 = RECTANGLE_OBJ) then
      begin
        // Подсветить указанный объект
        LightObj( pObj1, 1 );
        mes := LoadStr( IDS_COMMAND4 );
        info.commands := PWideChar( mes );

        // Указать второй базовый объект в документе
        if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
        begin
          // Найти объект по указанным координатам
          pObj2 := FindObj( x, y, ksGetCursorLimit );
          // Получить тип второго объекта
          type2 := GetObjParam( pObj2, nil, 0, 0 );

          // Если для объекта можно построить угловой размер
          if ( type2 = LINESEG_OBJ ) or ( type2 = POLYLINE_OBJ ) or ( type2 = RECTANGLE_OBJ) then
          begin
            // Подсветить указанный объект
            LightObj( pObj2, 1 );
            // Получить интерфейс графического объекта из референса
            baseObj1 := IUnknown(ksTransferReference( pObj1, ksGetCurrentDocument(0))) As IDrawingObject;
            baseObj2 := IUnknown(ksTransferReference( pObj2, ksGetCurrentDocument(0))) As IDrawingObject;

            if ( baseObj1 <> nil ) and ( baseObj2 <> nil ) then
            begin
              // Задать базовые объекты размера
              dim.BaseObject1 := baseObj1;
              dim.BaseObject2 := baseObj2;
              // Радиус дуги
              dim.Radius := 20;
              // Применить параметры
              dim.Update;
              // Убрать подсветку объекта
              LightObj( pObj2, 0 );
            end

            else
            begin
              mes := LoadStr( IDS_NOOBJS );
              ksMessageW( PWideChar(mes) );
            end;
            // Убрать подсветку объекта
            LightObj( pObj1, 0 );
          end

          else
          begin
            mes := LoadStr( IDS_NOTCREATE3 );
            ksMessageW( PWideChar(mes) );
          end;
        end;
      end

      else
      begin
        mes := LoadStr( IDS_NOTCREATE3 );
        ksMessageW( PWideChar(mes) );
      end;
    end;}

    // Построение размера на двух отрезках
    // Построить первый опорный объект
    line1 := LineSeg( 80, 120, 100, 120, 1 );
    baseObj1 := IUnknown(ksTransferReference( line1, ksGetCurrentDocument(0))) As IDrawingObject;
    // Построить второй опорный объект
    line2 := LineSeg( 80, 120, 120, 160, 1 );
    baseObj2 := IUnknown(ksTransferReference( line2, ksGetCurrentDocument(0))) As IDrawingObject;

    if ( baseObj1 <> nil ) and ( baseObj2 <> nil ) then
    begin
      // Задать опорные объекты
      dim.BaseObject1 := baseObj1;
      dim.BaseObject2 := baseObj2;
      // Координаты центра
      dim.Xc := 90;
      dim.Yc := 150;
      // Радиус дуги
      dim.Radius := 25;
      // Начальный угол размерной дуги
      dim.Angle1 := 45;
      // Конечный угол размерной дуги
      dim.Angle2 := 30;
      // Координаты точки выхода первой выносной линии
      dim.X1 := 80;
      dim.Y1 := 120;
      // Координаты точки выхода второй выносной линии
      dim.X2 := 100;
      dim.Y2 := 160;
      // Тип размера - на минимальный (острый) угол
      dim.DimensionType := ksADMinAngle;

      // Включить полку
      dimPar := dim As IDimensionParams;

      if ( dimPar <> nil ) then
        // Направление полки - вправо
        dimPar.ShelfDirection := ksLSRight;

      // Точка начала полки
      dim.ShelfX := 160;
      dim.ShelfY := 140;
      // Направление размерной дуги - против часовой стрелки
      dim.Direction := false;
      // Начало ножки или точка на дуге
      dim.X3 := 140;
      dim.Y3 := 120;
      // Применить параметры
      dim.Update;
      baseObj1._Release;
      baseObj2._Release;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактирование углового размера
// ---
procedure EditAngleDimension( dim : IAngleDimension );
begin
  if ( dim <> nil ) then
  begin
    // Тип размера - на максимальный (тупой) угол
    dim.DimensionType := ksADMaxAngle;
    // Направление размерной дуги - по часовой стрелке
    dim.Direction := true;
    // Точка начала полки
    dim.ShelfX := 150;
    dim.ShelfY := 170;
    // Радиус дуги
    dim.Radius := 40;
    // Применить изменения
    dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера
// ---
procedure AngleDimensionWork;

var
  symbCont              : ISymbols2DContainer;
  angCol                : IAngleDimensions;
  angDim, angDimension  : IAngleDimension;
  dimRef                : reference;
  mes                   : WideString;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию угловых размеров
    angCol := symbCont.AngleDimensions;

    if ( angCol <> nil ) then
    begin
      // Добавить угловой размер в коллекцию
      angDim := angCol.Add( ksDrADimension );

      if ( angDim <> nil ) then
      begin
        // Создать угловой размер
        CreateAngleDimension( angDim );
        // Получить референс размера
        dimRef := angDim.Reference;
        mes := LoadStr( IDS_EDIT );

        if ( YesNoW(PWideChar(mes)) = 1 ) then
        begin
          // Получить объект из коллекции по референсу
          angDimension := angCol.AngleDimension[ dimRef ];
          // Редактировать угловой размер
          EditAngleDimension( angDimension );
        end;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Создание размера дуги окружности
// ---
procedure CreateArcDimension( dim : IArcDimension );

var
  info  : RequestInfoW;
  x, y  : double;
  par   : ArcParam1;
  pObj  : reference;
  arc   : IDrawingObject;
  mes   : WideString;
begin
  if ( dim <> nil ) then
  begin
    // Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND5 );
    // Строка состава команд
    info.commands := PWideChar( mes );

    // Указать объект в документе
    if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
    begin
      // Найти объект по указанным координатам
      pObj := FindObj( x, y, ksGetCursorLimit );

      // Является ли объект дугой
      if ( GetObjParam(pObj, @par, SizeOf(par), POINT_ARC_PARAM) = ARC_OBJ ) then
      begin
        // Получить интерфейс графического объекта из референса
        arc := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

        if ( arc <> nil ) then
        begin
          // Задать базовый объект размера
          dim.BaseObject := arc;
          // Координаты центра
          dim.Xc := par.xc;
          dim.Yc := par.yc;
          // Координаты первой точки дуги
          dim.X1 := par.x1;
          dim.Y1 := par.y1;
          // Координаты второй точки дуги
          dim.X2 := par.x2;
          dim.Y2 := par.y2;
          mes := LoadStr( IDS_COMMAND6 );
          info.commands := PWideChar( mes );

          // Указать положение размерной линии
          if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
          begin
            dim.X3 := x;
            dim.Y3 := y;
          end;

          // Направление размерной дуги
          dim.Direction := true;
          // Тип размера - параллельные выносные линии
          dim.DimensionType := false;
          // Указатель от текста к дуге
          dim.TextPointer := true;
          // Применить параметры
          dim.Update;
          arc._Release;
        end

        else
        begin
          mes := LoadStr( IDS_NOOBJ );
          ksMessageW( PWideChar(mes) );
        end;
      end

      else
      begin
        mes := LoadStr( IDS_NOTCREATE4 );
        ksMessageW( PWideChar(mes) );
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактирование размера дуги окружности
// ---
procedure EditArcDimension( dim : IArcDimension );

var
  dimPar  : IDimensionParams;
  dimText : IDimensionText;
  tUnit   : ITextLine;
begin
  if ( dim <> nil ) then
  begin
    // Тип размера - выносные линии от центра
    dim.DimensionType := true;
    // Указатель от текста к дуге отключен
    dim.TextPointer := false;
    // Направление размерной дуги - поменять на противоположное
    dim.Direction := not dim.Direction;

    // Получить интерфейс параметров размера
    dimPar := dim As IDimensionParams;

    if ( dimPar <> nil ) then
    begin
      // Тип стрелок
      dimPar.ArrowType1 := ksLeaderPoint;
      dimPar.ArrowType2 := ksLeaderPoint;
      // Направление полки - вниз
      dimPar.ShelfDirection := ksLSDown;
      // Угол наклона полки
      dimPar.ShelfAngle := 180;
    end;

    // Получить интерфейс текста размера
    dimText := dim As IDimensionText;

    if ( dimText <> nil ) then
    begin
      // Отключить автоматическое определение номинального значения
      dimText.AutoNominalValue := false;
      // Установить новое номинальное значение
      dimText.NominalValue := 50;

      // Получить интерфейс текста единицы измерения
      tUnit := dimText.Unit_;

      // Задать текстовую строку
      if ( tUnit <> nil ) then
        tUnit.Str := LoadStr( IDS_UNIT2 );
    end;

    // Применить изменения
    dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование размера дуги окружности
// ---
procedure ArcDimensionWork;
var
  symbCont              : ISymbols2DContainer;
  arcCol                : IArcDimensions;
  arcDim, arcDimension  : IArcDimension;
  dimRef                : reference;
  mes                   : WideString;
begin
  // Получить контейнер условных обозначений
  symbCont := GetSymbols2DContainer;

  if ( symbCont <> nil ) then
  begin
    // Получить коллекцию размеров дуги окружности
    arcCol := symbCont.ArcDimensions;

    if ( arcCol <> nil ) then
    begin
      // Добавить размер дуги окружности в коллекцию
      arcDim := arcCol.Add;

      if ( arcDim <> nil ) then
      begin
        // Создать размер дуги окружности
        CreateArcDimension( arcDim );
        // Получить референс размера
        dimRef := arcDim.Reference;
        mes := LoadStr( IDS_EDIT );

        if ( YesNoW(PWideChar(mes)) = 1 ) then
        begin
          // Получить объект из коллекции по референсу
          arcDimension := arcCol.ArcDimension[ dimRef ];
          // Редактировать размер дуги окружности
          EditArcDimension( arcDimension );
        end;
      end;
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Создание линейного размера с обрывом
// ---
procedure CreateBreakLineDim( dim : IBreakLineDimension );
var
  info    : RequestInfoW;
  x, y    : double;
  par     : LineSegParam;
  pObj    : reference;
  lineSeg : IDrawingObject;
  mes     : WideString;
begin
  if ( dim <> nil ) then
  begin
    // Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND7 );
    // Строка состава команд
    info.commands := PWideChar( mes );

    // Указать объект в документе
    if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
    begin
      // Найти объект по указанным координатам
      pObj := FindObj( x, y, ksGetCursorLimit );

      // Является ли объект отрезком
      if ( GetObjParam(pObj, @par, SizeOf(par), ALLPARAM_W) = LINESEG_OBJ ) then
      begin
        // Подсветить указанный объект
        LightObj( pObj, 1 );
        // Получить интерфейс графического объекта из референса
        lineSeg := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

        if ( lineSeg <> nil ) then
        begin
          // Задать базовый объект размера
          dim.BaseObject := lineSeg;
          mes := LoadStr( IDS_COMMAND6 );
          info.commands := PWideChar( mes );

          // Указать положение размерной линии
          if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
          begin
            dim.X1 := par.x1;
            dim.Y1 := par.y1;
            dim.X2 := par.x2;
            dim.Y2 := par.Y2;
            dim.X3 := x;
            dim.Y3 := y;
          end;

          // Применить параметры
          dim.Update;
          lineSeg._Release;
        end

        else
        begin
          mes := LoadStr( IDS_NOOBJ );
          ksMessageW( PWideChar(mes) );
        end;
      end

      else
      begin
        mes := LoadStr( IDS_NOTCREATE5 );
        ksMessageW( PWideChar(mes) );
      end;

      // Убрать подсветку объекта
      LightObj( pObj, 0 );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактирование линейного размера с обрывом
// ---
procedure EditBreakLineDim( dim : IBreakLineDimension );

var
  dimPar          : IDimensionParams;
  dimText         : IDimensionText;
  prefix, nominal : ITextLine;
begin
  if ( dim <> nil ) then
	begin
		// Получить интерфейс параметров размера
		dimPar := dim As IDimensionParams;

		if ( dimPar <> nil ) then
			// Тип стрелки
			dimPar.ArrowType1 := ksLeftNotch;

		// Получить интерфейс текста размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
		begin
			// Получить текст перед размером
			prefix := dimText.Prefix;

			if ( prefix <> nil ) then
				// Изменить текст
				prefix.Str := LoadStr( IDS_DIM );

			// Получить текст номинального значения
			nominal := dimText.NominalText;

			if ( nominal <> nil ) then
				// Изменить текст
				nominal.Str := LoadStr( IDS_NOMINAL );
		end;
		// Применить изменения
		dim.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование линейного размера с обрывом
// ---
procedure BreakLineDimensionWork;

var
  symbCont                  : ISymbols2DContainer;
  breakCol                  : IBreakLineDimensions;
  breakDim, breakDimension  : IBreakLineDimension;
  dimRef                    : reference;
  mes                       : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линейных размеров с обрывом
		breakCol := symbCont.BreakLineDimensions;
		
		if ( breakCol <> nil ) then
		begin
			// Добавить линейный размер с обрывом в коллекцию
			breakDim := breakCol.Add;

			if ( breakDim <> nil ) then
			begin
				// Создать линейный размер с обрывом
				CreateBreakLineDim( breakDim );
				// Получить референс размера
				dimRef := breakDim.Reference;
        mes := LoadStr( IDS_EDIT );
				
				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					breakDimension := breakCol.BreakLineDimension[ dimRef ];
					// Редактировать линейный размер с обрывом
					EditBreakLineDim( breakDimension );
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание радиального размера с изломом
// ---
procedure CreateBreakRadialDim( dim : IBreakRadialDimension );

var
  info    : RequestInfoW;
  mes     : WideString;
  x, y    : double;
  pObj    : reference;
  par     : CircleParam;
  circle  : IDrawingObject;
begin
	if ( dim <> nil ) then
	begin
		// Структура параметров запроса к системе
		FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND2 );
		info.commands := PWideChar( mes );
		
		// Указать объект в документе
		if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
		begin
			// Найти объект по указанным координатам
			pObj := FindObj( x, y, ksGetCursorLimit );
			
			// Является ли объект окружностью
			if ( GetObjParam(pObj, @par, SizeOf(par), ALLPARAM_W ) = CIRCLE_OBJ ) then
			begin
				// Получить интерфейс графического объекта из референса
				circle := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

				if ( circle <> nil ) then
				begin
					// Задать базовый объект размера
					dim.BaseObject := circle;
					// Задать координаты центра размера, совпадающие с центром указанной окружности
					dim.Xc := par.xc;
					dim.Yc := par.yc;
					// Задать радиус размера, совпадающий с радиусом указанной окружности
					dim.Radius := par.rad;
					// Угол наклона размерной линии
					dim.Angle := 45;
					// Длина излома
					dim.BreakLength := 3;
					// Положение размерной надписи
					dim.TextOnLine := ksDimTextParallelOnLine;
					// Применить параметры
					dim.Update;
          circle._Release;
				end

				else
        begin
          mes := LoadStr( IDS_NOOBJ );
					ksMessageW( PWideChar(mes) );
        end;
			end

			else
      begin
        mes := LoadStr( IDS_NOTCREATE1 );
				ksMessageW( PWideChar(mes) );
      end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать радиальный размер с изломом
// ---
procedure EditBreakRadialDim( dim : IBreakRadialDimension  );

var
  dimText : IDimensionText;
begin
	if ( dim <> nil ) then
	begin
		// Угол наклона размерной линии
		dim.Angle := 90;
		// Длина излома
		dim.BreakLength := 1;
		// Положение размерной надписи
		dim.TextOnLine := ksDimTextParallelInCut;
	  // Получить интерфейс текста размера
	  dimText := dim As IDimensionText;

	  if ( dimText <> nil ) then
		  // Убрать значок радиуса
		  dimText.Sign := 0;

	  // Применить изменения
	  dim.Update;
  end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера с изломом
// ---
procedure BreakRadialDimensionWork;

var
  symbCont                  : ISymbols2DContainer;
  breakCol                  : IBreakRadialDimensions;
  breakDim, breakDimension  : IBreakRadialDimension;
  dimRef                    : reference;
  mes                       : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию радиальных размеров с изломом
		breakCol := symbCont.BreakRadialDimensions;
		
		if ( breakCol <> nil ) then
		begin
			// Добавить радиальный размер с изломом в коллекцию
			breakDim := breakCol.Add;

			if ( breakDim <> nil ) then
			begin
				// Создать радиальный размер с изломом
				CreateBreakRadialDim( breakDim );
				// Получить референс размера
				dimRef := breakDim.Reference;
        mes := LoadStr( IDS_EDIT );

				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					breakDimension := breakCol.BreakRadialDimension[ dimRef ];
					// Редактировать радиальный размер с изломом
					EditBreakRadialDim( breakDimension );
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание углового размера с обрывом
// ---
procedure CreateBreakAngleDim( dim : IBreakAngleDimension );

var
  line1, line2 : reference;
  baseObj1, baseObj2 : IDrawingObject;
begin
	if ( dim <> nil ) then
	begin
		// Построить первый опорный объект
		line1 := LineSeg( 80, 120, 120, 160, 1 );
    baseObj1 := IUnknown(ksTransferReference( line1, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;
		// Построить второй опорный объект
		line2 := LineSeg( 80, 120, 100, 120, 1 );
		baseObj2 := IUnknown(ksTransferReference( line2, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;

		if ( baseObj1 <> nil ) and ( baseObj2 <> nil ) then
		begin
			// Задать опорные объекты
			dim.BaseObject1 := baseObj1;
			dim.BaseObject2 := baseObj2;
			// Координаты центра
			dim.Xc := 80;
			dim.Yc := 120;
			// Радиус дуги
			dim.Radius := 20;
			// Начальный угол  размерной дуги
			dim.Angle1 := 45;
			// Конечный угол  размерной дуги
			dim.Angle2 := 30;
			// Координаты точки выхода первой выносной линии
			dim.X1 := 120;
			dim.Y1 := 160;
			// Координаты точки выхода второй выносной линии
			dim.X2 := 100;
			dim.Y2 := 160;
			// Тип размера - на минимальный (острый) угол
			dim.DimensionType := ksADMinAngle;
			// Направление размерной дуги - против часовой стрелки
			dim.Direction := true;
			// Начало ножки или точка на дуге
			dim.X3 := 165;
			dim.Y3 := 140;
			// Применить параметры
			dim.Update;
      baseObj1._Release;
      baseObj2._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование углового размера с обрывом
// ---
procedure EditBreakAngleDim( dim : IBreakAngleDimension  );

var
  dimPar  : IDimensionParams;
  dimText : IDimensionText;
begin
	if ( dim <> nil ) then
	begin
		// Включить полку
		dimPar := dim As IDimensionParams;

		if ( dimPar <> nil ) then
			// Направление полки - вправо
			dimPar.ShelfDirection := ksLSRight;
		
		// Точка начала полки
		dim.ShelfX := 167;
		dim.ShelfY := 177;

		// Получить интерфейс текстов размера
		dimText := dim As IDimensionText;

    if ( dimText <> nil ) then
		begin
			// Выравнивание размерной надписи
			dimText.TextAlign := ksDimALowerBoundary;
			// Текст в круглых скобках
			dimText.Brackets := ksDimBrackets;
		end;
		// Применить изменения
		dim.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера с обрывом
// ---
procedure BreakAngleDimensionWork;

var
  symbCont                  : ISymbols2DContainer;
  breakCol                  : IAngleDimensions;
  breakDim, breakDimension  : IBreakAngleDimension;
  dimRef                    : reference;
  mes                       : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию угловых размеров с обрывом
		breakCol := symbCont.AngleDimensions;

		if ( breakCol <> nil ) then
		begin
			// Добавить угловой размер с обрывом в коллекцию
			breakDim := breakCol.Add( ksDrABreakDimension ) As IBreakAngleDimension;
			
			if ( breakDim <> nil ) then
			begin
				// Создать угловой размер с обрывом
				CreateBreakAngleDim( breakDim );
				// Получить референс размера
				dimRef := breakDim.Reference;
        mes := LoadStr( IDS_EDIT );
				
				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					breakDimension := breakCol.AngleDimension[ dimRef ] As IBreakAngleDimension;
					// Редактировать угловой размер с обрывом
					EditBreakAngleDim( breakDimension );
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать размер высоты
// ---
procedure CreateHeightDimension( dim : IHeightDimension  );

var
  info                  : RequestInfoW;
  mes                   : WideString;
  x, y, x1, y1, x2, y2  : double;
begin
	if ( dim <> nil ) then
	begin
		// Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    mes := LoadStr( IDS_COMMAND8 );
    // Строка состава команд
    info.commands := PWideChar( mes );

		// Указать точку нулевого уровня
		if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
		begin
      mes := LoadStr( IDS_COMMAND9 );
      info.commands := PWideChar( mes );

			// Указать точку измеряемого уровня
			if ( ksCursorExW(@info, x1, y1, nil, nil) <> 0 ) then
			begin
        mes := LoadStr( IDS_COMMAND10 );
        info.commands := PWideChar( mes );
				
				// Указать положение размерной надписи
				if ( ksCursorExW(@info, x2, y2, nil, nil) <> 0 ) then
				begin
					// Точка нулевого уровня
					dim.X := x;
					dim.Y := y;
					// Точка измеряемого уровня
					dim.X1 := x1;
					dim.Y1 := y1;
					// Положение размерной надписи
					dim.X2 := x2;
					dim.Y2 := y2;
					// Применить параметры
					dim.Update;
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать размер высоты
// ---
procedure EditHeightDimension( dim : IHeightDimension  );

var
  dimText : IDimensionText;
  nominal : ITextLine;
begin
	if ( dim <> nil ) then
	begin
		// Тип размера
		dim.DimensionType := ksHDTopViewLeader;

		// Получить интерфейс текста размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
		begin
			// Условный значок - квадрат
			dimText.Sign := 2;
			// Получить текст номинального значения
			nominal := dimText.NominalText;
			
			if ( nominal <> nil )then
				// Изменить текст
				nominal.Str := LoadStr( IDS_NOMINAL );
		end;
		// Применить изменения
		dim.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование размера высоты
// ---
procedure HeightDimensionWork;

var
  symbCont                    : ISymbols2DContainer;
  heightCol                   : IHeightDimensions;
  heightDim, heightDimension  : IHeightDimension;
  dimRef                      : reference;
  mes                         : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линейных размеров с обрывом
		heightCol := symbCont.HeightDimensions;
		
		if ( heightCol <> nil ) then
		begin
			// Добавить линейный размер с обрывом в коллекцию
			heightDim := heightCol.Add;
			
			if ( heightDim <> nil ) then
			begin
				// Создать линейный размер с обрывом
				CreateHeightDimension( heightDim );
				// Получить референс размера
				dimRef := heightDim.Reference;
        mes := LoadStr( IDS_EDIT );
				
				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					heightDimension := heightCol.HeightDimension[ dimRef ];
					// Редактировать линейный размер с обрывом
					EditHeightDimension( heightDimension );
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    newKompasAPI := disp As IApplication;
  end;
end;


//----------------------------------------------------------------------------------------------
// Загрузить строку из ресурсов
//---
function LoadStr( ID : Integer ) : string;
var
  buf : array [0..255] of AnsiChar;
begin
  ksConvertLangStrEx( hInstance, ID, buf, 255 );
  Result := buf;
end;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessage( str : string; flags : integer ) : Integer;
var
 enabse : Integer;
begin
  enabse := IsEnableTaskAccess();  // проверка доступа
  if enabse <> 0 then             // если доступ к задаче разрешен
    EnableTaskAccess(0);          // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
  Result := Application.MessageBox( PChar(str), PChar(LoadStr(LIBRARYID)), flags );

  if enabse <> 0 then                         // если доступ к задаче был запрещен
    EnableTaskAccess(1);              // разрешаем доступ к задаче

end;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessageByID( strId, flags : Integer ) : Integer;
begin
  Result := LibMessage( LoadStr(strId), flags );
end;

end.


