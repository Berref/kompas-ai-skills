unit Step44;
//******************************************************************/
//*                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                       Приемы работы                            */
//*                                                                */
//* 1. Работа с БД                           - DrawTxtDB           */
//* 2. Процессы Cursor и Placement           - DrawRectCallBack,   */
//*                                            DrawRectNULL        */
//*                                          - <step4_1.pas>       */
//* 3. Ввод длинного целого                  - EnterInteger        */
//* 4. Выбор имени файла                     - SelectFileName      */
//* 5. Записать слайд                        - WriteSlideStep      */
//* 6. Отрисовать слайд                      - TestShowDialog      */
//*                                          - <step4_2.pas>       */
//* 7. Пример с обработкой очереди сообщений - TaskAccess          */
//* 8. Относительный путь файла              - WorkRelativePath    */
//* 9. Работа с системными каталогами        - WorkSystemPath      */
//*                                                                */
//******************************************************************/

interface

  procedure LIBRARYENTRY( comm: WORD  ); Pascal;
  function  LIBRARYID   : Cardinal;      Pascal;

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
  procedure DrawTxtDB;
  procedure EnterInteger;
  procedure ChoiceFileName;
  procedure TestPumpWaitingMessages;
  procedure WorkSystemPath;
  procedure WorkRelativePath;
  procedure WriteSlideStep;

implementation

uses Windows,  Sysutils, LtDefine, LibTool, step4_1, LibDB, LDefin2D;

//----------------------------------------------------------------------------------------
// Идентификатор библиотеки
//---
function LIBRARYID : Cardinal;  pascal;
begin
  LIBRARYID := 100;
end;

//----------------------------------------------------------------------------------------
// Головная функция библиотеки
//---
procedure  LIBRARYENTRY( comm : Word ); pascal;
begin
  case comm of
   1:  DrawTxtDB();             // Работа с БД
   2:  begin                    // Placement, Cursor  (описание в файле step4_1.pas )
       if ( YesNo('Вызывать функцию CallBack?') = 1 ) then
         DrawRectCallBack()
       else
         DrawRectNULL();
       end;
   3:  EnterInteger;            // Ввод длинного целого
   4:  ChoiceFileName;          // Выбор имени файла
   5:  begin                    // Отрисовать битмар
//       TestDrawBitmap;
       end;
   6:  WriteSlideStep();        // Пример записи слайда
   7:  begin                    // Отрисовать слайд
//        TestShowDialog();
       end;
   9:  TestPumpWaitingMessages; // Пример с обработкой очереди сообщений
   10: WorkRelativePath;        // Работа с относительными путями файлов
   11: WorkSystemPath;          // Работа с системными каталогами
  end; {case}
end;

//-------------------------------------------------------------------------------
// Ввод целого числа
//---
procedure EnterInteger;
var
  h1  : LongInt; // Буфер для числа
  buf : AnsiString;
begin
  // Ввод числа из диапазона -100000..100000
  // Начальное значение 10000
  if ( ReadLong( 'Ввести индекс', 10000, -100000, 100000, h1 ) > 0 ) then
  begin
    buf := Format( 'h = %d', [h1] );
    ksMessage( PAnsiChar(buf) );
  end
  else
    ksMessage( 'отказ' );
end;

//------------------------------------------------------------------------------
// Выбор файла
//---
procedure ChoiceFileName;
var
  name : array [0..255] of AnsiChar;
  size : Cardinal;
begin
  // Выбор файла
  size := ksChoiceFile( '*.cdw',
                        'Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|',
                        name, 255, 1);
  if ( size > 0 ) then
    ksMessage(name)
  else
    ksMessage('Отказ');
end;

//------------------------------------------------------------------------------
// Обработка очереди сообщений
//---
procedure TestPumpWaitingMessages;
var
  i, j : Integer;

