unit Step33;
//******************************************************************/
//*               (c)Акционерное общество АСКОН                    */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                  Работа с объектами системы                    */
//*                                                                */
//* 1.  Создать документ - WorkDocument                            */
//* 2.  Виды             - DrawView                                */
//* 3.  Слои             - DrawLayer                               */
//* 4.  Группы           - DrawGroup                               */
//* 5.  Именная группа   - WorkNameGroup                           */
//* 6.  Отрезки          - DrawLineSeg                             */
//* 7.  Дуги             - DrawArc                                 */
//* 8.  Линии            - DrawLine                                */
//* 9.  Окружности       - DrawCircle                              */
//* 10. Точки            - DrawPoint                               */
//* 11. Bezier-сплайны   - DrawBezier                              */
//* 12. Штриховка        - DrawHatch                               */
//* 13. Текст            - DrawText                                */
//*                                                                */
//******************************************************************/

interface
//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
  procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;

  procedure  WorkDocument;
  procedure  DrawView;
  procedure  DrawLayer;
  procedure  DrawGroup;
  procedure  WorkNameGroup;
  procedure  DrawLineSeg;
  procedure  DrawArc;
  procedure  DrawLine;
  procedure  DrawCircle;
  procedure  DrawPoint;
  procedure  DrawBezier;
  procedure  DrawHatch;
  procedure  DrawText;


implementation

  uses Windows,  Sysutils, LtDefine, LibTool, LDefin2D;

//----------------------------------------------------------------------------------------
// Задать идентификатор ресурсов
//---
function LIBRARYID : Cardinal;  pascal;
begin
  LIBRARYID := 100;
end;


//----------------------------------------------------------------------------------------
// Головная функция библиотеки
//---
procedure  LIBRARYENTRY( comm : Word  );  pascal;
begin
  if comm = 1 then
    WorkDocument()  // Cоздать документ
  else
    if ksGetCurrentDocument( 1 ) <> 0 then
      case comm of
        2:  DrawView();      // Виды
        3:  DrawLayer();     // Слои
        4:  DrawGroup();     // Группы
        5:  WorkNameGroup(); // Именная группа
        6:  DrawLineSeg();   // Отрезки
        7:  DrawArc();       // Дуги
        8:  DrawLine();      // Линии
        9:  DrawCircle();    // Окружности
        10: DrawPoint();     // Точки
        11: DrawBezier();    // Bezier-сплайны
        12: DrawHatch();     // Штриховка
        13: DrawText();      // Текст
      end; {case}
end;

//-------------------------------------------------------------------------------
//  работа с документом
//---
procedure WorkDocument;
var
  pDoc      : Reference;     // Указатель на документ
  doc, doc1 : DocumentParam; // Структура параметров документа
  par       : ViewParam;     // Структура параметров вида
  number    : Integer;       // Номер вида
  buf       : AnsiString;

