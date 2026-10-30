unit Step55;
//*****************************************************************************/
//*                   (c)Акционерное общество АСКОН                           */
//*                    Санкт-Петербург, 1991, 1996                            */
//*                     Компас-Мастер  версия 5.x                             */
//*****************************************************************************/
//*                           Приемы работы                                   */
//*                        Редактироваеие объекта                             */
//* 1.  Трансформация объекта по матрице        - DrawTransform               */
//* 2.  Копирование объекта                     - DrawCopy                    */
//* 3.  Симметрия объекта                       - DrawSymmetry                */
//* 4.  Редактирование допуска формы            - EditTolerance               */
//* 5.  Редактирование таблицы                  - EditTable                   */
//* 6.  Взять тексты граф и редактировать штамп - EditStamp                   */
//* 7.  Получить текст ТТ                       - GetTextTT                   */
//* 8.  Редактирование техничеческих требований - ChangeTechnicalDemand       */
//* 9.  Вставка фрагмента                       - ShowInsertFragment          */
//* 10. Работа с библиотекой фрагментов         - EditFragmentLibrary         */
//* 11. Вставка фрагмента россыпью              - ShowInsertFragment1         */
//* 12. Редактирование таблиц                   - EditTable1                  */
//* 13. Редактирование допуска формы            - EditTolerance1              */
//*                                                                           */
//*****************************************************************************/
interface

uses  Windows, Sysutils, LtDefine, LibTool, LDefin2D;

procedure LIBRARYENTRY( comm: WORD  ); Pascal;
function  LIBRARYID : Cardinal; Pascal;

//------------------------------------------------------------------------------
// Описания используемых функций
// ---
procedure  DrawTransform;
procedure  DrawCopy;
procedure  DrawSymmetry;
procedure  EditTolerance;
procedure  EditTable;
procedure  EditStamp;
procedure  GetTextTT;
procedure  ShowInsertFragment;
procedure  EditFragmentLibrary;
procedure  ShowInsertFragment1;
procedure  ChangeTechnicalDemand;
procedure  EditTable1;
procedure  EditTolerance1;

implementation

//------------------------------------------------------------------------------
// Идентификатор библиотеки
//---
function LIBRARYID: Cardinal; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// Головная функция библиотеки
//---
procedure LIBRARYENTRY( comm : Word ); pascal;
begin

  case comm of
     1: DrawTransform();          // Трансформация объекта по матрице
     2: DrawCopy();               // Копирование объекта
     3: DrawSymmetry();           // Симметрия объекта
     4: EditTolerance();          // Редактирование допуска формы
     5: EditTable();              // Редактирование таблицы
     6: EditStamp();              // Взять тексты граф и редактировать штамп
     7: GetTextTT();              // Получить текст ТТ
     8: ShowInsertFragment();     // Вставка фрагмента
     9: EditFragmentLibrary();    // Работа с библиотекой фрагментов
    10: ShowInsertFragment1 ();   // Вставка фрагмента россыпью
    11: ChangeTechnicalDemand (); // Редактирование техничеческих требований
    12: EditTable1();             // Редактирование таблицы
    13: EditTolerance1();         // Редактирование допуска формы
  end; {case}

end;

//------------------------------------------------------------------------------
// Трансформация объектов
//---
procedure DrawTransform();
var
  ref : Reference; // Указатель группы
