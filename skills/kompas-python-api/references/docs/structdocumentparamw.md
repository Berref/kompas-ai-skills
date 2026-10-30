# DocumentParamW - Структура параметров документа (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structlayerparam.html "К следующему разделу")](bk1829760.html "На уровень выше")](structdocumentparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksDocumentParam](ksdocumentparam.html).

unsigned char | regim | режим (0 - видимый, 1 - "слепой"),  
---|---|---  
unsigned char | type | [тип документа,](doctype.html)  
wchar_t | fileName [MAX_TEXT_LENGTH] | имя файла документа,  
wchar_t | comment [TEXT_LENGTH] | комментарий к документу,  
wchar_t | author [TEXT_LENGTH] | автор документа,  
SheetParW | sheet | [структура параметров оформления документов.](structsheetparw.html)  
  
Примечание:

1\. Структура параметров sheet используется для чертежей и спецификаций, т.е. когда параметр type имеет значения 1, 2, 4.

2\. При использовании ANSI следует использовать структуру параметров [DocumentParam](structdocumentparam.html).

Подразделы:

(отсутствуют)