begin
  EnableTaskAccess( 0 ); // Запретили доступ к задаче
  for  i:=0 to 10000 do
  begin
    LineSeg( 0, i, 20, i, 1 );
    j := i div 100;
    if j <> 0 then
    begin
      // Посылаем необрабатываемое сообщение своему приложению
      // Для выполнения процесса в фоновом режиме
      PostThreadMessage( GetCurrentThreadId(), 0, 0, 0 );
      PumpWaitingMessages(); // Через каждые 100 отрезков обрабатываем очередь сообщений
                             // При этом Windows получает возможность выполнить свои
                             // действия, например переключиться на другую задачу
    end;
  end;
  EnableTaskAccess( 1 ); // Разрешили доступ к задаче
end;

//------------------------------------------------------------------------------
//  Работа с текстовой базой данных
//  Данные сформированы в виде таблицы обнородных строк, колонки
//  разделены  пробелами или запятыми.
//---
procedure DrawTxtDB;
type
  // Пользовательская структура
  UserData = record
    dr, l : Double;
    f     : SmallInt;
  end;

  // Пользовательская структура 1
  UserData1 = record
    d     : Double;
    l     : Double;
  end;

var
  name :array [0..255] of AnsiChar; // Имя файла базы данных
  s   : array [0..22]  of AnsiChar; // Буфер для строки
  bd,                           // Указатель базы данных
  r1, r2, r3 : Reference;       // Отношения
  tmpD: UserData1;              // Пользовательская структура
  b   : UserData;               // Пользовательская структура
  i :  Integer;
  buf : AnsiString;
begin
  // Выбор базы данных для чтения
  if ( ksChoiceFile( '*.loa','Базы данных(*.loa)|*.loa|Все файлы (*.*)|*.*|', name, 255, 0 ) > 0 ) then
  begin
    // Создать объект, обслуживающий базу данных
    bd := CreateDB('TXT_DB');
    // Связать объект базы с определенной базой данных( для текстового файла - имя файла )
    if ( ConnectDB( bd, name) > 0 ) then
    begin
      // Создать отношение - буфер для считывания информации из таблицы
      // В нашем случае это два double и один int; при этом не важно сколько колонок
      // в базе, важно чтобы их было >= описанных в Relation
      r1 := Relation( bd );
        RDouble( 'dr' );// Имена даются ключевым колонкам,
        RDouble( 'L' ); // По ним в дальнейшем формируются условия выборки
        RInt ('');
      EndRelation();
      // Создать еще одно отношения для считывания поля в виде строки
      // У базы данных отношений может быть сколько угодно
      r2 := Relation( bd );
        RChar( 'L', 20, 0 ); // Считать строку (максимальная длина строки 20 символов)
      EndRelation();

      // Установить запрос - отношение связывается с базой
      // Указываем какие колонки базы связать с переменными буфера
      DoStatement( bd, r1, '1 2 3' ); // Колонка dr - 1, L - 2, оставшаяся колонка -3
                                      // (если связываются последовательно все колонки
                                      // текстовой базы, то допускается посылать
                                      // пустую строку -"" )

      DoStatement( bd, r2, '2' );     // Строку буфера связать со 2 колонкой базы

      // Умолчательное условие выборки все строки
      // ConditionTxt(   bd, r1, "Index1000 = 2" ); // Считать строку 2
      i := 1;
      while( i > 0 ) do
      begin
        i := ReadRecord( bd, r1, Addr(b) ); // Считать очередную порцию информации и положть в структуру b
        if ( i > 0 ) then
        begin
          buf := Format( 'dr=%4.1f l=%4.1f f=%d', [b.dr, b.l, b.f] );
          ksMessage( PAnsiChar(buf) );
        end;
      end;
      ksMessage( 'Закончили чтение' );
      i := 1;
      while ( i > 0 ) do
      begin
        i := ReadRecord( bd, r2, Addr(s) ); // Cчитать строку
        if i > 0 then
          ksMessage( s );
      end;
      ksMessage( 'Закончили чтение' );
      // Создадим еще одно отношение
      r3 := Relation( bd );
        RDouble( ''  );
        RDouble( 'L' );
      EndRelation;
      // Установим запрос
      DoStatement( bd, r3, '1 2' );
      // Определим запрос (считать все строки у которых в колонке L лежит 100 или 120
      Condition(   bd, r3, 'L=100 || L=120' ); // Создать запрос
      i := 1;
      while ( i > 0 ) do
      begin
        i := ReadRecord( bd, r3, Addr(tmpD) ); // Чтение строки
        if ( i > 0 ) then
        begin
          buf := Format( 'd=%4.1f ', [ tmpD.d]);
          ksMessage( PAnsiChar(buf));
        end;
      end;
    end;
    // Удалить обьект, обслуживающий базу данных
    // Рассоединение базы с файлом, удаление отношений произойдет автоматически
    DeleteDB( bd );
  end;
