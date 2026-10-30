////////////////////////////////////////////////////////////////////////////////
//
// Пример работы с заданием на печать и настройками принтера
//
////////////////////////////////////////////////////////////////////////////////

unit Step4_API7_2D_1;

interface
uses
  Sysutils, LDefin2D, ksAuto, Forms, Libtool, Windows, Math
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  , Variants
{$IFEND}
{$ENDIF CONDITIONALEXPRESSIONS}
  ;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  procedure  GetNewKompasAPI;
  procedure  PrintSample;
  procedure  PrintSettingsSample;

implementation

uses
  LtDefine,
  ksApi7,
  ksConstTLB;

const
  IDS_NODOC       = 200;
  IDS_ERRCONFIG   = 201;

var
  appl7 : IApplication;       // Компас Application 7
  doc   : IKompasDocument2D;  // Активный документ


//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;


//------------------------------------------------------------------------------
// Получить текущий документ
// ---
function GetCurrentDocument : IKompasDocument2D;

var
  kDoc : IKompasDocument;
begin
  Result := nil;

  if ( appl7 <> nil ) then
     // Получить активный документ
     kDoc := appl7.ActiveDocument;
  Result := kDoc As IKompasDocument2D;
end;


//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;

var
  mes : WideString;
begin
  Forms.Application.Handle := GetHWindow;
  GetNewKompasAPI;
  doc := GetCurrentDocument;

  if ( doc <> nil ) then
  begin
    case command of
      1: PrintSample;
      2: PrintSettingsSample;
    end;
    appl7 := nil;
  end
  else
  begin
    mes := LoadStr( IDS_NODOC );
    ksMessageW( PWideChar(mes) );
  end;
end;


//------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if appl7 = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    appl7 := disp As IApplication;
  end;
end;


//------------------------------------------------------------------------------
// Рассчитать масштаб для вывода
// ---
procedure CalcScale( print : IPrintJob );
var
  pageWidth,
  pageHeight,
  w,
  h         : double;
  count,
  i         : integer;
  sheet     : IPrintJob_Sheet;
begin
  if print <> nil then
  begin
    // Определяем габариты страницы устройства печати
    print.GetPageGabarites( pageWidth, pageHeight );
    count := print.SheetsCount;

    for i := 0 to count do
    begin
      // Получаем лист документа
      sheet := print.Sheet[i];

      if sheet <> nil then
      begin
        // Определяем габариты листа
        sheet.GetGabarites( w, h );
        // Вычисляем масштаб вывода
        if pageWidth > w then
          sheet.Scale := 1
        else
          sheet.Scale := pageWidth/w;
        // Размещаем лист в начале страницы
        sheet.X := pageWidth * i;
      end;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Пример работы с интерфейсом задания на печать
// ---
procedure PrintSample;
var
  print    : IPrintJob;
  sheets,
  delIndex : OleVariant;
begin
  GetNewKompasAPI;

  if appl7 <> nil then
  begin
    // Получаем интерфейс задания на печать
    print := appl7.PrintJob;

    if print <> nil then
    begin
      VarAsType( sheets, varEmpty );
      // Добавляем документ дважды (все листы)
      print.AddSheets( 'Чертеж.cdw', sheets, ksAllSheets );
      print.AddSheets( 'Чертеж.cdw', sheets, ksAllSheets );
      // Массив индексов удаляемых листов
      delIndex := VarArrayCreate( [0, 3], varInteger );
      delIndex[0] := 0;
      delIndex[1] := 1;
      delIndex[2] := 4;
      delIndex[3] := 5;
      // Удаляем листы
      print.RemoveSheets( delIndex );
      // Рассчитываем масштаб
      CalcScale( print );
      // Выводим окно предварительного просмотра
      print.ShowPreviewWindow;
    end;
  end;
end;


//------------------------------------------------------------------------------
// Пример работы с интерфейсом настроек принтера
// ---
procedure PrintSettingsSample;
var
  print : IPrintJob;
  printSettings : IPrintJob_PrinterSettings;
  sheet : IPrintJob_Sheet;
  sheets,
  delIndex : OleVariant;
  w, h, scale : double;
  mes : WideString;
begin
  GetNewKompasAPI;

  if appl7 <> nil then
  begin
    // Получаем интерфейс задания на печать
    print := appl7.PrintJob;

    if print <> nil then
    begin
      VarAsType( sheets, varEmpty );
      // Добавляем документ
      print.AddSheets( 'Чертеж.cdw', sheets, ksAllSheets );
      // Массив индексов удаляемых листов
      delIndex := VarArrayCreate( [0, 2], varInteger );
      delIndex[0] := 1;
      delIndex[1] := 2;
      delIndex[2] := 3;
      // Удаляем все листы, кроме 1-го
      print.RemoveSheets( delIndex );
      // Получаем интерфейс настроек принтера
      printSettings := print As IPrintJob_PrinterSettings;

      if printSettings <> nil then
      begin
        // Загружаем конфигурацию принтера
        if printSettings.LoadPrinterConfig( 'Конфигурация.pdc' ) then
        begin
          // Получаем интерфейс листа документа
          sheet := print.Sheet[0];
          if sheet <> nil then
          begin
            // Получаем габариты листа
            sheet.GetGabarites( w, h );
            // Получаем масштаб листа
            scale := sheet.Scale;
            // Подгоняем размер бумаги под размер листа
            printSettings.PaperWidth := Floor( 10 * w * scale );
            printSettings.PaperLength := Floor( 10 * h * scale );
            // Выводим окно предварительного просмотра
            print.ShowPreviewWindow;
          end;
        end
        else
        begin
          mes := LoadStr( IDS_ERRCONFIG );
          ksMessageW( PWideChar(mes) );
        end;
      end;
    end;
  end;
end;


end.
