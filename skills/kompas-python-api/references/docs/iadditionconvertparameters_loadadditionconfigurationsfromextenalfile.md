# LoadAdditionConfigurationsFromExtenalFile - Загрузить список доступных конфигураций из файла

[API интерфейсов. Версия 7](applicate.html) > [Конвертер файлов КОМПАС ](conv.html) > [Интерфейс IAdditionConvertParameters ](iadditionconvertparameters.html) > [IAdditionConvertParameters - методы ](iadditionconvertparameters_methods.html) |  Scroll [ [ [ ](iadditionconvertparameters_loadconfigurationfile.html "К следующему разделу")](iadditionconvertparameters_methods.html "На уровень выше")](iadditionconvertparameters_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iadditionconvertparameters.html)

Синтаксис Automation:

VARIANT LoadAdditionConfigurationsFromExtenalFile( BSTR FileName, long * ActiveIndex );

Синтаксис COM:

HRESULT LoadAdditionConfigurationsFromExtenalFile( BSTR FileName, long * ActiveIndex, VARIANT * Result );

Возвращаемое значение:

| \- Список доступных для экспорта конфигураций (VT_ARRAY | VT_BSTR).  
---|---  
  
Входные параметры:

FileName | \- путь к экспортируемому файлу.  
---|---  
  
Выходные параметры:

ActiveIndex | \- индекс текущей конфигурации, установленной в файле.  
---|---  
  
Примечание:

Список конфигураций может быть получен для файлов SolidWorks, деталей (.sldprt) и сборок (.sldasm).

Версия Компас v23

Подразделы:

(отсутствуют)