end;

//------------------------------------------------------------------------------
// Выделенную группу селектирования записать в слайд( во внешний текстовый файл )
//---
procedure WriteSlideStep;
var
  info    : RequestInfo;            // Параметры запроса
  x, y    : double;                 // Координаты
  name    : array [0..255] of AnsiChar; // Имя
  slideID : integer;                // Идентификатор слайда

begin
  // Выберем файл для записи
  if ( ksSaveFile( '*.rc', nil, nil, name, 255, 0 ) > 0 )  then
  begin
     info.commands := 'Укажите точку привязки слайда'; // Команда

     info.title        := nil; // Строка или идентификатор строки заголовка окна
     info.prompt       := nil; // Строка или идентификатор приглашения
     info.cursor       := nil; // Строка с именем или идентификатор стандартного курсора
     info.callBack     := nil; // Указатель на функцию обратной связи
     info._dynamic     := 0;   // Признак динамического запроса 1-динамический запрос, 0-статический
     info.commInstance := 0;   // Instance модуля, в ктором размещен состав команд

     // Точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
     if ( ksCursor( Addr(info), x, y, nil ) <> 0 ) then
     begin
       if ( ReadInt( 'Введите идентификатор слайда', 100, 0, 32000, slideID ) > 0 ) then
       begin
         // Запись слайда
         if (WriteSlide( name, slideID, x,  y  ) = 0 ) then
           Error('Группа селектирования пуста');
         ClearGroup(0);        // Снять селектирование
       end;
     end;
  end;
end;


//---------------------------------------------------------------------------------
// Работа с относительными путями файлов
//---
procedure WorkRelativePath;
var
  mainName : array [0..255] of AnsiChar; // Полный путь к задающему файлу
  fileName : array [0..255] of AnsiChar; // Полный путь к требуемому файлу
  relName  : array [0..255] of AnsiChar; // Относительный путь
  fullName : array [0..255] of AnsiChar; // Полный путь к требуемому файлу
  mess     : AnsiString;

begin
  // Имя задающего файла
  if ( ksChoiceFile( '*.*', 'Все файлы (*.*)|*.*|', mainName, 255, 0 ) > 0 ) then
  begin
    if ( ksChoiceFile( '*.*', 'Все файлы (*.*)|*.*|', fileName, 250, 0 ) > 0 ) then
    begin
      //относительный путь
      ksGetRelativePathFromFullPath( mainName, // Полный путь к задающему файлу
                                     fileName, // Полный путь к требуемому файлу
                                     relName,  // (Результат) относительный путь к требуемому файлу( без общей с задающим файлом части пути )
                                     250 );    // Размер буффера

      mess := 'Задающий файл : ';
      mess := mess + mainName;
      ksMessage( PAnsiChar(mess) );
      mess := 'Полный путь : ';
      mess := mess + fileName;
      ksMessage( PAnsiChar(mess) );

      mess := 'Относительный путь : ';
      mess := mess + relName ;
      ksMessage( PAnsiChar(mess) );

      //полный путь
      ksGetFullPathFromRelativePath( mainName, // Полный путь к задающему файлу
                                     relName,  // Относительный путь к требуемому файлу( без общей с задающим файлом части пути )
                                     fullName, // (Результат) полный путь к требуемому файлу
                                     250 );    // Размер буффера

      mess := 'Задающий файл : ';
      mess := mess + mainName;
      ksMessage( PAnsiChar(mess) );
      mess := 'Относительный путь : ';
      mess := mess + relName ;
      ksMessage( PAnsiChar(mess) );
      mess := 'Полный путь : ';
      mess := mess + fullName;
      ksMessage( PAnsiChar(mess) );

    end;
  end;
