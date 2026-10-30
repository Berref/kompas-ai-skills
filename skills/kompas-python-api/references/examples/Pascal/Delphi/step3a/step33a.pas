unit Step33a;
//******************************************************************/
//*               (c)Акционерное общество АСКОН                    */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*                       Объекты-a                                */
//* 1.  Контур                            - WorkContour            */
//* 2.  Технические требования            - TDemWork               */
//* 3.  Стрелка вида                      - DrawViewPointer        */
//* 4.  Работа со штампом                 - WorkStamp              */
//* 5.  Таблица                           - TableWork              */
//* 6.  Эквидистанта                      - DrawEquidistant        */
//* 7.  Эллипс                            - DrawEllipse            */
//* 8.  Полилиния                         - DrawPolyline           */
//* 9.  Nurbs                             - DrawNurbs              */
//* 10. Допуск формы                      - WorkTolerance          */
//* 11. Одинаковая шероховатость          - DrawSpecRough          */
//* 12. Вставка фрагмента внешней ссылкой - DrawInsFragment1       */
//* 13. Вставка локального фрагмента      - DrawInsFragment2       */
//*                                                                */
//******************************************************************/

interface

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
  procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;
  procedure  WorkContour;
  procedure  TDemWork;
  procedure  DrawViewPointer;
  procedure  WorkStamp;
  procedure  TableWork;
  procedure  DrawEquidistant;
  procedure  DrawEllipse;
  procedure  DrawPolyline;
  procedure  DrawNurbs;
  procedure  WorkTolerance;
  procedure  DrawInsFragment1;
  procedure  DrawInsFragment2;

implementation

  uses Sysutils, LtDefine, LibTool, LDefin2D;

//----------------------------------------------------------------------------------------
// Задать идентификатор ресурсов
//---
function   LIBRARYID : Cardinal;  pascal;
begin
  LIBRARYID:=100;
end;

//----------------------------------------------------------------------------------------
// Головная функция библиотеки
//---
procedure  LIBRARYENTRY( comm : Word  );  pascal;
begin

  case comm of
    1:  WorkContour();             // Контур
    2:  TDemWork();                // Технические требования
    3:  DrawViewPointer();         // Стрелка вида
    4:  WorkStamp();               // Работа со штампом
    5:  TableWork();               // Таблица
    6:  DrawEquidistant();         // Эквидистанта
    7:  DrawEllipse();             // Эллипс
    8:  DrawPolyline();            // Полилиния
    9:  DrawNurbs();               // Nurbs
    10: WorkTolerance();           // Допуск формы
    11: SpecRough( 2, 1, 'Rz40' ); // Одинаковая шероховатость
    12: DrawInsFragment1();        // Вставка фрагмента внешней ссылкой
    13: DrawInsFragment2();        // Вставка локального фрагмента
  end; {case}

end;

//-------------------------------------------------------------------------------
// Построить контур
//---
procedure WorkContour;
var
  _contour,              // Контур
   g      : Reference;   // Группа
begin
  if ( Contour( 1 ) > 0 ) then                       // Контур
  begin
    LineSeg( 20, 30, 50, 30, 1 );                    // Отрезок
    ArcByPoint( 50, 20, 10, 50, 30, 50, 10, -1, 1 ); // Дуга

    //вложенный контур
    Contour( 2 );
      LineSeg( 50, 10, 20, 10, 1 );                  // Отрезок
      ArcByPoint( 20, 20, 10, 20,10, 20, 30,-1, 1);  // Дуга
    EndObj();

    _contour := EndObj();

    // Подсветить контур
    LightObj( _contour, 1 );
    ksMessage( 'контур' );
    LightObj( _contour, 0 );

    // Добавим контур в группу
    g := NewGroup(0);
    EndGroup();
    AddObjGroup( g, _contour);

    // Сместим группу
    MoveObj( g, 10, 10 );
    ksMessage( 'сдвинули группу' );

  end;
end;

//--------------------------------------------------------------------------------
// заполнение технических требований
// расположим ТТ на двух листах ,для формата A3
//---
procedure TDemWork;
var
  pGab : Reference; // Массив габаритов окон технических требований
  par  : RectParam; // Габариты окна
