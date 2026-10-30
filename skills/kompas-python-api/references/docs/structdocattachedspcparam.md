# DocAttachedSpcParam - Структура параметров документа, подключенного к объекту спецификации

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structdocattachedspcparamw.html "К следующему разделу")](bk1738516.html "На уровень выше")](bk1738516.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksDocAttachedSpcParam](ksdocattachedspcparam.html).

char | fileName [MAX_TEXT_LENGTH] | имя файла подключенного документа,  
---|---|---  
char | comment [MAX_TEXT_LENGTH] | комментарий к подключенному документу,  
unsigned char | transmit | признак передачи в документ изменений в объекте спецификации (0 - не передавать в изменения в документ, 1 - передавать в изменения в документ).  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [DocAttachedSpcParamW](structdocattachedspcparamw.html).

Подразделы:

(отсутствуют)
