# SpcDescrParam - Структура параметров описания спецификации

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcdescrparamw.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspccolumnparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcDescrParam](ksspcdescrparam.html).

char | layoutName [MAX_TEXT_LENGTH] | имя файла библиотеки стилей,  
---|---|---  
unsigned int | styleId | номер стиля в библиотеке,  
char | spcName [MAX_TEXT_LENGTH] | имя подключенного файла спецификации, имеющей данный стиль.  
  
Примечание.

При использовании Unicode следует использовать структуру параметров [SpcDescrParamW](structspcdescrparamw.html).

Подразделы:

(отсутствуют)