begin

  // Заполнение структуры параментов документа
  FillChar( doc, SizeOf(doc), 0 );
  StrCopy( doc.fileName, 'c:\1.cdw' );        // Имя файла
  StrCopy( doc.comment,  'create document' ); // Комментарий к документу
  StrCopy( doc.author,   'user' );            // Автор документа
  doc.regim          := 0;                    // Режим ( 0 - видимый, 1 - слепой )
  doc._type          := lt_DocSheetStandart;  // Тип документа - чертеж стандартный
  // Структура параметров оформления документов ( параметры листа чертежа стандартного формата )
  doc.stPar.format   := 3;                    // Формат листа 0( А0 ) ... 4( А4 )
  doc.stPar.multiply := 1;                    // Кратность формата
  doc.stPar.direct   := 0;                    // Расположение штампа ( 0 - вдоль короткой стороны, 1 - вдоль длинной )
  doc.shtType        := 1;                    // Тип штампа из указанной библиотеки для спецификации ( номер стиля из указанной библиотеки )
  StrCopy( doc.layoutName,'');                // Имя библиотеки оформления (Graphic.lyt)
  // создали документ: лист, формат А3, горизонтально расположенный
  // и с системным штампом 1
  pDoc := CreateDocument( Addr(doc) );

  // Заполнение структуры параментов вида
  FillChar( par, SizeOf(par), 0 );
  par.x     := 10;                            // Точка привязки вида
  par.y     := 20;
  par.scale := 0.5;                           // Масштаб вида
  par.ang   := 45;                            // Угол поворота вида
  par.color := RGB( 10, 20, 10 );             // Цвет вида в активном состоянии
  par.state := stACTIVE;                      // Состояние вида
  StrCopy(par.name, 'user view');             // Имя вида

  //у документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр
  number    := 2;
  CreateSheetView( Addr(par), number );
  MessageBoxResult();
  // создадим слой с номером 5
  Layer( 5 );
  // Отрисовка отрезков
  LineSeg( 20, 10, 40, 10, 1 );
  LineSeg( 40, 10, 40, 30, 1 );
  LineSeg( 40, 30, 20, 30, 1 );
  LineSeg( 20, 30, 20, 10, 1 );

  ksMessage('нарисовали');

  //получить параметры документа
  GetObjParam( pDoc, Addr(doc1), sizeof(doc1), ALLPARAM );

  buf := Format('type=%d f=%d m=%d d=%d ,\nfileName = %s,'+ #13#10 +'comment = %s,'+ #13#10 +'author = %s', [doc1._type, doc1.stPar.format,
                 doc1.stPar.multiply, doc1.stPar.direct, doc1.fileName, doc1.comment, doc1.author] );

  ksMessage( PAnsiChar(buf) );

  //сохраним документ
  SaveDocument ( pDoc, '' );
  // закрыть документ
  //  CloseDocument( pDoc );

end;

//-------------------------------------------------------------------------------
// Создать вид
//---
procedure DrawView;
var
  par        : ViewParam; // Структура параметров вида
  v, p, gr   : Reference;
  number, st : Integer;
  buf        : AnsiString;
begin

  number    := 5;
  // Заполнение структуры параментов вида
  FillChar( par, SizeOf(par), 0 );
  par.x     := 10;                // Точка привязки вида
  par.y     := 20;
  par.scale := 0.5;               // Масштаб вида
  par.ang   := 45;                // Угол поворота вида
  par.color := RGB( 10, 20, 10 ); // Цвет вида в активном состоянии
  par.state := stACTIVE;          // Состояние вида
  StrCopy(par.name, 'user view'); // Имя вида

  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  gr := NewGroup( 0 );
    LineSeg( 20, 10, 20, 30, 1 );
    LineSeg( 20, 30, 40, 30, 1 );
    LineSeg( 40, 30, 40, 10, 1 );
    LineSeg( 40, 10, 20, 10, 1 );
  EndGroup(); // Завершить создание группы объектов

  //создали вид
  v := CreateSheetView( Addr(par), number);
  number := GetViewNumber(  v );
  buf := Format( 'создали вид ref=%d, number=%d', [v, number] );
  ksMessage( PAnsiChar(buf) );

  // Добавим вид в группу
  AddObjGroup(gr, v);
  ksMessage('добавили вид в группу');
  MessageBoxResult();   // Выдать сообщение об ошибке на экран

  p := LineSeg( 10, 10, 30, 30, 0 );
  AddObjGroup(gr, p);
  ksMessage('добавили эл в группу');

  //должно быть сообщение о повторном включении объекта в группу - вид уже включон
  MessageBoxResult();

  RotateObj( gr, 0, 0, -45 );

  //взять параметры вида
  FillChar( par, SizeOf(ViewParam), 0 );
  GetObjParam( v, Addr(par), SizeOf(ViewParam), ALLPARAM );
  buf:=Format( 'x=%4.1f y=%4.1f, angl=%4.1f name=%s st = %d', [par.x, par.y, par.ang,
                                                    par.name , par.state]);
  ksMessage( PAnsiChar(buf) );
  //сделать текущим системный вид( номер 0 )
  OpenView( 0 );
  //состояние  вида  : stREADONLY - только чтение
  st := stREADONLY;
  SetObjParam ( v, Addr(st), sizeof(st), VIEW_LAYER_STATE );
