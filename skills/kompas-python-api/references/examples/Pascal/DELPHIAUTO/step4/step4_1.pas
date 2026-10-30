unit step4_1;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
uses
  Windows,
  SysUtils,
  LDefin2D,
  ksConstTLB,
  ksAuto,
  Classes,
  Forms,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

  procedure LIBRARYENTRY( command: WORD  ); Pascal;
  function  LIBRARYID : Cardinal; Pascal;
  function  CallBackProcPlacement( comm : Integer; var x, y, ang : Double; rInfo, rPhan : PIDispatch;
                               _dynamic : Integer ) : Integer; stdcall;
  function CallBackProcCursor( comm     : Integer; var x, y : Double; rInfo, rPhan : PIDispatch;
                              _dynamic  : Integer ) : Integer; stdcall;
implementation
uses
  step4_3; {TestSlideDlg}

var
  kompas : KompasObject;
  doc    : ksDocument2D;
  _type, flag : integer;

//-------------------------------------------------------------------------------
//
// ---
procedure TestShowDialog;
var
  dlg : TTestSlideDlg;
begin
  Forms.Application.Handle := kompas.ksGetHWindow;
  kompas.ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
	// создаем диалог - хендл окна компаса не нужен, вижал сам разбирается
	dlg        := TTestSlideDlg.Create( Forms.Application );
  dlg.doc    := doc;
  dlg.kompas := kompas;
  dlg.ShowModal;                    // вывод диалога
	kompas.ksEnableTaskAccess( 1 ); // открыть доступ к компасу
  Forms.Application.Handle := 0;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawTxtDB;
type
userData = record
 dr, l :   double ;
 f     : SmallInt;
end;
userData1 = record
 d  :   double;
 l  :   double;
end;

var
  bd, r1, r2, r3 : reference;
  i              : Integer;
  buf            : string;
  libName        : string;
  con            : userData1;
  b              : userData;
  data           : ksDataBaseObject;
  par            : ksUserParam;
  item           : ksLtVariant;
  arr            : ksDynamicArray;

begin
  i := 1;
	data := ksDataBaseObject( kompas.DataBaseObject );
  par  := ksUserParam( kompas.GetParamStruct(ko_UserParam) );
  item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
	arr  := ksDynamicArray( kompas.GetDynamicArray(LTVARIANT_ARR) );
  if ( (par = nil) Or (item = nil) Or (data = nil) Or (arr = nil) ) then
		Exit;
	par.Init;
	par.SetUserArray( arr );
	item.Init;
	  item.doubleVal := 0;
	  arr.ksAddArrayItem( -1, item );
	item.Init;
  	item.doubleVal := 0;
		arr.ksAddArrayItem( -1, item );
  item.Init;
	  item.intVal := 0;
	  arr.ksAddArrayItem( -1, item );

	libName := kompas.ksChoiceFile( '*.loa', 'Базы данных(*.loa)|*.loa|Все файлы (*.*)|*.*|', True );
  if ( libName <> '' ) then begin
    bd := data.ksCreateDB( 'TXT_DB' ); // создать объект, обслуживающий базу данных
    // связать объект базы с определенной базой данных( для текстового файла - имя файла )
    if ( data.ksConnectDB(bd, libName) <> 0 ) then begin
      r1 := data.ksRelation( bd );     // создать отношение - буфер для считывания информации из таблицы
        data.ksRDouble( 'dr' );        // имена даются ключевым колонкам,
        data.ksRDouble( 'L'  );        // по ним в дальнейшем формируются условия выборки
				data.ksRInt   ( ''   );
      data.ksEndRelation;

      // установить запрос - отношение связывается с базой( указываем какие колонки
      // базы связать с переменными буфера )
      data.ksDoStatement( bd, r1, '1 2 3' );   // колонка dr - 1, L - 2, оставшаяся колонка -3
      while i <> 0 do begin
        i := data.ksReadRecord( bd, r1, par ); // считать очередную порцию информации и положть в структуру b
        if ( i <> 0 ) then begin
  				arr.ksGetArrayItem( 0, item );
					b.dr := item.doubleVal;
	  			arr.ksGetArrayItem( 1, item );
					b.l := item.doubleVal;
	  			arr.ksGetArrayItem( 2, item );
					b.f := item.intVal;
          buf := Format( 'DR = %g, L = %g, F = %d', [b.dr, b.l, b.f] );
          kompas.ksMessage( buf );
        end;
      end;
      kompas.ksMessage( 'end' );

			i := 1;
			arr.ksClearArray;
      item.Init;
	      item.strVal := '';
			  arr.ksAddArrayItem( -1, item );
      r2 := data.ksRelation( bd );       // создать отношение - буфер для считывания информации из таблицы
 				data.ksRChar( '', 255, 0 );
      data.ksEndRelation;

      data.ksDoStatement( bd, r2, '2' ); // установить запрос - отношение связывается с базой( указываем какие колонки
      while i <> 0 do begin
        i := data.ksReadRecord( bd, r2, par ); // считать очередную порцию информации и положть в структуру b
        if ( i <> 0 ) then begin
 					arr.ksGetArrayItem( 0, item );
					buf := Format( 'L = %s', [item.strVal] );
					kompas.ksMessage( buf );
        end;
      end;
      kompas.ksMessage( 'end' );

			i := 1;

			arr.ksClearArray;
      item.Init;
	      item.doubleVal := 0;
			  arr.ksAddArrayItem( -1, item );
      item.Init;
	      item.doubleVal := 0;
			  arr.ksAddArrayItem( -1, item );
      r3 := data.ksRelation( bd ); // создать отношение - буфер для считывания информации из таблицы
 				data.ksRDouble( ''  );
				data.ksRDouble( 'L' );
      data.ksEndRelation;

      data.ksDoStatement( bd, r3, '1 2' ); // установить запрос - отношение связывается с базой( указываем какие колонки
			data.ksCondition( bd, r3, 'L=100 || L=150' );
      while i <> 0 do begin
        i := data.ksReadRecord( bd, r3, par ); // считать очередную порцию информации и положть в структуру b
        if ( i <> 0 ) then begin
 					arr.ksGetArrayItem( 0, item );
          con.d := item.doubleVal;
					arr.ksGetArrayItem( 1, item );
					con.l := item.doubleVal;
					buf := Format( 'dr = %g, L = %g', [con.d, con.l] );
					kompas.ksMessage( buf );
        end;
      end;
      kompas.ksMessage( 'end' );
    end;
    data.ksDeleteDB( bd ); //удалить обьект, обслуживающий базу данных
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure WriteSlideStep;
var
  name    : string;
  info    : ksRequestInfo;
	x, y    : Double;
	slideID : LongInt;
