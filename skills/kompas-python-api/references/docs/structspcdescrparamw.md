# SpcDescrParamW - Структура параметров описания спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcobjparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspcdescrparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcDescrParam](ksspcdescrparam.html).

wchar_t | layoutName [MAX_TEXT_LENGTH] | имя файла библиотеки стилей,  
---|---|---  
unsigned int | styleId | номер стиля в библиотеке,  
wchar_t | spcName [MAX_TEXT_LENGTH] | имя подключенного файла спецификации, имеющей данный стиль.  
  
Примечание.

При использовании ANSI следует использовать структуру параметров [SpcDescrParam](structspcdescrparam.html).

Подразделы:

(отсутствуют)