begin

  //трансформация  рабочей группы
  Mtr( -30, -30, 0, 1 );
    // Создать группу
    ref := NewGroup(0);            // 0 - Постоянная группа
      LineSeg( 30, 30, 60, 30, 1);
      LineSeg( 60, 30, 60, 60, 1);
      LineSeg( 60, 60, 30, 60, 1);
      LineSeg( 30, 60, 30, 30, 1);
      // Штриховка
      Hatch( 0, 45, 2, 0, 0, 0 );
        LineSeg( 30, 30, 60, 30, 1);
        LineSeg( 60, 30, 60, 60, 1);
        LineSeg( 60, 60, 30, 60, 1);
        LineSeg( 30, 60, 30, 30, 1);
      EndObj();

    EndGroup();
  DeleteMtr();

  // Трансформация  простых объектов
  // ref =  ArcBy3Points( 20, 60, 40, 70, 20, 80, 1 );

  // Трансформация вида 1 должен быть создан
  // ref := GetViewReference( 1 );
  // if( ref = 0 ) then
  // begin
  //   MessageBoxResult();
  //   exit;
  // end;

  // Трансформация слоя 1 должен быть создан
  // ref := GetLayerReference( 1 );
  // if(ref = 0) then
  // begin
  //   MessageBoxResult();
  //   exit;
  // end;

  // Трансформация группы селектирования
  // ref := 0;

  ksMessage('Cоздали матрицу 20, 20, 45, 2');

  Mtr( 20, 20, 45, 2 );        // Создать матрицу
                               // cмещение x = 20, y = 20
                               // угол поворота = 45
                               // масштаб = 2
    TransformObj( ref );       // Трансформация
  DeleteMtr();                 // Удалить матрицу

  MessageBoxResult();          // Результат
  ksMessage('Вернем обратно');

  Mtr(-20, -20, 0, 1 );        // Cмещение x = -20, y = -20
    TransformObj( ref );
  DeleteMtr();

  Mtr(0, 0, 0, 0.5 );          // Масштаб = 0.5
    TransformObj( ref );
  DeleteMtr();

  Mtr(0, 0, -45, 1 );          // Угол поворота = 45
    TransformObj( ref );
  DeleteMtr();

  MessageBoxResult();          // Результат

end;

//------------------------------------------------------------------------------
// Пример использования  копии объектов
//---
procedure DrawCopy;
var
  par    : ViewParam; // Параметры вида
  v      : Reference; // Указатель
  number : Integer;   // Номер вида
begin

  number    := 5;                   // Номер вида

  par.x     := 20;                  // Смещение
  par.y     := 60;
  par.scale := 1;                   // Масштаб
  par.ang   := 0;                   // Угол
  par.color := RGB( 10, 20, 10 );   // Цвет
  par.state := stACTIVE;            // Состояние - активный
  StrCopy( par.name, 'user view' ); // Имя вида

  // Cоздали вид
  v := CreateSheetView( Addr(par), number );
  // Cоздали слой
  Layer( 5 );

  // Нарисуем несколько отрезков
  LineSeg( 20, 10, 20, 30, 1 );
  LineSeg( 20, 30, 40, 30, 1 );
  LineSeg( 40, 30, 40, 10, 1 );
  LineSeg( 40, 10, 20, 10, 1 );

  // Копируем вид ( для вида точки задаются в листовых координатах )
  CopyObj( v, 20, 60, 40, 80, 1, 0 );

end;

//------------------------------------------------------------------------------
// Пример использования симметрии  объектов
//---
procedure DrawSymmetry;
var
  grp : Reference; // Указатель группы

begin
  // Создание группы с использованием симметрии. Так как при использовании орерации
  // Симметрии группа не закрыта, объекты созданные в результате симметрии попадают в
  // группу. В результате группа будет состоять из 8 объектов
  grp := NewGroup( 0 );
    LineSeg( 20, 10, 20, 30, 1 );
    LineSeg( 20, 30, 40, 30, 1 );
    LineSeg( 40, 30, 40, 10, 1 );
    LineSeg( 40, 10, 20, 10, 1 );
    SymmetryObj( grp, 40, 10, 40, 20, 1 ); // Симетрия группы
  EndGroup();

  // Подсветить группу
  LightObj( grp, 1 );
    MessageBoxResult();
  LightObj( grp, 0 );

end;

//------------------------------------------------------------------------------
// пример редактирования допуска формы
//---
procedure   EditTolerance;
var
  par      : ToleranceParam; // Параметры допуска формы
  par1     : TextLineParam;  // Параметры строчки текста
  par3     : TextItemParam;  // Параметры элемента строки
  info     : RequestInfo;    // Параметры процесса
  pObj     : Reference;      // Указатель объекта
  x, y     : Double;         // Координаты
  j, _type : Integer;
  numb     : Cardinal;
  count    : Integer;
  buf      : AnsiString;