end;

//------------------------------------------------------------------------------
// Создать слой
//---
procedure DrawLayer;
var
  par, par1 : LayerParam; // Параметры слоя
  n, n1, st : Integer;
  lay, l    : Reference;
  buf       : AnsiString;
begin
  if  ReadInt('Введите номер слоя', 1, 0, 255, n ) = 0 then
    exit;
  //создаем слой, слой становится текущим
  lay := Layer( n );

  // Матрица преобразования координат ( 20 по оси OX, 15 по оси OY )
  Mtr( 20, 15, 0, 1 );
    LineSeg( -10,  0,  10,  0, 1 );
    LineSeg(  10,  0,  10, 20, 1 );
    LineSeg(  10, 20, -10, 20, 1 );
    LineSeg( -10, 20, -10,  0, 1 );
  DeleteMtr(); // Отключение матрицы преобразования координат

  //подсветить слой
  LightObj( lay, 1 );

  //получить номер слоя по указателю и указатель по номеру
  n1 := GetLayerNumber( lay );   // Получить номер слоя по указателю
  l  := GetLayerReference( n1 ); // Получить указатель слоя по номеру

  buf := Format( ' n=%d n1=%d layer=%d l=%d', [n, n1, lay, l] );
  ksMessage( PAnsiChar(buf) );

  // Получим параметры слоя
  GetObjParam( l, Addr(par), sizeof(par), ALLPARAM );
  // Запомним текущие параметры слоя в структуре
  Move( par,  par1, sizeof(par) );

  par.color := RGB( 0, 255, 0 );  // Цвет слоя в активном состоянии
  par.state := stACTIVE;          // Состояние слоя
  StrCopy( par.name, 'зеленый' ); // Имя слоя

  // Параметры текущего слоя изменить нельзя поэтому переключаемся на нулевой слой
  Layer(0);
  // Изменим параметры слоя
  if ( SetObjParam( l, Addr(par) , sizeof(par), ALLPARAM ) = 0 ) then
    MessageBoxResult()
  else
  begin
    // Получим новые параметры слоя
    GetObjParam( l, Addr(par), sizeof(par), ALLPARAM );
    buf:=Format( 'col=%d col1=%d name=%s name1=%s',  [par.color,
                                                      par1.color,
                                                      par.name,
                                                      par1.name] );
    ksMessage( PAnsiChar(buf) );
  end;
  LightObj( lay, 0 );

  // изменить состояние слоя
  st := stACTIVE ; // stCURRENT;
  SetObjParam( l, Addr(st),sizeof(st), VIEW_LAYER_STATE );

end;

//-------------------------------------------------------------------------------
// работа с группой
//---
procedure DrawGroup;
var
  p1,  p2,              // Указатели объектов
  gr1, gr2 : Reference; // Указатели групп

begin

  p1 := LineSeg( 10, 10, 20, 10, 0 ); // Первый отрезок
  p2 := LineSeg( 10, 10, 10, 20, 0 ); // Второй отрезок

  //создать модельную группу   1
  gr1 := NewGroup(0);
  EndGroup();

  //создать модельную группу   2
  gr2 := NewGroup(0);
  EndGroup();

  // Добавили объекты в первую группу
  AddObjGroup(gr1,p1);
  AddObjGroup(gr1,p2);

  // Добавили объекты во вторую группу
  AddObjGroup(gr2,p1);
  AddObjGroup(gr2,p2);

  ksMessage('создали группы');

  MoveObj( gr1, 10, 0 );
  ksMessage('сдвинули группу на 10 мм');

  RotateObj( gr2, 20, 10, 45 );
  ksMessage('повернули группу на 45 гр');

  RotateObj( gr2, 20, 10, -45 );
  ksMessage('повернули группу на -45 гр');

  MoveObj( gr1, -10, 0 );
  ksMessage('сдвинули группу на -10 мм');

  // очистили группу 2 ( объекты исключаются из группы )
  ClearGroup(gr2);
  //удалим  группу 2
  DeleteObj(gr2);


  LightObj(  gr1, 1 );
  ksMessage('подсветили gr');

  LightObj(  gr1, 0 );
  ksMessage('выключили gr');

  LightObj(  p1, 1 );
  ksMessage('подсветили el');
  LightObj(  p1, 0 );
  ksMessage('выключили el');

  //удалим  группу 1( объекты удалятся тоже )
  DeleteObj(gr1);
  MessageBoxResult();

