# GetFilter - Получить фильтр и номер команды по типу документа

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IСonverter ](iconverter.html) > [IConverter - методы ](iconverter_methods.html) |  Scroll [ [ [ ](iconverter_visualeditconvertparam.html "К следующему разделу")](iconverter_methods.html "На уровень выше")](iconverter_converterparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconverter.html)

Синтаксис Automation:

BSTR * GetFilter (long docType, BOOL saveAs, long * command);

Синтаксис COM:

HRESULT GetFilter ([in] long docType,

[in] VARIANT_BOOL saveAs,

[out] long* command,

[out, retval] BSTR* Result);

Входные параметры:

docType | \- при импорте в КОМПАС-документ - тип документа из перечисления [DocumentTypeEnum,](documenttypeenum.html) \- при экспорте КОМПАС-документа - тип документа, в который производится экспорт, перечисление типов документов, должно быть задано в конверторе. Например, для конвертора в DXF и DWG используются типы: #define FORMAT_DXF 1 // ID команды для работы с DXF #define FORMAT_DWG 2 // ID команды для работы с DWG  
---|---  
saveAs | \- TRUE - экспорт документа КОМПАС, \- FALSE - импорт в документ КОМПАС.  
  
Выходные параметры:

command | \- номер команды.  
---|---  
  
Возвращаемое значение:

фильтр | \- строка со справочным значением (например 'КОМПАС-Фрагменты (*.myfrw)|*.myfrw|'), которое используется в диалогах Открыть файл и Сохранить файл.  
---|---  
  
Подразделы:

(отсутствуют)