begin

  // Очищаем структуру
  FillChar( info, sizeof(info), 0 );

  info.prompt := 'Укажите допуск формы';         // Приглашение
  j := ksCursor( Addr(info), x ,y, nil );        // Процесс указания объекта
  if ( j <> 0 ) then
  begin
    pObj := FindObj( x, y, ksGetCursorLimit() );
    if ( ExistObj(pObj) > 0  ) then              // Если объект найден
    begin

      _type := GetObjParam( pObj, nil, 0, 0 );   // Узнаем тип объекта
      if ( _type = TOLERANCE_OBJ ) then          // Если найденный объект допуск формы
      begin
        // Открыть допуск формы для редактирования
        ksOpenTolerance( pObj );

          // Получить параметры допуска формы
          GetObjParam(  pObj,                   // Указатель на графический объект
                      Addr(par),                // Указатель на структуру параметров
                      SizeOf( ToleranceParam ), // Размер структуры параметров
                      ALLPARAM );               // Тип считывания параметров

          buf := Format( 'базовая точка=%d стиль=%d расположение-%d x=%5.1f y=%5.1f',
                         [ par.tBase, par.style, par._type, par.x, par.y ] );
          ksMessage(PAnsiChar(buf));

          // В цикле будем брать все существующие ячейки
          while ( ksGetToleranceColumnText( numb, Addr(par1) ) <> 0 ) do
          begin
            buf := Format( 'numb =%d', [numb] );        // Номер ячейки
            ksMessage( PAnsiChar(buf) );

            buf := Format( 'style=%d ', [par1.style] ); // Стиль
            ksMessage( PAnsiChar(buf) );

            count := GetArrayCount( par1.pTextItem );   // Количество элементов в строке

            for  j := 0 to count-1 do
            begin
              // Получить параметры строки
              GetArrayItem( par1.pTextItem, j, Addr(par3), SizeOf(TextItemParam) );
              if ( par3.tip = 0 ) then // Если
                buf := Format( 'Компонента=%d h=%5.1f s=%s fontName=%s битвектор =%d',
                              [ j, par3.font.height, par3.s, par3.font.fontName, par3.font.bitVector] )
              else
                buf := Format( 'Компонента=%d тип = %d номер спецзнака=%d',
                              [ j, par3.tip, par3.iSNumb] );
              ksMessage( PAnsiChar(buf) );
            end;
            DeleteArray( par1.pTextItem );  // Очистим массив компонент
          end;

          // Заменим параметры
          par.x := par.x + 10;
          par.y := par.y + 10;
          SetObjParam(  pObj,                      // Указатель на графический объект
                        Addr(par),                 // Указатель на структуру параметров
                        SizeOf( ToleranceParam  ), // Размер структуры параметров
                        ALLPARAM );                // Тип считывания параметров

          // Заменим текст второй ячейки
          ColumnNumber( 2 );
          TextLine( NEW_LINE, 0, nil, 'вторая ячейка' );

          ksDivideTableItem( 3, 1, 2 );        // Разделить ячейку 3 тонкой вертикальной линией

          // Заполним ячейку 4
          ColumnNumber( 4 );
          TextLine(NEW_LINE, 0, nil, '4' );

          // ksSetTableBorderStyle( 1, 2, 1 ); // Установить стиль вехней границы ячейки 1 на основной
          // ksClearTableColumnText( 0 );      // Очистить таблицу допуска формы
        EndObj();                              // Закрыли объект "допуск формы"

      end else
        Error( 'Это не допуск формы');
    end else
      Error( 'Нет объекта');
  end;
end;

//------------------------------------------------------------------------------
// Пример редактирования таблицы
//---
procedure EditTable;
var
  par          : TextParam;     // Параметры текста
  par2         : TextLineParam; // Параметры строки
  par3         : TextItemParam; // Параметры элемента строки
  pObj, p      : Reference;     // Указатели на объект и на текст
  info         : RequestInfo;   // Параметры процесса
  x, y         : Double;        // Координаты точки
  numb         : Cardinal;      // Номер ячейки
  j, _type, i  : Integer;
  count, count1: Integer;
  buf          : AnsiString;

