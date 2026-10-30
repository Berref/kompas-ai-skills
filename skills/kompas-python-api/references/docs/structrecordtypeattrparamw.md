# RecordTypeAttrParamW - Структура записи в колонке спецификации (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspccolumnparam.html "К следующему разделу")](bk1738516.html "На уровень выше")](structrecordtypeattrparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksRecordTypeAttrParam](ksrecordtypeattrparam.html).

wchar_t | attrLibName [MAX_TEXT_LENGTH] | имя файла библиотеки типов атрибутов,  
---|---|---  
int | key1 | значения ключей атрибутов, служащих шаблонами заполнения колонки спецификации в данном разделе.  
int | key2  
int | key3  
int | key4  
  
Примечания:

1\. Данная структура заполняется, если тип значения в колонке спецификации - запись (SPC_RECORD).

2\. Если значение какого-либо ключа 0, то этот ключ не учитывается.

3\. При использовании ANSI следует использовать структуру параметров [RecordTypeAttrParam](structrecordtypeattrparam.html).

Подразделы:

(отсутствуют)