end;

//-------------------------------------------------------------------------------
//  работа с именнованной группой
//-------------------------------------------------------------------------------
procedure WorkNameGroup;
var
  p,  c,               // Указатели объектов
  gr, gr1: Reference;  // Указатели групп

begin

  //рабочая группа сущестует до конца работы функции
  gr := NewGroup( 0 );
    p := LineSeg( 20, 20, 40, 20, 1 );
    LineSeg( 40, 20, 40, 40, 1 );
    LineSeg( 40, 40, 20, 40, 1 );
    LineSeg( 20, 40, 20, 20, 1 );
  EndGroup();

  // Сохранить группу объектов в модели с указанным именем
  // Группа автоматически сохраняется в чертеже при его записи
  // В противном случае группа действительна только в текущем сеансе работы
  // Если указатель группы равен нулю, то сохраняется группа селектирования
  // КОМПАС-ГРАФИК (выделенные объекты чертежа).
  if ( SaveGroup(  gr, 'group1' ) = 0 ) then
    exit;

  // Получим указатель на именнованную группу
  gr1 := GetGroup( 'group1' );
  if gr1 = 0 then
    exit;

  // Создание окружности
  c := Circle( 30, 30, 10, 1);
  AddObjGroup( gr1, c );

  LightObj( gr1, 1);
  ksMessage( 'добавили объект в именную группу' );
  LightObj( gr1, 0);

  ExcludeObjGroup( gr1, p );

  LightObj( gr1, 1);
  ksMessage( 'исключили объект из именной группы' );
  LightObj( gr1, 0);

end;

//-------------------------------------------------------------------------------
// создать отрезок
//---
procedure DrawLineSeg;
var
  par : LineSegParam; // Параметры отрезка
  p   : Reference;    // Указатель на отрезок
  t   : Integer;      // Тип объекта
  buf : AnsiString;
begin

  //построить отрезок
  //введем локальную систему ккординат
  Mtr( 30, 20, 45, 1 );
  p := LineSeg( 30, 20, // Координаты начальной точки
                60, 20, // Координаты конечной точки
                1 );    // Стиль линии

  //взять параметры отрезка
  FillChar( par, SizeOf(LineSegParam), 0 );
  t := GetObjParam( p, Addr(par), sizeof(par), ALLPARAM );

  buf := Format('t=%d, x1=%4.1f y1=%4.1f x2=%4.1f y2=%4.1f tl=%d',
                [t, par.x1, par.y1 ,par.x2, par.y2 , par.style]);
  ksMessage(PAnsiChar(buf));

  //заменить параметры отрезка
  par.x2    := 30;  // Координаты конечной точки
  par.y2    := 60;
  par.style :=  2;  // Стиль линии

  if SetObjParam( p, Addr(par), sizeof(par), ALLPARAM ) > 0   then
    ksMessage('Изменили объект')
  else
    MessageBoxResult();

  //отключить локальную систему координат
  DeleteMtr();
end;

//-------------------------------------------------------------------------------
// создать дугу
//--------------------------------------------------------------------------------
procedure DrawArc;
var
  par  : ArcParam;  // Параметры дуги по углам
  par1 : ArcParam1; // Параметры дуги по точкам
  p    : Reference; // Указатель объекта
  t    : Integer;   // Тип объекта
  buf  : AnsiString;