begin

  pGab := CreateArray( RECT_ARR, nil );
  //поместим техтребования в двух габаритных окнах
  par.pBot.x:= 230; par.pBot.y := 65;
  par.pTop.x:= 415; par.pTop.y := 80;
  AddArrayItem( pGab, -1, Addr(par), SizeOf(RectParam ) ); // Первое окно
  par.pBot.x:= 45;  par.pBot.y := 15;
  par.pTop.x:= 230; par.pTop.y := 60;
  AddArrayItem( pGab, -1, Addr(par), sizeof(RectParam ) ); // Второе окно
  // Открываем технические требования на редактирование
  if( OpenTechnicalDemand( pGab, 0 ) > 0 ) then
  begin
    TextLine( NEW_LINE, 0, nil, '1111111' );
    TextLine( NEW_LINE, 0, nil, '2222222' );
    TextLine( NEW_LINE, 0, nil, '3333333' );
    TextLine( NEW_LINE, 0, nil, '4444444' );
    TextLine( NEW_LINE, 0, nil, '5555555' );
    TextLine( NEW_LINE, 0, nil, '6666666' );
    CloseTechnicalDemand( ); // Завершение редактирования
  end;
end;

//------------------------------------------------------------------------------
// Создание стрелки вида
//---
procedure DrawViewPointer;
var
  par  : ViewPointerParam; // Параметры стрелки вида
  par3 : TextItemParam ;   // Параметры элемента строки
  p    : Reference;        // Указатель объекта
  tip  : Integer;          // Тип
  buf  : AnsiString;

  //----------------------------------------------------------------------------------------
  // Вывод параметров
  procedure PrintPar1;
  var
    j, count : Integer;
  begin
    count := GetArrayCount( par.pTextItem ); // Количество элементов строки
    for j:=0 to count-1 do
    begin
      GetArrayItem( par.pTextItem, j, Addr(par3), SizeOf(TextItemParam) );
      buf := Format('j=%d h=%5.1f  s=%s fontName=%s ',
                    [j, par3.font.height, par3.s, par3.font.fontName] );
      ksMessage(PAnsiChar(buf));
    end;
  end;

begin

  par.x1 := 55; par.y1 := 50;    // Координаты вершины( острия) стрелки
  par.x2 := 40; par.y2 := 50;    // Координаты конечной точки стрелки
  par.xt := 40; par.yt := 52;    // Координаты текста
  par._type := 0;                // Текст в виде строки
  StrCopy( par.str, 'A' );       // Надпись

  p := ViewPointer( Addr(par) ); // Создание "стрелки вида"
  if ( ExistObj( p ) > 0 ) then
  begin
    // Подсветили объект
    LightObj( p, 1 );
    ksMessage('Создали стрелку вида');
    LightObj( p, 0 );

    // Получение и вывод параметров "стрелки вида"
    FillChar( par, SizeOf(par), 0 );
    GetObjParam( p, Addr(par), SizeOf(par), ALLPARAM );
    tip := par._type;
    buf := Format( ' tip = %d x1 = %5.1f y1 = %5.1f x2 = %5.1f y2 = %5.1f xt = %5.1f yt = %5.1f ',
                     [tip, par.x1, par.y1, par.x2, par.y2, par.xt, par.yt]);
    ksMessage(PAnsiChar(buf));
    PrintPar1;
  end;
end;

//--------------------------------------------------------------------------------
// заполнение основной надписи
//---
procedure  WorkStamp;
begin

  if ( OpenStamp()>0 ) then
  begin
    ColumnNumber( 2 );     // Определить номер графы штампа, определяет графу с номером как текущую
    // Задание подстроки основной надписи
    TextLine( NEW_LINE,    // Значения свойств, устанавливаемые двоичными флагами 
              0,           // Тип свойства
              nil,           // Указатель на значение свойства
              '1111111' ); // Строка
    CloseStamp();
  end;

end;

