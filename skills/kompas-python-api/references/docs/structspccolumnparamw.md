# SpcColumnParamW - Структура параметров колонки спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcdescrparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspccolumnparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcColumnParam](ksspccolumnparam.html).

unsigned int | columnType | тип колонки,  
---|---|---  
unsigned int | ispoln | номер исполнения данного типа, начиная с 1,  
unsigned int | block | номер блока,  
unsigned int | typeVal | тип данных в колонке,  
wchar_t | name [TEXT_LENGTH] | имя колонки.  
  
[Типы колонок спецификации...](ctypes.html)

[Типы данных в колонках...](attypes.html)

Примечание:

1\. Тип данных в колонках спецификации columnType может принимать значения: SPC_CLM_FORMAT...SPC_CLM_USER.

2\. Тип колонки спецификации typeVal может принимать значения: LINT_ATTR_TYPE, DOUBLE_ATTR_TYPE, STRING_ATTR_TYPE и RECORD_ATTR_TYPE.

3\. При использовании ANSI следует использовать структуру параметров [SpcColumnParam](structspccolumnparam.html).

Подразделы:

(отсутствуют)
