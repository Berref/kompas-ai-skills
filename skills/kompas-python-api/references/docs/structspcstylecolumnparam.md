# SpcStyleColumnParam - Структура параметров стиля колонки спецификаци

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspcstylecolumnparamw.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspcstyleparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcStyleColumnParam](ksspcstylecolumnparam.html).

char | nameColumn [MAX_TEXT_LENGTH] | имя колонки,  
---|---|---  
unsigned int | columnType | тип колонки спецификации,  
unsigned int | ispoln | номер колонки данного типа,  
unsigned int | typeVal | тип значения в колонке,  
unsigned char | edit | разрешение редактирования, (1 - редактировать колонку в данном разделе, 0 - не редактировать колонку в данном разделе),  
unsigned char | createSum | разрешение расчета суммы (1 - рассчитывать сумму значений в колонке, 0 - не рассчитывать сумму значений в колонке),  
unsigned char | multiplyToCount | разрешение умножения при расчете суммы (1 - при расчете суммы умножать значения в колонке на количество, 0 - не умножать),  
unsigned char | useForSectionTitle | признак размещения имен разделов (1 - использовать колонку для показа имени раздела, 0 - не использовать колонку для показа имени раздела)  
unsigned char | textDn | признак размещения текста в колонке (1 - выравнивать текст в колонке по нижней строке объекта специфИкации, 0 - выравнивать текст в колонке по верхней строке  
char | rezerv[10] | служебный параметр  
unsigned int | linkId | номер ячейки штампа для связи с данной колонкой  
RecordTypeAttrParam | recordType | параметры записи в колонке спецификации  
NumberTypeAttrParam | numberType | параметры числового значения в колонке спецификации  
  
[Типы колонок спецификации...](ctypes.html)

Структура параметров записи в колонке спецификации [RecordTypeAttrParam...](structrecordtypeattrparam.html)

Структура параметров числового значения в колонке спецификации [NumberTypeAttrParam...](structnumbertypeattrparam.html)

[Типы данных в колонках...](attypes.html)

Примечания:

1\. В качестве типа значения в колонке используются INT_ATTR_TYPE, DOUBLE_ATTR_TYPE, STRING_ATTR_TYPE и RECORD_ATTR_TYPE.

2\. В настоящее время параметр rezerv не используется.

3\. Структура recordType заполняется, если тип значения в колонке - запись (SPC_RECORD).

4\. Структура numberType заполняется для числовых значений в колонке (SPC_DOUBLE и SPC_INT).

5\. При использовании Unicode следует использовать структуру параметров [SpcStyleColumnParamW](structspcstylecolumnparamw.html).

Подразделы:

(отсутствуют)