//-------------------------------------------------------------------------------
// Создание таблицы
//---
procedure TableWork;
begin

  Table;
    // Рисуем сетку
    LineSeg(50, 50, 90, 50, 1 );
    LineSeg(50, 40, 90, 40, 1 );
    LineSeg(50, 30, 90, 30, 1 );
    LineSeg(50, 50, 50, 30, 1 );
    LineSeg(70, 50, 70, 30, 1 );
    LineSeg(90, 50, 90, 30, 1 );
    // Выводим текст в ячейках
    ksText( 52, 48, 0, 5, 1, 0, '1' );
    ksText( 72, 48, 0, 5, 1, 0, '2' );
    ksText( 52, 38, 0, 5, 1, 0, '3' );
    ksText( 72, 38, 0, 5, 1, 0, '4' );
  EndObj;

end;

//--------------------------------------------------------------------------------
// Построить эквидистанту
//---
procedure DrawEquidistant;
var
  par  : EquidistantParam;
  info : RequestInfo;
  x, y : Double;
  j    : Integer;
  p1   : Reference;
begin


  par.side      := 2;     // Признак, с какой стороны строить эквидистанту
                          // 0-слева по направлению, 1-справа по направлению, 2-с двух сторон
  par.cutMode   := 0;     // Тип обхода углов контура
                          // 0-обход срезом, 1- обход дугой
  par.degState  := 0;     // Флаг разрешения вырожденных сегментов эквидистанты
                          // 0-вырожденные сегменты запрещены, 1-вырожденные сегменты разрешены
  par.radRight  := 5;     // Радиус эквидистанты
  par.radLeft   := 3;     // Радиус эквидистанты
  par.style     :=1;      // Тип линии
  info.commands := 'Укажите объект';;
  info.title    := nil;   // Строка или идентификатор строки заголовка окна
  info.prompt   := nil;   // Строка или идентификатор приглашения
  info.cursor   := nil;   // Строка с именем или идентификатор стандартного курсора
  info.callBack := nil;   // Указатель на функцию обратной связи
  info._dynamic     := 0; // Признак динамического запроса 1-динамический запрос, 0-статический
  info.commInstance := 0; // Instance модуля, в ктором размещен состав команд

 //найдем объект
  repeat
    j := ksCursor( Addr(info), x ,y, nil );
    if j <> 0 then
    begin
      par.geoObj := FindObj( x, y, 1e6 );
      if ExistObj( par.geoObj ) > 0 then
      begin
        p1 :=  Equidistant( Addr(par) ); // Создаем эквидистанту
        if p1 <> 0 then                  // Эквидистанта создана
        begin
          LightObj( p1, 1 );             // Подсветить эквидистанту
          ksMessage( 'эквидистанта' );
          LightObj( p1, 0 );
        end
        else
          MessageBoxResult();            // Результат работы
      end
      else
        Error( 'Объект не найден' );
    end;
  until j = 0;
end;

//--------------------------------------------------------------------------------
//  Создать эллипс
//---
procedure DrawEllipse;
var
  par : EllipseParam;          // Параметры элепса
  p   : Reference;             // Указатель объекта
begin
  par.xc    := 50;             // Координаты центра
  par.yc    := 40;
  par.a     := 20;             // Длина полуосей эллипса
  par.b     := 10;
  par.ang   := 0;              // Угол
  par.style := 1;              // Стиль линии
  p := ksEllipse( Addr(par) ); // Элипс
  // Подсветим элемент
  LightObj( p, 1 );
  ksMessage( 'эллипс' );
  LightObj( p, 0 );
end;

//-------------------------------------------------------------------------------
//  Создание полилинии
//---
procedure DrawPolyline;
type
  MathArr = array [0..4] of MathPointParam;
var
  par : PolylineParam; // Параметры полилинии
  pr  : MathArr;       // Массив точек
  p   : Reference;     // Указатель объекта
  i   : Integer;