begin

  //построить дугу
  Mtr( 10, 10, 0, 1 );
  p := ArcByAngle( 30, 20,  // Координаты центра дуги
                   20,      // Радиус
                   45, 135, // Углы начальной и конечной узловых точек в градусах
                   1,       // Направление дуги ( +1 - против часовой стрелки, -1 - по часовой стрелке )
                   1 );     // Cтиль линии ( 1 - основная )

  //взять параметры дуги  по углам
  t := GetObjParam( p, Addr(par), sizeof(par), ANGLE_ARC_PARAM );
  MessageBoxResult();
  buf := Format( 't=%d, xc=%4.1f yc=%4.1f rad=%4.1f a1=%4.1f a2=%4.1f napr=%d tl=%d',
                 [t, par.xc, par.yc, par.rad, par.ang1 ,par.ang2, par.dir ,
                                        par.style ]);
  ksMessage(PAnsiChar(buf));

  //заменить параметры дуги по точкам
  FillChar( par1, SizeOf(ArcParam1), '0' );

  par1.xc   := 40;   // Координаты центра
  par1.yc   := 30;
  par1.rad  := 10;   // Радиус
  par1.x1   := 50;   // Начальная точка дуги
  par1.y1   := 30;
  par1.x2   := 40;   // Конечная точка дуги
  par1.y2   := 20;
  par1.dir  := 1;    // Направление построения дуги
  par1.style:= 2;    // Cтиль линии

  if( SetObjParam( p, Addr(par1), sizeof(par1), POINT_ARC_PARAM )>0 ) then
    ksMessage('Изменили объект')
  else
    MessageBoxResult();

  DeleteMtr();
end;

//-------------------------------------------------------------------------------
// создать вспомогательную линию
//---
procedure DrawLine;
var
  par : LineParam;  // Параметры отрезка
  p   : Reference;  // Указатель объекта
  t   : Integer;    // Тип объекта
  buf : AnsiString;
begin

  Mtr(0,0,45,1);
  //построить вспомогательную линию
  p := Line( 30, 20, 0 );

  //взять параметры вспомогательной линии

  t := GetObjParam( p, Addr(par), SizeOf(par), ALLPARAM );
  buf := Format( 't=%d, x=%4.1f y=%4.1f alf=%4.1f ',[t,
                             par.x, par.y, par.ang] );
  ksMessage(PAnsiChar(buf));

  //заменить параметры вспомогательной линии
  par.ang := 90;

  if( SetObjParam( p, Addr(par), SizeOf(par), ALLPARAM ) > 0  ) then
    ksMessage('Изменили линию')
  else
    MessageBoxResult();
  DeleteMtr();
end;

//-------------------------------------------------------------------------------
// создать окружность
//---
procedure DrawCircle;
var
  par : CircleParam; // Параметры окружности
  p   : Reference;   // Указатель объекта
  t   : Integer;     // Тип объекта
  buf : AnsiString;
begin

  Mtr(0,0,0,2);
  //построить окружность
  p := Circle( 30, 20, 10, 1 );

  //взять параметры олружности
  t := GetObjParam( p, Addr(par), SizeOf(par), ALLPARAM );
  buf := Format( 't=%d, xc=%4.1f yc=%4.1f rad=%4.1f tl=%d ',[t,
                             par.xc, par.yc, par.rad, par.style] );
  ksMessage(PAnsiChar(buf));

  //заменить параметры окружности
  par.rad   := 20;
  par.style := 2;
  if( SetObjParam( p, Addr(par), SizeOf(par), ALLPARAM ) > 0 ) then
    ksMessage( 'Изменили окружность' )
  else
    MessageBoxResult();
  DeleteMtr();
end;

//-------------------------------------------------------------------------------
// создать точку
//---
procedure DrawPoint;
var
  par :	PointParam;  // Параметры точки
  p   : Reference;   // Указатель объекта
  t   : Integer;     // Тип объекта
  buf : AnsiString;