begin

  // Очищаем структуру
  FillChar( info, sizeof(info), 0 );
  info.prompt := 'Укажите таблицу';              // Приглашение

  // Указать таблицу на чертеже
  j := ksCursor( Addr(info), x, y, nil );        // Процесс указания объекта
  if ( j <> 0 ) then
  begin
    pObj := FindObj( x, y, ksGetCursorLimit() ); // Найти объект
    if( ExistObj(pObj) > 0 ) then                // Если объект найден
    begin

      _type := GetObjParam( pObj, nil, 0, 0 );   // Узнаем тип объекта
      // Проверить полученный объкет - таблица
      if ( _type = TABLE_OBJ ) then
      begin

        // Открыть таблицу для редактирования
        ksOpenTable( pObj );

          // В цикле будем брать все существующие ячейки
          while  ksGetTableColumnText( numb, Addr(par) ) <> 0  do
          begin

            buf := Format( 'numb =%d', [numb] );
            ksMessage( PAnsiChar(buf) );

            p     := par.pTextLine;                // Указатель массива строк
            count := GetArrayCount(p);             // Количество строк

            for i:=0 to count-1 do
            begin
              // Получить параметры строки
              GetArrayItem( p , i, Addr(par2), SizeOf(TextLineParam) );
              buf := Format( 'i =%d style=%d', [i, par2.style] );
              ksMessage(PAnsiChar(buf));

              count1 := GetArrayCount( par2.pTextItem ); // Количество элементов в строке
              for j:=0 to count1-1 do
              begin
                // Получить параметры элемента строки
                GetArrayItem( par2.pTextItem, j, Addr(par3), SizeOf(TextItemParam) );
                if ( par3.tip = 0 ) then
                  buf := Format( 'компонента=%d h=%5.1f s=%s fontName=%s битвектор =%d',
                                [ j, par3.font.height, par3.s, par3.font.fontName, par3.font.bitVector ] )
                else
                  buf := Format( 'компонента=%d тип = %d номер спецзнака=%d',
                                [ j, par3.tip, par3.iSNumb ] );
                ksMessage( PAnsiChar(buf) );
              end;
              DeleteArray( par2.pTextItem ); // Очистим массив компонент
              par2.pTextItem := 0;
            end;
            // Очистим массив текстовых строк
            DeleteArray( p );
            par.pTextLine := 0;
          end;

          // Редактируем ячейку 2
          ColumnNumber( 2 );
          ksText( 0, 0, 0, 5, 1 , 0, 'Вторая ячейка' );

          ksDivideTableItem( 3, 1, 2 );        // Разделить ячейку 3 тонкой вертикальной линией

          // Редактируем ячейку 4
          ColumnNumber( 4 );
          ksText( 0, 0, 0, 5, 1 , 0, '4' );

          // ksSetTableBorderStyle( 1, 2, 1 ); // Установить стиль вехней границы ячейки 1 на основной
          // ksClearTableColumnText( 0 );      // Очистить таблицу допуска формы

        EndObj; // Закрыли объект "таблица"
      end else
        Error( 'Это не таблица');
    end else
      Error( 'Нет объекта');
  end;
end;

//------------------------------------------------------------------------------
// Пример взять тексты граф и редактировать штамп
//---
procedure EditStamp;
var
  par1  : TextLineParam; // Параметры строки
  par2  : TextItemParam; // Параметры элемента строки
  numb  : Cardinal;      // Номер ячейки штампа
  p     : Reference;     // Указатель на массив текста
  count : Integer;
  count1, i, j : Integer;
  buf   : AnsiString;
begin
  // Открыть штамп на редактирование
  if ( OpenStamp > 0 ) then
  begin
    // В цикле будем брать все существующие графы
    p := GetStampColumnText( numb );       // Получить текст ячейки
    while ( p <> 0 ) do
    begin

      buf := Format( 'numb =%d', [numb] ); // Номер ячейки
      ksMessage( PAnsiChar(buf) );

      count := GetArrayCount(p);           // Количество строк
      for i := 0  to count - 1 do
      begin
        // Получить параметры строки текста
        GetArrayItem( p, i, Addr(par1), SizeOf(TextLineParam) );
        buf := Format( 'i =%d style=%d', [i, par1.style] );
        ksMessage( PAnsiChar(buf) );

        count1 := GetArrayCount( par1.pTextItem ); // Количество элементов строки
        for j := 0 to count1 - 1 do
        begin
          // Параметры элемента строки
          GetArrayItem( par1.pTextItem, j, Addr(par2), SizeOf(TextItemParam) );
          buf := Format( 'Компонента=%d h=%5.1f s=%s fontName=%s',
                       [ j, par2.font.height, par2.s, par2.font.fontName ]);
          ksMessage( PAnsiChar(buf) );
        end;
        DeleteArray( par1.pTextItem );  // Очистим массив компонент
        par1.pTextItem := 0;
      end;
      // Очистим массив текстовых строк
      DeleteArray( p );
      p := GetStampColumnText( numb );   // Получить следующий текст
    end;
    // Заменим графу 2
    ColumnNumber( 2 );
    TextLine( NEW_LINE, 0, nil, 'Графа 2' );
    // ClearStamp( 0 );  // Очистить штамп
    CloseStamp();        // Закрыть штамп
  end else
    Error ( 'Штамп не найден' );