begin
  // Координаты точек полилинии
  pr[0].x := 10; pr[0].y := 10;
  pr[1].x := 20; pr[1].y := 20;
  pr[2].x := 30; pr[2].y := 10;
  pr[3].x := 40; pr[3].y := 20;

  // Пример создания полилинии как составного объекта
  ksPolyline( 1 );
    for i := 0 to 3 do
    begin
      Point( pr[i].x, pr[i].y, 1 ); // Добавление точки в полилинию
      pr[i].y := pr[i].y + 10;      // Изменение координат точки для следующей полилинии
    end;
  p := EndObj();

  LightObj( p, 1);
    ksMessage( 'Полилиния как составной объект' );
  LightObj( p, 0);

  // Пример создания полилинии одной функцией
  // Создание массива точек
  par.pMathPoint := CreateArray( POINT_ARR,  nil );

  // Добавляем координаты точек в массив
  for i := 0 to 3 do
    AddArrayItem( par.pMathPoint, -1, Addr(pr[i]), sizeof( MathPointParam ) );

  par.style := 2; // Стиль полилинии - 2 - тонкая линия

  // Создание полилинии
  p := _ksPolyline( Addr(par) );

  // Подсветить полилинию
  LightObj( p, 1);
  ksMessage( 'Полилиния по структуре' );
  LightObj( p, 0);

  // Удалить массив точек
  DeleteArray( par.pMathPoint );
end;

//---------------------------------------------------------------------------------
// Создать Nurbs - сплайн
//---
procedure DrawNurbs;
type
  NurbsArr = array [0..6] of NurbsPointParam;
var
  par : NurbsArr;  // Массив параметров точек Nurbs-а
  p   : Reference; // Указатель объекта
  i   : Integer;
begin
  // Координаты точек
  par[0].x := 0;   par[0].y := 0;   par[0].weight := 1;
  par[1].x := 20;  par[1].y := 20;  par[1].weight := 1;
  par[2].x := 50;  par[2].y := 10;  par[2].weight := 1;
  par[3].x := 70;  par[3].y := 20;  par[3].weight := 1;
  par[4].x := 100; par[4].y := 0;   par[4].weight := 1;
  par[5].x := 50;  par[5].y := -50; par[5].weight := 1;

  // Построить Nurbs сплайн  как составной объект
  Nurbs( 3, 1, 1 );
    for i:=0 to 5 do
      NurbsPoint( Addr(par[i]) ); // Создать Nurbs
  p := EndObj();

  // Подсветить Nurbs
  LightObj(p, 1 );
  ksMessage('NURBS');
  LightObj(p, 0 );

end;

//------------------------------------------------------------------------------
// Допуск формы
//---
procedure WorkTolerance;
var
  par      : ToleranceParam; // Параметры допуска формы
  parPoint : MathPointParam; // Параметры точки
  p        : Reference;      // Указатель объекта
  tip      : Integer;        // Тип
begin

  //заполняем параметры 1-ой ноги
  par.branch1.arrowType  := 2;  // Тип опоры ( 0 - нет опоры, 1 - треугольник, 2 - стрелка )
  par.branch1.tCorner    := 1;  // Число от 1 до 8, определяющее точку выхода "опоры" из таблицы
  par.branch1.pMathPoint := CreateArray( POINT_ARR,  nil ); // Массив точек опоры
  parPoint.x             := 40; // Координаты точки опоры
  parPoint.y             := 10;
  AddArrayItem( par.branch1.pMathPoint, -1, Addr(parPoint), SizeOf( parPoint ) );

  //заполняем параметры 2-ой ноги
  par.branch2.arrowType  := 1;  // Тип опоры ( 0 - нет опоры, 1 - треугольник, 2 - стрелка )
  par.branch2.tCorner    := 5;  // Число от 1 до 8, определяющее точку выхода "опоры" из таблицы
  par.branch2.pMathPoint := CreateArray( POINT_ARR,  nil ); // Массив точек опоры
  parPoint.x := 100; parPoint.y := 50; // Координаты первой точки опоры
  AddArrayItem( par.branch2.pMathPoint, -1, Addr(parPoint), SizeOf( parPoint ) );
  parPoint.x := 100; parPoint.y := 10; // Координаты второй точки опоры
  AddArrayItem( par.branch2.pMathPoint, -1, Addr(parPoint) , SizeOf( parPoint ) );

  par.x     := 40; // Координаты базовой точки
  par.y     := 40;
  par._type := 0;  // Ориентация таблицы допуска ( 0 - горизонтально, 1 - вертикально )

  // Создаем допуск формы как составной объект
  if(Tolerance( Addr(par) ) > 0) then
  begin
    // Заполнение ячеек таблицы допуска формы
    // 1-я графа
    ColumnNumber( 1 );
    tip := 26;         // Спецзнак
    TextLine( SPECIAL_SYMBOL, SPECIAL, Addr(tip), '' );

    // 2-я графа
    ColumnNumber( 2 );
    TextLine (NEW_LINE, 0, nil, '222' );

    // 3-я графа
    ColumnNumber( 3 );
    TextLine (NEW_LINE, 0, nil, '333' );

    // 11-я графа
    ColumnNumber( 11 );
    tip := 23;         // Спецзнак
    TextLine ( SPECIAL_SYMBOL  ,SPECIAL, Addr(tip) ,'' );

    // 12-я графа
    ColumnNumber( 12 );
    TextLine (NEW_LINE  ,0, nil ,'444');

    // 13-я графа
    ColumnNumber( 13 );
    TextLine (NEW_LINE  ,0, nil ,'555');

    p := EndObj();    // Вернется указатель на допуск формы
    LightObj( p, 1 ); // Подсветить объект
    ksMessage( 'Допуск формы' );
    LightObj( p, 0 );
  end;
  // Удаляем массивы точек
  DeleteArray( par.branch2.pMathPoint );
  DeleteArray( par.branch1.pMathPoint );

