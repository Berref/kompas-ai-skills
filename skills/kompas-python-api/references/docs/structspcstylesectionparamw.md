# SpcStyleSectionParamW - Структура параметров стиля раздела спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcsubsectionparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspcstylesectionparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcStyleSectionParam](ksspcstylesectionparam.html).

wchar_t | sectionName [MAX_TEXT_LENGTH] | имя раздела  
---|---|---  
unsigned short | number | номер раздела  
unsigned int | sortColumnType | общий тип колонки, по данным в которой производится сортировка  
unsigned int | sortIspoln | номер колонки, по данным в которой производится сортировка  
unsigned char | dataType | способ ввода данных (0 - ручное заполнение колонок, 1 - ручное заполнение или чтение из основной надписи подключенного документа)  
unsigned short | sortType | тип сортировки объектов в разделе  
reference | arrColumn | массив структур параметров стиля колонок спецификации  
reference | arrAdditionalColumn | массив структур параметров стиля дополнительных колонок спецификации  
char | rezerv[10] | служебный параметр  
  
[Типы сортировки объектов в разделе спецификации...](spcsorttypes.html)

Структура параметров стиля колонки спецификации [SpcStyleColumnParamW...](structspcstylecolumnparamw.html)

Примечание:

1\. В настоящее время параметр rezerv не используется.

2\. При использовании ANSI следует использовать структуру параметров [SpcStyleSectionParam](structspcstylesectionparam.html).

Подразделы:

(отсутствуют)