end;

//------------------------------------------------------------------------------
//  Получить текст ТТ
//---
procedure GetTextTT;
var
  par       : TechnicalDemandParam;
  par2      : TextLineParam;
  par3      : TextItemParam;
  pTT       : Reference;
  pTextLine : reference;
  count, count1, count2 : integer;
  i, i1, j  : integer;
  buf       : AnsiString;
begin
  //получим указатель на технические трбования
  pTT := GetReferenceDocumentPart( 1 );
  if ( pTT > 0) then
  begin

    //получим параметры описания ТТ
    GetObjParam( pTT, Addr(par), SizeOf(par), TECHNICAL_DEMAND_PAR );
    count := GetArrayCount( par.pGab );
    buf := Format('стиль =%d число страниц  TT =%d',[par.style,count]);
    ksMessage(PAnsiChar(buf));
    // создадим массив текстовых строк
    pTextLine := CreateArray( TEXT_LINE_ARR, nil ) ;
    //пройдемся по листам ТТ и получим текст
    for  i := 0 to count-1 do
    begin
      GetObjParam( pTT, Addr(pTextLine), sizeof(reference), i );
      count1 := GetArrayCount(pTextLine);
      for i1:=0 to count1-1 do
      begin
        GetArrayItem( pTextLine, i1, Addr(par2), SizeOf(TextLineParam) );
        buf := Format( 'компонента =%d style=%d', [i1, par2.style] );
        ksMessage(PAnsiChar(buf));
        count2 := GetArrayCount( par2.pTextItem );
        for j:=0 to count2-1 do
        begin
          GetArrayItem( par2.pTextItem, j, Addr(par3), SizeOf(TextItemParam));
          buf := Format( 'компонента=%d h=%5.1f s=%s fontName=%s',[j,par3.font.height,par3.s,
                    par3.font.fontName]);
          ksMessage(PAnsiChar(buf));
        end;
        DeleteArray( par2.pTextItem );  //очистим массив компонент
        par2.pTextItem := 0;
      end;
      //очистим массив текстовых строк
    end;
    DeleteArray( pTextLine );
    pTextLine := 0;
  end;
end;

//--------------------------------------------------------------------------------
// Функция выбора и простановки в текущий документ вставки фрагмента из библиотки
// фрагментов
//---
procedure ShowInsertFragment;
var
  par          : PlacementParam;         // Параметры размещения
  libName, buf : array [0..250] of AnsiChar; // Имя библиотеки фрагментов и имя фрагмента
  insertName   : PAnsiChar;                  // Имя вставки
  x, y         : Double;                 // Координаты точки
  rub          : Phantom;                // Фантом
  pDefFrg      : Reference;              // Указатель на параметры вставки фрагмента
  p            : Reference;              // Указатель на объект
  j1, j        : Integer;