begin
  //выберем файл для записи
  name := kompas.ksSaveFile( '*.rc', '', '', false );
	if ( name <> '' ) then begin
	  info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
		if ( info <> nil ) then begin
			info.Init;
			info.commandsString := 'Укажите точку привязки слайда';
	    // точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
			if ( doc.ksCursor(info, x, y, Nil) <> 0 ) then begin
				if ( kompas.ksReadInt('Введите идентификатор слайда', 100, 0, 32000, slideID) <> 0 ) then begin
					if ( kompas.ksWriteSlide(name, slideID, x,  y) = 0 ) then
						kompas.ksError( 'Группа селектирования пуста' );
					doc.ksClearGroup( 0, true );
				end;
      end;
    end;
  end;
end;

//---------------------------------------------------------------------------------
// Работа с относительными путями файлов
//----------------------------------------------------------------------------------
procedure WorkRelativePath;
var
  mainName, fileName, relName, fullName, mess : string;
begin
  //имя задающего файла
	mainName := kompas.ksChoiceFile( '*.*', 'Все файлы (*.*)|*.*|', true );
	fileName := kompas.ksChoiceFile( '*.*', 'Все файлы (*.*)|*.*|', true );
	if ( (mainName <> '') Or (fileName <> '') ) then begin
    // относительный путь
		relName := kompas.ksGetRelativePathFromFullPath( mainName,  // полный путь к задающему файлу
																										fileName ); // полный путь к требуемому файлу

		mess := 'Задающий файл : ' + mainName + #13;
    mess := mess + 'Полный путь : ' + fileName + #13;
    mess := mess + 'Относительный путь : ' + relName;
		kompas.ksMessage( mess );

    // полный путь
		fullName := kompas.ksGetFullPathFromRelativePath( mainName,  // полный путь к задающему файлу
																											relName ); // относительный путь к требуемому файлу( без общей с задающим файлом части пути )
    mess := 'Задающий файл : ' + mainName + #13;
    mess := mess + 'Относительный путь : ' + relName + #13;
    mess := mess + 'Полный путь : ' + fullName;
		kompas.ksMessage( mess );
	end;
end;

//---------------------------------------------------------------------------------
// Работа с системными каталогами
//----------------------------------------------------------------------------------
procedure WorkSystemPath;
var
  catalogName    : array [0..5] of pChar;
  info           : ksRequestInfo;
  j, typeCatalog : Integer;
  buf            : PChar;
  fileName, mess, relName : string;