begin

  Mtr( 10, 10, 0, 1 );
  //построить точку
  p := Point( 30, 40, 0 ); // 0 - точка
  Point( 40,  40, 1 );     // 1 - крестик
  Point( 50,  40, 2 );     // 2 - х-точка
  Point( 60,  40, 3 );     // 3 - квадрат
  Point( 70,  40, 4 );     // 4 - треугольник
  Point( 80,  40, 5 );     // 5 - окружность
  Point( 90,  40, 6 );     // 6 - звезда
  Point( 100, 40, 7 );     // 7 - перечеркнутый квадрат

  //взять параметры точки
  t := GetObjParam( p, Addr(par), SizeOf(par), ALLPARAM );
  buf := Format( ' t=%d, x=%4.1f y=%4.1f style=%d ',[t,
         	 par.x, par.y, par.style] );
  ksMessage(PAnsiChar(buf));

	//заменить параметры точки
  par.x     := 20;
  par.y     := 30;
  par.style := 7;

  if( SetObjParam( p, Addr(par), SizeOf(par), ALLPARAM ) > 0 ) then
    ksMessage( 'Изменили точку')
  else
    MessageBoxResult();
  DeleteMtr();

end;

//-------------------------------------------------------------------------------
// создать Bezier сплайн
//---
procedure DrawBezier;
type
  Double6 = array [0..5] of Double; // Массив из 6 элементов
var
  pPar : MathPointParam;            // Параметры точки (координаты)
  par  : BezierParam;               // Параметры Bezier сплайна
  p    : Reference;                 // Указатель объекта
  t, i : Integer;
  count: Integer;                   // Количество точек
  x,  y: Double6;                   // Массив координат точек кривой
  buf  : AnsiString;

begin

  x[0] := 0; x[1] := 20; x[2] := 50; x[3] := 70; x[4] := 100; x[5] :=  50;
  y[0] := 0; y[1] := 20; y[2] := 10; y[3] := 20; y[4] := 0;   y[5] := -50;

  //построить Bezier сплайн
  Bezier( 0, 1 );
  for  i:=0 to 4 do
    Point( x[i], y[i],0 );
  p := EndObj();

  //взять параметры Bezier сплайна
  par.pMathPoint := CreateArray( POINT_ARR, nil );         // Создать массив точек
  t := GetObjParam( p, Addr(par), sizeof(par), ALLPARAM ); // Получить параметры кривой
  count := GetArrayCount( par.pMathPoint );                // Количество точек
  buf :=Format( ' t=%d, count=%d close=%d tl=%d ',[t,
                 count, par.closed, par.style] );
  ksMessage(PAnsiChar(buf));
  for i:=0 to count-1 do
  begin
    GetArrayItem( par.pMathPoint, // указатель на массив
		              i,              // индекс в массиве
		              Addr(pPar),     // указатель на структуру элемента
		              SizeOf(pPar) ); // размер структуры элемента

    buf:=Format ( 'x[%d]=%4.1f y[%d]=%4.1f',
                  [i, pPar.x, i, pPar.y] );
    ksMessage(PAnsiChar(buf));
  end;


  //заменить параметры Bezier сплайна
  ClearArray( par.pMathPoint );   // Очистить массив точек
  //изменим значения точек
  for i:=0 to 5 do
  begin
    pPar.x := x[i];
    pPar.y := y[i];
    AddArrayItem( par.pMathPoint, // указатель на массив
 	                -1,             // индекс в массиве - в конец
 		              Addr(pPar),     // указатель на структуру элемента
		              SizeOf(pPar) ); // размер структуры элемента
  end;

  par.style  := 2;                // Изменить стиль линии
  par.closed := 1;                // Замкнуть Bezier сплайн

  // Установить новые параметры
  if( SetObjParam( p, Addr(par), sizeof(par), ALLPARAM ) >0 ) then
    ksMessage('Изменили объект')
  else
    MessageBoxResult();
  DeleteArray( par.pMathPoint );  // Удалить массив линий

end;

//-------------------------------------------------------------------------------
// создать штриховку
//---
procedure DrawHatch;
var
  par  : HatchParam; // Параметры штриховки
  p    : Reference;  // Указатель объекта
  t    : Integer;    // Тип
  buf  : AnsiString;
