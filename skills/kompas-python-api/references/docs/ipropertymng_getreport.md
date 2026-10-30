# GetReport - Получить интерфейс таблицы отчета по имени файла или указателю на документ

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyMng ](ipropertymng.html) > [IPropertyMng - методы ](ipropertymng_methods.html) |  Scroll [ [ [ ](ipropertymng_removeproperty.html "К следующему разделу")](ipropertymng_methods.html "На уровень выше")](ipropertymng_getproperties.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymng.html)

Синтаксис Automation:

LPDISPATCH GetReport( VARIANT Document, ksReportTypeEnum Type );

Синтаксис COM:

HRESULT GetReport( VARIANT Document, ksReportTypeEnum Type, IReport ** Result );

Возвращаемое значение:

| \- Указатель на интерфейс отчета [IReport](ireport.html).  
---|---  
  
Входные параметры:

Document | \- имя файла или указатель на документ.  
---|---  
  
Выходные параметры:

Type | \- тип отчета.  
---|---  
  
Подразделы:

(отсутствуют)