begin
  catalogName[0]  := 'каталог системных файлов';
  catalogName[1]  := 'каталог библиотек'       ;
  catalogName[2]  := 'каталог временных файлов';
  catalogName[3]  := 'каталог конфигурации'    ;
  catalogName[4]  := 'INI-файл' ;

  // сформировать  полный путь к заданному файлу
  info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if ( info <> nil ) then begin
		info.Init;
		info.title          := 'Каталоги файлов системы';
		info.commandsString := '!Системные !Библиотеки !Временные !Конфигурация !INI-файл ';
		info.prompt         := 'Выберите нужный каталог';
		buf                 := 'user.ttt';
		repeat
			j := doc.ksCommandWindow( info );
			if ( j > 0 ) then begin
        typeCatalog := 0;
				case j of
					1 : typeCatalog := sptSYSTEM_FILES; // Относительно каталога системных файлов
					2 : typeCatalog := sptLIBS_FILES  ; // Относительно каталога файлов библиотек
					3 : typeCatalog := sptTEMP_FILES  ; // Относительно каталога сохранения временных файлов
					4 : typeCatalog := sptCONFIG_FILES; // Относительно каталога сохранения конфигурации системы
					5 : typeCatalog := sptINI_FILE    ; // Относительно полного имени INI-файла системы
        end;
				//полный путь
				fileName := kompas.ksGetFullPathFromSystemPath( buf,           // относительный путь к файлу( без системного пути )
																		                    typeCatalog ); // путь установленного типа см. ksSystemPath
				mess := 'Полный путь к файлу user.ttt ' + #13 + catalogName[j - 1] + ' :' + #13 + fileName;
				kompas.ksMessage( mess );

				//относительный путь
				relName := kompas.ksGetRelativePathFromSystemPath( fileName,      // полный путь к файлу
																		                       typeCatalog ); // путь установленного типа см. ksSystemPath
				mess := 'Относительный путь к файлу ' + #13 + fileName + #13 + catalogName[j -1] + ' :' + #13 + relName;
				kompas.ksMessage( mess );
			end;
		until j <= 0;
	end;
end;

//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
function CallBackProcCursor( comm : Integer; var x, y : Double; rInfo, rPhan : PIDispatch;
                             _dynamic : Integer ) : Integer;  stdcall; Export;
var
  info : ksRequestInfo;
  phan : ksPhantom;
  t1   : ksType1;
begin
	info := ksRequestInfo( rInfo );
	phan := ksPhantom( rPhan );
	if ( (info <> nil) And (phan <> nil) ) then begin
		t1 := ksType1( phan.GetPhantomParam );
		case comm of
			1, 2  : _type := comm;
			-1    : begin // поставить в модель
                doc.ksMoveObj( t1.gr, x, y );
                if ( Abs(t1.Angle) > 0.001 ) then
                  doc.ksRotateObj( t1.gr, x, y, t1.Angle );
                doc.ksStoreTmpGroup( t1.gr );
                doc.ksClearGroup( t1.gr, true );
              end;
		end;
// группа для фантома должна быть временная и обновляться при изменении вида отрисовки
		if ( t1.gr <> 0 ) then
			doc.ksDeleteObj( t1.gr );
		t1.gr := doc.ksNewGroup( 1 );   // временная группа

		if ( ((flag = 1) And (comm = 1)) Or ((flag = 2) And (comm = 2)) ) then
		  _type := 3;

// обновляется не только изображение но и меню для запроса
	  case _type of
		  1 : begin
            doc.ksCircle( 0, 0, 20, 1 );
            info.commandsString := '!Квадрат !Треугольник ';
            flag := 1;
				  end;
			2 : begin
            doc.ksLineSeg( -10, 0,  10,  0,  1 );
            doc.ksLineSeg( 10,  0,  0,   20, 1 );
            doc.ksLineSeg( 0,   20, -10, 0,  1 );
            info.commandsString := '!Окружность !Квадрат ';
            flag := 2;
  				end;
			3 : begin
            doc.ksLineSeg( -10, 0,  10,  0,  1 );
            doc.ksLineSeg( 10,  0,  10,  20, 1 );
            doc.ksLineSeg( 10,  20, -10, 20, 1 );
            doc.ksLineSeg( -10, 20, -10, 0,  1 );
            info.commandsString := '!Окружность !Треугольник ';
            flag := 0;
          end;
		end;

		doc.ksEndGroup;
	end;
	Result := 1;