begin

  Mtr(30,20,0,0.5);

  //построить заштрихованный квадрат
  LineSeg ( 20, 30, 70, 30, 2 );
  LineSeg ( 70, 30, 70, 80, 2 );
  LineSeg ( 70, 80, 20, 80, 2 );
  LineSeg ( 20, 80, 20, 30, 2 );

  // Штриховка
  if ( Hatch( 0, 45, 2, 0, 0, 0 ) > 0 ) then
  begin
    LineSeg ( 20, 30, 70, 30, 2 );
    LineSeg ( 70, 30, 70, 80, 2 );
    LineSeg ( 70, 80, 20, 80, 2 );
    LineSeg ( 20, 80, 20, 30, 2 );
    p := EndObj();

    //взять параметры штриховки
    t := GetObjParam( p, Addr(par), sizeof(par), ALLPARAM );
    buf := Format(' t=%d, tip=%d angl=%4.1f shag=%4.1f width=%4.1f x0=%4.1f y0=%4.1f ',
              [t, par.style, par.ang, par.step, par.width, par.x, par.y ]);
    ksMessage(PAnsiChar(buf));
    DeleteMtr();

    Mtr( 0, 0, 0, 2 );

    //заменить параметры штриховки
    par.x := 0.8;

    if( SetObjParam( p, Addr(par), sizeof(par), ALLPARAM )>0 )then
      ksMessage('Изменили объект')
    else
      MessageBoxResult();

    DeleteMtr();
  end
  else
    MessageBoxResult;
end;

//------------------------------------------------------------------------------
// Текст
//---
procedure DrawText;
var
  par1  : TextParam;             // Параметры текста
  par2  : TextLineParam;         // Параметры строки
  par3  : TextItemParam;         // Параметры элемента строки
  par   : ParagraphParam;        // Параметры параграфа
  p     : Reference;             // Указатель на объект
  j,
  symbol: Integer;               // Номер спецзнака
  ch    : Cardinal;
  s     : Array [0..10] of AnsiChar;
  buf   : AnsiString;

  //----------------------------------------------------------------------------
  // Вывод параметров элементов строки
  procedure PrintPar1;
  var
    j, count   : integer;
  begin
    buf := Format('style=%d',  [par2.style] );
    ksMessage(PAnsiChar(buf));
    count := GetArrayCount( par2.pTextItem );
    for j:=0 to count-1 do
    begin
      GetArrayItem( par2.pTextItem, j, Addr(par3), SizeOf(TextItemParam));
      buf := Format('j=%d h=%5.1f  s=%s fontName=%s ', [j,par3.font.height,par3.s,
                                                       par3.font.fontName]);
      ksMessage(PAnsiChar(buf));
    end;
  end;

  //----------------------------------------------------------------------------
  // Вывод параметров строки
  procedure PrintPar;
  var
    i,count : integer;
  begin
    buf := Format( 'hFormat=%d vFormat=%d h=%4.1f w=%4.1f\n x=%4.1f y=%4.1f ang=%4.1f ', [par1.par.hFormat,
       par1.par.vFormat, par1.par.height, par1.par.width,par1.par.x,par1.par.y,par1.par.ang] );

    ksMessage(PAnsiChar(buf));
    count := GetArrayCount(par1.pTextLine);
    for  i:=0 to count-1 do
    begin
      GetArrayItem( par1.pTextLine , i, Addr(par2), sizeof(TextLineParam) );
      PrintPar1;
    end;
    MessageBoxResult();
  end;

