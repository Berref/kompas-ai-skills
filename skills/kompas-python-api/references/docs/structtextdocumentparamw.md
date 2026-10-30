# TextDocumentParamW - Структура параметров текстового документа (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](structtextlineparam.html "К следующему разделу")](bk1742729.html "На уровень выше")](structtextdocumentparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextDocumentParam](kstextdocumentparam.html).

unsigned char | regim | 0 - видимый режим, 1 - невидимый режим,  
---|---|---  
wchar_t | fileName [MAX_TEXT_LENGTH] | имя файла,  
wchar_t | comment [TEXT_LENGTH | комментарий,  
wchar_t | author [TEXT_LENGTH] | автор,  
[LibraryStyleParamW](structlibrarystyleparamw.html) | firstSheet | оформление первого листа (имя библиотеки стилей, номер стиля в библиотеке),  
[LibraryStyleParamW](structlibrarystyleparamw.html) | evenSheet | оформление четных листов (имя библиотеки стилей, номер стиля в библиотеке),  
[LibraryStyleParamW](structlibrarystyleparamw.html) | oddSheet | оформление нечетных листов (имя библиотеки стилей, номер стиля в библиотеке),  
reference | arrTitleSheet | динамический массив оформлений титульных листов LIBRARY_STYLE_ARR,  
reference | arrTailSheet | динамический массив оформлений листов заключительной части LIBRARY_STYLE_ARR,  
unsigned char | type | тип документа из [DocType](doctype.html) (lt_DocTxtStandart или lt_DocTxtUser),  
struct StandartSheet | stPar | параметры стандартного формата, структура [StandartSheet](structstandartsheet.html), multiply не используется,  
struct SheetSize | usPar | параметры нестандартного формата, структура [SheetSize](structsheetsize.html).  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [TextDocumentParam](structtextdocumentparam.html).

Подразделы:

(отсутствуют)