end;

//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
// ---
function CallBackProcPlacement( comm : Integer; var x, y, ang : Double; rInfo, rPhan : PIDispatch;
                             _dynamic : Integer ) : Integer; stdcall; Export;
var
  info : ksRequestInfo;
  phan : ksPhantom;
  t1   : ksType1;
begin
	info := ksRequestInfo( rInfo );
	phan := ksPhantom( rPhan );
	if ( (info <> nil) And (phan <> nil) ) then begin
		t1 := ksType1( phan.GetPhantomParam );
		case comm of
			1, 2  : _type := comm;
			-1    : begin // поставить в модель
                doc.ksMoveObj( t1.gr, x, y );
// отличие от Cursor угол приходит в виде параметра функции
                if ( Abs(ang) > 0.001 ) then
                  doc.ksRotateObj( t1.gr, x, y, ang );
                doc.ksStoreTmpGroup( t1.gr );    // поставить временную группу в вид
                doc.ksClearGroup( t1.gr, true );
              end;
		end;

// группа для фантома должна быть временная и обновляться при изменении вида отрисовки
		if ( t1.gr <> 0 ) then
			doc.ksDeleteObj( t1.gr );
		t1.gr := doc.ksNewGroup( 1 );   // временная группа

// обновляется не только изображение но и меню для запроса
	  if ( ((flag = 1) And (comm = 1)) Or ((flag = 2) And (comm = 2)) ) then
		  _type := 3;

	  case _type of
		  1 : begin
            doc.ksCircle( 0, 0, 20, 1 );
            info.commandsString := '!Квадрат !Треугольник ';
            flag := 1;
				  end;
			2 : begin
            doc.ksLineSeg( -10, 0,  10,  0,  1 );
            doc.ksLineSeg( 10,  0,  0,   20, 1 );
            doc.ksLineSeg( 0,   20, -10, 0,  1 );
            info.commandsString := '!Окружность !Квадрат ';
            flag := 2;
  				end;
			3 : begin
            doc.ksLineSeg( -10, 0,  10,  0,  1 );
            doc.ksLineSeg( 10,  0,  10,  20, 1 );
            doc.ksLineSeg( 10,  20, -10, 20, 1 );
            doc.ksLineSeg( -10, 20, -10, 0,  1 );
            info.commandsString := '!Окружность !Треугольник ';
            flag := 0;
          end;
		end;

		doc.ksEndGroup;
	end;

	Result := 1;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawRectCallBack;
var
  phan      : ksPhantom;
  t1        : ksType1;
  info      : ksRequestInfo;
  x, y, ang : Double;
begin
  _type := 1;
	phan  := ksPhantom( kompas.GetParamStruct(ko_Phantom) );
	if ( phan <> nil ) then begin
		phan.Init;
		phan.phantom := 1;
		t1 := ksType1( phan.GetPhantomParam );
		if ( t1 <> nil ) then begin
			t1.Init;
			t1.scale_ := 1;
			t1.gr     := doc.ksNewGroup( 1 );   // временная группа
		    doc.ksCircle( 0, 0, 20, 1 );
			doc.ksEndGroup;

			info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
			if ( info <> nil ) then begin
				info.Init;
				info.commandsString := '!Квадрат !Треугольник ';
				// указываем адрес обратной функции для Placement
				info.SetCallBackP( 'CALLBACKPROCPLACEMENT', HInstance, nil );
				doc.ksPlacement( info, x, y, ang, phan );

				t1.gr := doc.ksNewGroup( 1 );   // временная группа
			    doc.ksCircle( 0, 0, 20, 1 );
				doc.ksEndGroup;

				// указываем адрес обратной функции для Cursor
				info.SetCallBackC( 'CALLBACKPROCCURSOR', HInstance, nil );
				doc.ksCursor( info, x, y, phan );
			end;
		end;
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawRectNULL;
var
  j         : Integer;
  phan      : ksPhantom;
  t1        : ksType1;
  info      : ksRequestInfo;
  x, y, ang : Double;
