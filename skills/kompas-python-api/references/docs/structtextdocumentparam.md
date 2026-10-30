# TextDocumentParam - Структура параметров текстового документа

[Структуры параметров и константы](3d_define.html) > [Структуры параметров текста ](bk1742729.html) |  Scroll [ [ [ ](structtextdocumentparamw.html "К следующему разделу")](bk1742729.html "На уровень выше")](structparagraphparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksTextDocumentParam](kstextdocumentparam.html).

unsigned char | regim | 0 - видимый режим, 1 - невидимый режим,  
---|---|---  
char | fileName [MAX_TEXT_LENGTH] | имя файла,  
char | comment [TEXT_LENGTH | комментарий,  
char | author [TEXT_LENGTH] | автор,  
[LibraryStyleParam](structlibrarystyleparam.html) | firstSheet | оформление первого листа (имя библиотеки стилей, номер стиля в библиотеке),  
[LibraryStyleParam](structlibrarystyleparam.html) | evenSheet | оформление четных листов (имя библиотеки стилей, номер стиля в библиотеке),  
[LibraryStyleParam](structlibrarystyleparam.html) | oddSheet | оформление нечетных листов (имя библиотеки стилей, номер стиля в библиотеке),  
reference | arrTitleSheet | динамический массив оформлений титульных листов LIBRARY_STYLE_ARR,  
reference | arrTailSheet | динамический массив оформлений листов заключительной части LIBRARY_STYLE_ARR,  
unsigned char | type | тип документа из [DocType](doctype.html) (lt_DocTxtStandart или lt_DocTxtUser),  
struct StandartSheet | stPar | параметры стандартного формата, структура [StandartSheet](structstandartsheet.html), не используется,  
struct SheetSize | usPar | параметры нестандартного формата, структура [SheetSize](structsheetsize.html).  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [TextDocumentParamW.](structtextdocumentparamw.html)

Подразделы:

(отсутствуют)