begin

  par.style   := 0;       // Номер стиля текста (0 - стиль по умолчанию )
  par.x       := 30;      // Координаты точки привязки текста
  par.y       := 30;
  par.ang     := 0;       // Угол наклона текста
  par.hFormat := 0;       // Признак горизонтального форматирования ( 0 - нет форматирования,
                          // 1 - сужение текста, 2 - перенос на другую строку )
  par.vFormat := 0;       // признак вертикального форматирования ( 0 - нет форматирования,
                          // 1-изменение шага строк )
  par.height  := 25;      // Высота блока форматирования
  par.width   := 20;      // Ширина блока форматирования
  Paragraph( Addr(par) ); // Параграф

    // Пример задания дроби
    // Снятие наклона, по умолчанию включен
    TextLine( ITALIC_OFF, 0, nil, '' );
    // Пример задания дроби
    // Задание подстроки параграфа текста
    TextLine( NEW_LINE,  // Значения свойств, устанавливаемые двоичными флагами
              0,         // Тип свойства
              nil,       // Указатель на значение свойства
              'Дробь' ); // Строка
    // Числитель, наклон, высота дроби в 1.5 раза меньше высоты текста
    j := 2;  // Значение свойства FRACTION_TYPE

    TextLine( NUMERATOR, FRACTION_TYPE, Addr(j), '111' );
    // Знаменатель, утолщение
    TextLine( DENOMINATOR or BOLD_ON, 0, nil, '222' );
    // Конец дроби, снятие утолщения, снятие наклона и текст после дроби
    TextLine( END_FRACTION or BOLD_OFF or ITALIC_OFF, 0, nil, '333' );

    // Пример задания дроби, нижнего и верхнего отклонения
    TextLine( NEW_LINE, 0, nil, 'Дробь и отклонения ' );
    // Числитель, наклон
    TextLine( NUMERATOR or ITALIC_ON, 0, nil, '111 ' );
    // Базвая строка для отклонения
    TextLine( S_BASE, 0, nil, '222' );
    // Верхнее отклонение
    TextLine( S_UPPER_INDEX, 0, nil, 'Верх' );
    // Нижнее отклонение
    TextLine( S_LOWER_INDEX, 0, nil, 'Низ' );
    // Конец отклонения
    TextLine( S_END, 0, nil, ' 333' );
    // Знаменатель, утолщение
    TextLine( DENOMINATOR, 0, nil, '444' );
    // Конец дроби, снятие утолщения, снятие наклона и текст после дроби
    TextLine( END_FRACTION or BOLD_OFF or ITALIC_OFF, 0, nil, ' 555' );

    // Пример задания спецсимвола
    TextLine( NEW_LINE, 0, nil, 'Спецсимвол ' );
    symbol := 65; // Номер спецзнака - шероховатость
    // Спецзнак
    TextLine( SPECIAL_SYMBOL, SPECIAL, @symbol, '' );
    // Конец спецсимвола и текст после спецзнака
    TextLine( SPECIAL_SYMBOL_END, 0, nil, ' 111' );

    // Пример задания символа из сушествующего шрифта
    TextLine( NEW_LINE, 0, nil, 'Шрифт Arial ' );
    ch := 64; // Номер символа из шрифта - @
    StrCopy (s, 'Arial');
    // Задания символа из Arial
    TextLine( FONT_SYMBOL, FONT_NAME, Addr(s), PAnsiChar(ch) );

  // Описание параграфа заканчивается функцией EndObj, возвращающей указатель на созданный объект
  p := EndObj;

  // Возьмем параметры текста
  GetObjParam( p, Addr(par1), SizeOf(par1), ALLPARAM  );
//  PrintPar();

  // В параметрах текста задействованы два массива неопределенной длины :
  par1.pTextLine := CreateArray( TEXT_LINE_ARR, nil );  // Массив по строкам
  par2.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );  // Массив по компонентам строки

  //возьмем параметры 1 -ой строки ( индекс 0 )
  GetObjParam( p, Addr(par2), SizeOf(par2), 0 );

  PrintPar1();

  if( YesNo( 'Изменять параметры текста ?' ) = 1 ) then
  begin
    // У первой строки отключаем ITALIC и BOLD и меняем цвет
    // Для этого получим параметры первой строки
    GetArrayItem( par2.pTextItem, 0, Addr(par3), sizeof(TextItemParam));
    // Устновим уталщенный наклонный шрифт
    par3.font.bitVector := par3.font.bitVector or ITALIC_OFF or BOLD_OFF;
    // Установим цвет красный
    par3.font.color := RGB( 255,0,0 );
    // Установим новые параметры
    SetArrayItem( par2.pTextItem, 0, Addr(par3), sizeof(TextItemParam));
    // Заменим у текста первую строку
    SetObjParam( p, Addr(par2), sizeof(par2), 0 );
    //возьмем параметры 1 -ой строки ( индекс 0 )  для проверки
    GetObjParam( p, Addr(par2), sizeof(par2), 0 );
    PrintPar1();
  end;

end;

end.