begin
  // Выберем библиотеку фрагментов
  if( ksChoiceFile( '*.lfr','Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|', libName, 250, 0 ) > 0 ) then
  begin
    repeat
      // Выбрать фрагмент в библиотеке фрагментов
      j1 := ksChoiceFragmentFromLib( libName, buf, 250 );
      if ( j1 <> 0 ) then
      begin
        // Выделим имя вставки
        insertName := StrPos( buf, '|' );
        if ( insertName <> nil ) then
        begin
          //подготовим структуры фанома и запросов для Placement
          rub.type1.xBase := 0;
          rub.type1.yBase := 0;
          rub.type1.scale := 1;
          rub.phType      := 1;


          // Создадим описание всавки фрагментов
          pDefFrg := FragmentDefinition( buf,            // Имя файла фрагмента
                                         insertName + 1, // Имя вставки
                                         1 );            // Тип вставки -действителен для внешнего фрагмента
                                                         // 0- взять в документ, 1-внешней ссылкой

          if( pDefFrg > 0) then
          begin
            // Во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
            rub.type1.gr    := NewGroup( 1 );       // Временная группа

              par.xBase := 0;
              par.yBase := 0;
              par.ang   := 0;
              par.scale := 1 ;
              // Создаем объект "вставка фрагмента"
              p := InsertFragment( pDefFrg,         // Указатель определения  фрагмента
                                   0,               // Тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                   Addr(par) );     // Параметры привязки

            EndGroup();

            repeat
              rub.type1.ang  := 0;
              // Указать точку вставки и угол поворота
              j := Placement( nil, x, y, rub.type1.ang, Addr(rub) );
              if ( j <> 0 ) then
              begin
                CopyObj( p,                   // Указатель на графический объект
                         0, 0,                // Базовая точка объекта
                         x, y,                // Точка куда копировать
                         1, rub.type1.ang  ); // Масштаб и угол поворота а градусах
              end;
            until( j = 0 );

            DeleteObj( rub.type1.gr );        // Удалить группу

          end else
            Error( 'Ошика создания описания вставки фрагмента' );
        end else
          Error( 'Имя вставки не определено' );
      end;
    until( j1 = 0 );
  end;
end;

//------------------------------------------------------------------------------
// Пример работы с библиотекарем фрагментов
//---
procedure  EditFragmentLibrary;
var
  info    : RequestInfo;            // Рапаметры приглашения
  libName : array [0..250] of AnsiChar; // Имя библиотеки
  nameFrg : AnsiString;                 // Имя фрагмента
  typeEdit: Integer;                // Тип редактирования
  j       : Integer;
  buf     : array [0..250] of AnsiChar;
begin
  // Выберем библиотеку фрагментов
  if ( ksChoiceFile( '*.lfr', 'Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|', libName, 255, 0 ) > 0 ) then
  begin
    typeEdit := 0;
    FillChar( info, sizeof(info), 0 );
    info.commands := '!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент'; // Команды
    repeat
      j := CommandWindow( Addr(info) );                         // Создать меню команд

      case j of

        1 : begin  // !Новый_фрагмент
              if ( ReadString( 'Введите имя нового фрагмента',  // Cтрока приглашения
                               buf,                             // Возвращаемая строка
                               250 ) > 0 ) then                 // Допустимая длина строки
              begin
                nameFrg   := libName;
                if ( buf[0] <> '|' ) then
                  nameFrg := nameFrg + '|';
                nameFrg   := nameFrg + buf;
                typeEdit  := 2;                                  // Запустить на редактирование
              end
              else
                typeEdit  := 0;
            end;

        2 : begin // Редактировать_фрагмент
            if  ksChoiceFragmentFromLib( libName, buf, 250 ) <> 0  then
            begin
              nameFrg  := buf;
              typeEdit := j;   // 2- запустить на редактирование, 3-удалить;
            end
            else
              typeEdit := 0;
           end;

        3 : begin //Удалить_фрагмент
              // Выберем имя файла фрагмента
              if  ksChoiceFragmentFromLib( libName, buf, 250 ) <> 0  then
              begin
                nameFrg  := buf;
                typeEdit := j;   // 2- запустить на редактирование, 3-удалить;
              end
              else
                typeEdit := 0;
            end;

      end;

      if ( j > 0) And (typeEdit > 0) then
      begin
        if ( ksFragmentLibrary( PAnsiChar(nameFrg), typeEdit ) > 0 ) then
        begin
          if ( typeEdit = 2 ) then
          begin
            ksFragmentLibrary( PAnsiChar(nameFrg), 4 { Минимизировать окно библиотекаря } );
            // Редактируем фрагмент из библиотеки
            ksText( 0, 100, // Точка привязки текста
                    0,      // Угол наклона текста
                    5,      // Высота текста
                    1,      // Сужение текста
                    0,	    // Свойства строки, которые задаются вкл.-выкл.
                    'Редактируем фрагмент из библиотеки' );   // Строка символов

            LineSeg( 0, 100, 110, 100, 1 );
            // Редактируем фрагмент в интерактивном режиме
            // После выбора в меню "Сервис" команды "Закончить редактирование фрагмента",
            // Возвращаемся в библиотеку
            SystemControlStart( 'Закончить редактирование фрагмента' );
            ksFragmentLibrary( PAnsiChar(nameFrg), 0 { Закрыть c сохранением } );
          end;
        end else
          MessageBoxResult;          // Результат работы
      end;
    until( j = -1 );
  end;
end;

//------------------------------------------------------------------------------
//  Вставка фрагмента россыпью
//---
procedure ShowInsertFragment1;
var
  par     : PlacementParam;          // Парметры размещения
  frwName : array [0..250] of AnsiChar;  // Имя фрагмента
  x, y    : Double;                  // координаты точки
  rub     : Phantom;                 // Фантом
  j1, j   : Integer;

begin
  repeat
    // Выберем  фрагмент
    j1 := ksChoiceFile( '*.frw','фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|', frwName, 250, 1);
    if( j1 <> 0 ) then
    begin

      //подготовим структуры фанома и запросов для Placement
      rub.type1.xBase := 0;
      rub.type1.yBase := 0;
      rub.type1.scale := 1;
      rub.phType      := 1;
      rub.type1.ang   := 0;
      //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов

      par.xBase := 0;
      par.yBase := 0;
      par.ang   := 0;
      par.scale := 1 ;
      repeat
        // Если нужно вставить несколько фрагментов, группу лучше создать новую,
        // так как вместе с геометрией могут придти атрибуты, объекты спецификации, стили,
        // которые связаны с геометрией. При простом копировании группы эта связь будет
        // потеряна.
        rub.type1.gr := ksReadFragmentToGroup( frwName,     // Имя фрагмента
                                               0,           // Тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                               Addr(par) ); // Параметры привязки
        // Если фрагмент считан
        if rub.type1.gr > 0 then
        begin
          // Указываем точку вставки и угол поворота фрагмента
          j := Placement( nil, x, y, rub.type1.ang, Addr(rub) );
          if ( j <> 0 ) then
          begin
            // Сдвигаем группу
            MoveObj( rub.type1.gr, x, y );
            //поворачиваем группу
            if( Abs(rub.type1.ang) > 0.001 ) then
               RotateObj( rub.type1.gr, x, y, rub.type1.ang ); // Повернуть группу
            // Ставим группу в модель
            StoreTmpGroup( rub.type1.gr );
            ClearGroup( rub.type1.gr );                        // Очистить группу
            DeleteObj( rub.type1.gr );                         // Удалить группу
          end;
        end
        else begin
          if ( rub.type1.gr > 0 ) then
            DeleteObj( rub.type1.gr );                         // Удалить группу
          j := 0;
        end;

      until( j = 0 );
    end;
  until( j1 = 0 );
end;

//----------------------------------------------------------------------------------------
// Редактирование техничеческих требований
//---
procedure ChangeTechnicalDemand;
var
  par     : TechnicalDemandParam; // Параметры технических требований
  parLine : TextLineParam;        // Параметры строки
  parItem : TextItemParam;        // Параметры элементов строки
  pTT     : Reference;            // Указатель тех-требований
  buf     : AnsiString;
  i, j, itemCount : Integer;
begin
  // Если активен 2D документ
  if ( ksGetCurrentDocument( 1 ) > 0 ) then
  begin
    // Получим указатель на технические трбования
    pTT := GetReferenceDocumentPart( 1 );
    if ( pTT > 0 ) then
    begin
      // Получим параметры описания ТТ
      GetObjParam( pTT, Addr(par), SizeOf(par), TECHNICAL_DEMAND_PAR );
      buf := Format( 'число строк TT =%d', [par.strCount] );
      ksMessage( PAnsiChar(buf) );
      // Открываем ТТ на редактирование
      // ТТ должны быть открыты, чтобы менять тексты
      OpenTechnicalDemand( par.pGab,    // Динамический массив листов технических требований или 0
                           par.style ); // Стиль текста для технических требований если 0 - умолчательное значение

      // Пройдемся по ТТ и получим текст
      for i := 0 to par.strCount-1 do
      begin
        // Получить параметры строки
        GetObjParam( pTT, Addr(parLine), SizeOf(TextLineParam), TT_FIRST_STR+i );
        itemCount := GetArrayCount( parLine.pTextItem );
        for j := 0 to itemCount-1 do
        begin
          // Получить параметры элемента строки
          GetArrayItem( parLine.pTextItem, j, Addr(parItem), SizeOf(TextItemParam) );
          StrCat( parItem.s, '!!!'); // Изменить текст
          // Установить новый текст
          SetArrayItem( parLine.pTextItem, j, Addr(parItem), SizeOf(TextItemParam) );
          ksMessage( parItem.s );
        end;
        // Установить параметры строки текста
        SetObjParam( pTT, Addr(parLine), sizeof(TextLineParam), TT_FIRST_STR+i );
      end;
      // Закрываем ТТ
      CloseTechnicalDemand();
    end else
      Error( 'ТТ отсутствуют' );

  end else
    Error( 'Документ должен быть листом' );
end;

//--------------------------------------------------------------------------------
// Пример редактирования таблицы
//---
procedure EditTable1;
var
  par       : TextParam;     // Параметры текста
  linePar   : TextLineParam;
  itemPar   : TextItemParam;
  info      : RequestInfo;
  x, y      : Double;
  _type     : Integer;
  numb      : Cardinal;
  pObj      : Reference;
  p         : Reference;
  count,  i : Integer;
  count1, j : Integer;
  comm      : Integer;
begin
  // Редактирование таблицы
  FillChar( info, sizeof(info), 0 );
  info.prompt := 'Укажите таблицу';
  // Взять таблицу на чертеже
  comm := ksCursor( Addr(info), x ,y, nil );
  if ( comm <> 0 ) then
  begin
    pObj := FindObj( x, y, 100000 );
    if ( ExistObj(pObj) > 0 ) then
    begin
      // Узнаем тип объекта
      _type := GetObjParam(  pObj, nil, 0, 0 ); // Указатель на графический объект
      // Проверить полученный объкет - таблица
      if ( _type = TABLE_OBJ ) then
      begin
        // Открыть таблицу для редактирования
        ksOpenTable( pObj );
        // В цикле будем брать все существующие ячейки
        while ksGetTableColumnText( numb, Addr(par) ) <> 0  do
        begin
          p := par.pTextLine;          // Массив текста
          count := GetArrayCount(p);   // Количество элементов
          for i := 0 to count - 1 do
          begin
            GetArrayItem( p , i, Addr(linePar), sizeof(TextLineParam) );
            count1 := GetArrayCount( linePar.pTextItem );
            for j := 0 to count1 - 1 do
            begin

              GetArrayItem( linePar.pTextItem, j, Addr(itemPar), sizeof(TextItemParam) );
              if ( StrLen( itemPar.s ) > 0) then
              begin
                StrCat( itemPar.s, '!!!' );
                SetArrayItem( linePar.pTextItem, j, Addr(itemPar), SizeOf(TextItemParam) );
              end;
            end;
            SetArrayItem( p, i, Addr(linePar), SizeOf(TextLineParam) );
          end;
          //очистим массив текстовых строк
          ksSetTableColumnText( numb, Addr(par) );
        end; // while
        EndObj();//закрыли объект "таблица"
      end else
        Error( 'это не таблица' );
    end else
      Error( 'нет объекта' );
  end;
end;
//--------------------------------------------------------------------------------
// пример редактирования допуска формы
//---------------------------------------------------------------------------------
procedure   EditTolerance1;
var
  pObj   : reference;
  info   : RequestInfo  ;
  x, y   : double ;
  comm   : integer;
  _type  : integer;
  numb   : Cardinal;
  linePar: TextLineParam ;
  itemPar: TextItemParam ;
  count1,j: integer;
//--------------------------------------------------------------------------------

begin
   FillChar( info, sizeof(info), 0 );
  // редактирование допуска формы
  info.prompt := 'Укажите допуск формы';
  comm := ksCursor( Addr(info), x ,y, nil );
  if ( comm <> 0 ) then
  begin
    pObj := FindObj( x, y, 1000. );
    if( ExistObj(pObj)> 0 )then
    begin
      //узнаем тип объекта
      _type := GetObjParam(  pObj, nil, 0, 0);   //указатель на графический объект
      if ( _type = TOLERANCE_OBJ ) then
      begin
        //открыть допуск формы для редактирования
        ksOpenTolerance( pObj );

        //в цикле будем брать все существующие ячейки
        while ( ksGetToleranceColumnText( numb, Addr(linePar) )<>0) do
        begin
          count1 := GetArrayCount( linePar.pTextItem );
          for j:=0 to count1-1 do
          begin
            GetArrayItem( linePar.pTextItem, j, Addr(itemPar), SizeOf(TextItemParam));
            if ( Strlen( itemPar.s ) > 0) then
            begin
              StrCat( itemPar.s, '!!!' );
              SetArrayItem( linePar.pTextItem, j, Addr(itemPar), SizeOf(TextItemParam));
            end;
          end;
          ksSetToleranceColumnText( numb, Addr(linePar) );
        end;
        EndObj();//закрыли объект "допуск формы"
      end else
        Error( 'это не допуск формы' );
    end else
      Error( 'нет объекта' );
  end;
end;

end.