begin
  _type := 1;
  flag  := 1;
  j     := 1;
	phan  := ksPhantom( kompas.GetParamStruct(ko_Phantom) );
	if ( phan <> nil ) then begin
		phan.Init;
		phan.phantom := 1;
		t1          := ksType1( phan.GetPhantomParam );
		if ( t1 <> nil ) then begin
			t1.Init;
			t1.scale_ := 1;
			t1.gr     := 0;   // временная группа

			info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
			if ( info <> nil ) then begin
				info.Init;
			  while j <> 0 do begin
					if ( t1.gr <> 0 ) then
						doc.ksDeleteObj( t1.gr );

					t1.gr := doc.ksNewGroup( 1 ); // временная группа
					if ( ((flag = 1) And (j = 1)) Or ((flag = 2) And (j = 2)) ) then
						_type := 3;

          case _type of
            1 : begin
                  doc.ksCircle( 0, 0, 20, 1 );
                  info.commandsString := '!Квадрат !Треугольник ';
                  flag := 1;
                end;
            2 : begin
                  doc.ksLineSeg( -10, 0,  10,  0,  1 );
                  doc.ksLineSeg( 10,  0,  0,   20, 1 );
                  doc.ksLineSeg( 0,   20, -10, 0,  1 );
                  info.commandsString := '!Окружность !Квадрат ';
                  flag := 2;
                end;
            3 : begin
                  doc.ksLineSeg( -10, 0,  10,  0,  1 );
                  doc.ksLineSeg( 10,  0,  10,  20, 1 );
                  doc.ksLineSeg( 10,  20, -10, 20, 1 );
                  doc.ksLineSeg( -10, 20, -10, 0,  1 );
                  info.commandsString := '!Окружность !Треугольник ';
                  flag := 0;
                end;
          end;

					doc.ksEndGroup;

					j := doc.ksPlacement( info, x, y, ang, phan );
//					j := doc.ksCursor( info, x, y, phan );
          case j of
            1, 2  : _type := j;
            -1    : begin // поставить в модель
                      doc.ksMoveObj( t1.gr, x, y );
//                      if ( Abs(t1.Angle) > 0.001 ) then
//                        doc.ksRotateObj( t1.gr, x, y, t1.Angle );
      // отличие от Cursor угол приходит в виде параметра функции
                      if ( Abs(ang) > 0.001 ) then
                        doc.ksRotateObj( t1.gr, x, y, ang );
                      doc.ksStoreTmpGroup( t1.gr );    // поставить временную группу в вид
                      doc.ksClearGroup( t1.gr, true );
                    end;
          end;
				end;
			end;
		end;
	end;
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 10;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;
var
 h1, i : LongInt;
 buf   : string;
begin
  kompas := KompasObject( CreateKompasObject );

  if kompas <> nil then begin
    case command of
      1 : DrawTxtDB; // работа с БД
      3 : begin      // ввод длинного целого
            if ( kompas.ksReadInt('Ввести индекс', 10000, -100000, 100000, h1) <> 0 ) then begin
              buf := Format( 'h = %d', [h1] );
              kompas.ksMessage( buf );
            end
            else
              kompas.ksMessage( 'отказ' );
          end;
      4  : begin  // выбор имени файла
            buf := kompas.ksChoiceFile( '*.cdw', '', true );
            if ( buf <> '' ) then
              kompas.ksMessage( buf )
            else
              kompas.ksMessage( 'отказ' );
          end;
      9  : WorkRelativePath; // Работа с относительными путями файлов

      else begin
        doc := ksDocument2D( kompas.ActiveDocument2D );
        if ( doc <> nil ) then begin
          case command of
            2  : begin // технические требования
                   if ( kompas.ksYesNo('Вызывать функцию CallBack?') > 0 ) then
                     DrawRectCallBack
                   else
                     DrawRectNULL;
                 end;
            6  : WriteSlideStep; // пример отрисовки слайда
            7  : TestShowDialog; // отрисовать слайд ( описание в файле step4_3.cpp )
            8  : begin
                   kompas.ksEnableTaskAccess( 0 ); //запретили доступ к задаче
                   for i := 0 to 9999 do begin
                     doc.ksLineSeg( 10, 10 + i, 20, 10 + i, 1 );
                     if ( (i div 100) = 0 ) then begin
                       // посылаем необрабатываемое сообщение своему приложению
                       // для выполнения процесса в фоновом режиме
                       PostThreadMessage( GetCurrentThreadId, 0, 0, 0 );
                       kompas.ksPumpWaitingMessages; // через каждые 100 отрезков обрабатываем очередь сообщений
                                                     // при этом Windows получает возможность выполнить свои
                                                     // действия, например переключиться на другую задачу
                     end;
                   end;
                   kompas.ksEnableTaskAccess( 1 ); //разрешили доступ к задаче
                 end;
            10 : WorkSystemPath; // Работа с системными каталогами
          end;
          doc := nil;
        end;
      end;
      kompas.ksMessageBoxResult;
    end;
    kompas := nil;
  end;
end;

end.
