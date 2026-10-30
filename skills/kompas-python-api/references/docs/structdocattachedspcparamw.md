# DocAttachedSpcParamW - Структура параметров документа, подключенного к объекту спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structnumbertypeattrparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structdocattachedspcparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksDocAttachedSpcParam](ksdocattachedspcparam.html).

wchar_t | fileName [MAX_TEXT_LENGTH] | имя файла подключенного документа,  
---|---|---  
wchar_t | comment [MAX_TEXT_LENGTH] | комментарий к подключенному документу,  
unsigned char | transmit | признак передачи в документ изменений в объекте спецификации (0 - не передавать в изменения в документ, 1 - передавать в изменения в документ).  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [DocAttachedSpcParam](structdocattachedspcparam.html).

Подразделы:

(отсутствуют)
