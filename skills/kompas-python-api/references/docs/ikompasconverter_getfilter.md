# GetFilter - Получить фильтр и номер команды по типу документа

[Создание прикладных библиотек ](libraries_create.html) > [Оформление библиотек типа Converter ](cr95008.html) > [Интерфейс IKompasConverter ](ikompasconverter.html) > [IKompasConverter - свойства ](ikompasconverter_props.html) |  Scroll [ [ [ ](ikompasconverter_convert.html "К следующему разделу")](ikompasconverter_props.html "На уровень выше")](ikompasconverter_converterparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasconverter.html)

Синтаксис Automation:

BSTR * GetFilter ( long docType, BOOL saveAs, long * command );

Синтаксис COM:

HRESULT GetFilter ( [in] long docType,

[in] VARIANT_BOOL saveAs,

[out] long * command,

[out, retval] BSTR* Result );

Входные параметры:

docType | при импорте в КОМПАС-документ - тип документа из перечисления [DocumentTypeEnum](documenttypeenum.html), при экспорте КОМПАС-документа - тип документа, в который производится экспорт; перечисление типов документов должно быть задано в конверторе. Например, для конвертора в DXF и DWG используются типы: #define FORMAT_DXF 1 // ID команды для работы с DXF #define FORMAT_DWG 2 // ID команды для работы с DWG  
---|---  
saveAs | \- TRUE - экспорт документа КОМПАС, \- FALSE - импорт в документ КОМПАС.  
  
Выходные параметры:

command | \- номер команды.  
---|---  
  
Возвращаемое значение:

фильтр | \- строка с справочным значением (например, "КОМПАС-фрагменты (*.myfrw |*.myfrw|" ), которое используется в диалогах открытия и сохранения файлов.  
---|---  
  
Подразделы:

(отсутствуют)
