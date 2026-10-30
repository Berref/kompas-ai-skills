# DocumentParam - Структура параметров документа

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structdocumentparamw.html "К следующему разделу")](bk1829760.html "На уровень выше")](copyobjectparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksDocumentParam](ksdocumentparam.html).

unsigned char | regim | режим (0 - видимый, 1 - "слепой"),  
---|---|---  
unsigned char | type | [тип документа,](doctype.html)  
char | fileName [MAX_TEXT_LENGTH] | имя файла документа,  
char | comment [TEXT_LENGTH] | комментарий к документу,  
char | author [TEXT_LENGTH] | автор документа,  
SheetPar | sheet | [структура параметров оформления документов.](structsheetpar.html)  
  
Примечание:

1\. Структура параметров sheet используется для чертежей и спецификаций, т.е. когда параметр type имеет значения 1, 2, 4.

2\. При использовании Unicode следует использовать структуру параметров [DocumentParamW](structdocumentparamw.html).

Подразделы:

(отсутствуют)
