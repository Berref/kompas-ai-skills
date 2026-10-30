# SpcStyleParamW - Структура параметров стиля спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcstylecolumnparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspcstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcStyleParam](ksspcstyleparam.html).

wchar_t | layoutName1 [MAX_TEXT_LENGTH] | имя файла библиотеки оформлений для первого листа спецификации  
---|---|---  
wchar_t | layoutName2 [MAX_TEXT_LENGTH] | имя файла библиотеки оформлений для последующих листов спецификации  
unsigned int | shtType1 | номер оформления из библиотеки для первого листа спецификации  
unsigned int | shtType2 | номер оформления из библиотеки для последующих листов спецификации  
unsigned char | ispolnVariant | вариант оформления спецификации (0 - простая, 1 - групповая, вариант А, 2 - групповая, вариант Б, 3 - групповая, вариант В, 4 - групповая, вариант Г)  
unsigned char | sectionOn | деление на разделы (0 - выключено, 1- включено)  
char | rezerv[10] | служебный параметр  
[SpcTuningStyleParamW](structspctuningstyleparamw.html) | tuning | параметры умолчательных настроек спецификации  
reference | arrColumn | массив структур параметров колонок [SpcStyleColumnParam](structspcstylecolumnparam.html)  
reference | arrAdditionalColumn | массив структур параметров дополнительных колонок [SpcStyleColumnParam](structspcstylecolumnparam.html)  
reference | arrSection | массив структур параметров разделов спецификации [SpcStyleSectionParam](structspcstylesectionparam.html)  
unsigned char | type | формат листа бумаги (0 - стандартный, 1 - пользовательский)  
[StandartSheet](structstandartsheet.html) | stPar | параметры листа бумаги стандартного формата  
[SheetSize](structsheetsize.html) | usPar | параметры листа бумаги пользовательского формата  
  
Примечания:

1\. Структура stPar заполняется, если параметр type равен 1, структура usPar заполняется, если параметр type равен 0.

2\. В настоящее время параметр rezerv не используется.

3\. При использовании ANSI следует использовать структуру параметров [SpcStyleParam](structspcstyleparam.html).

Подразделы:

(отсутствуют)