end;

//------------------------------------------------------------------------------
// Работа с системными каталогами
//---
procedure  WorkSystemPath;
var
  info          : RequestInfo;             // Параметры процесса
  typeCatalog,j : Integer;                 // Тип каталога
  fileName      : array [0..255] of AnsiChar;  // Имя файла
  buf           : PAnsiChar;                   // Указатель буфера
  mess          : AnsiString;                  // Сообщение
  relName       : array [0..255] of AnsiChar;  // Каталог
  catalogName   : array [0..5]   of PAnsiChar; // Назначение каталога

begin
  catalogName[0] := 'каталог системных файлов';
  catalogName[1] := 'каталог библиотек'       ;
  catalogName[2] := 'каталог временных файлов';
  catalogName[3] := 'каталог конфигурации'    ;
  catalogName[4] := 'INI-файл';

  // Сформировать полный путь к заданному файлу
  info.cursor       := nil; // Строка с именем или идентификатор стандартного курсора
  info.callBack     := nil; // Указатель на функцию обратной связи
  info._dynamic     := 0;   // Признак динамического запроса 1-динамический запрос, 0-статический
  info.commInstance := 0;   // Instance модуля, в ктором размещен состав команд

  // Заголовок окна команд
  info.title    := 'Каталоги файлов системы ';
  // Список команд через !
  info.commands := '!Системные !Библиотеки !Временные !Конфигурация !INI-файл';
  // Приглашение
  info.prompt   := 'Выберите нужный каталог';
  buf           := 'user.ttt';

  repeat
    j := CommandWindow( Addr(info) );        // Окно команд
    if ( j > 0 ) then
    begin
      case j of
        2 :  typeCatalog := sptLIBS_FILES;   // Относительно каталога файлов библиотек
        3 :  typeCatalog := sptTEMP_FILES;   // Относительно каталога сохранения временных файлов
        4 :  typeCatalog := sptCONFIG_FILES; // Относительно каталога сохранения конфигурации системы
        5 :  typeCatalog := sptINI_FILE;     // Относительно полного имени INI-файла системы
        else typeCatalog := sptSYSTEM_FILES; // Относительно каталога системных файлов
      end;
      //полный путь
      ksGetFullPathFromSystemPath( buf ,          // Относительный путь к файлу( без системного пути )
                                   fileName,      // (Результат) полный путь к файлу
                                   250,           // Размер буффера
                                   typeCatalog ); // Путь установленного типа см. ksSystemPath
      mess := 'Полный путь к файлу user.ttt - ';
      mess := mess + catalogName[j -1];
      mess := mess + ' : ';
      mess := mess + fileName ;
      ksMessage( PAnsiChar(mess) );

      //относительный путь
      ksGetRelativePathFromSystemPath( fileName,      // Полный путь к файлу
                                       relName,       // (Результат) относительный путь к файлу( без системного пути )
                                       250,           // Размер буффера
                                       typeCatalog ); // Путь установленного типа см. ksSystemPath
     mess := 'Относительный путь к файлу ';
     mess := mess + fileName;
     mess := mess + catalogName[j -1];
     mess := mess + ' : ';
     mess := mess + relName;
     ksMessage( PAnsiChar(mess) );

    end;
  until ( j = -1 );
end;

end.