end;

//--------------------------------------------------------------------------------
//  Вставка внешнего фрагмента
//---
procedure  DrawInsFragment1;
var
  par     : PlacementParam; // Параметры расположения объекта
  pDefFrg : Reference;      // Указатель на описание параметров вставки фрагмента
  p       : Reference;      // Указатель объекта
begin

  // Оределим фрагмент для вставки
  pDefFrg := FragmentDefinition( 'c:\1.frw',  // Имя файла фрагмента
                                     'frw1',  // Имя вставки
                                         1 ); // Тип вставки -действителен для внешнего фрагмента
                                              // 0- взять в документ, 1-внешней ссылкой
  if( pDefFrg > 0 )  then
  begin
    par.xBase := 30; // Координаты вставки фрагмента
    par.yBase := 40;
    par.ang   := 45; // Угол поворота
    par.scale := 2;  // Масштаб
    //создаем объект "вставка фрагмента"
    p := InsertFragment( pDefFrg,     // Указатель определения  фрагмента
                         0,           //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                         Addr(par) ); //параметры привязки
    // Подсветить объект
    LightObj ( p, 1 );
    ksMessage( 'вставка внешнего фрагмента' );
    LightObj ( p, 0 );
  end;
end;

//--------------------------------------------------------------------------------
// Вставка локального фрагмента
//---
procedure  DrawInsFragment2;
var
  par     : PlacementParam; // Параметры расположения объекта
  pDefFrg : Reference;      // Указатель на описание параметров вставки фрагмента
  p       : Reference;      // Указатель объекта
begin
  // Определим фрагмент для вставки
  pDefFrg := 0;
  // Определим локальный фрагмент
  if( LocalFragmentDefinition( 'local' ) > 0 ) then
  begin
    // Нарисуем два отрезка и дугу
    LineSeg( 0, 0, 10, 0, 1 );
    LineSeg( 0, 0, 0, 10, 1 );
    ArcByPoint( 0, 0,   // Цетр дуги
                10,     // Радиус дуги
                10, 0,  // Точка на дуге
                0, 10,  // Точка на дуге
                -1,     // Направление отрисовки дуги
	  	          1 );    // Стиль отрисовки дуги
    // Завершение создания описания локального фрагмента
    pDefFrg := CloseLocalFragmentDefinition();
  end;

  if( pDefFrg > 0 ) then
  begin
    par.xBase := 30; // Координаты вставки фрагмента
    par.yBase := 40;
    par.ang   := 45; // Угол поворота
    par.scale := 2 ; // Масштаб
    // Создаем объект "вставка фрагмента"
    p := InsertFragment( pDefFrg,     // Указатель определения  фрагмента
                         0,           // Тип размещения по слоям 0 - на свои слои 1- в текущий слой
                         Addr(par) ); // Параметры привязки
    // Подсветить объект
    LightObj ( p, 1 );
    ksMessage( 'вставка локального фрагмента' );
    LightObj ( p, 0 );
  end;
end;

end.
