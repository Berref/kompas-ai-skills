# GetCondition - Получить условия фильтра по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Отчет ](ba1711159.html) > [Интерфейс IReportProcess ](ireportprocess.html) > [Интерфейс IReportFilter ](ireportfilter.html) > [IReportFilter - методы ](ireportfilter_methods.html) |  Scroll [ [ [ ](ireportfilter_removecondition.html "К следующему разделу")](ireportfilter_methods.html "На уровень выше")](ireportfilter_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ireportfilter.html)

Синтаксис Automation:

BOOL GetCondition( long index, VARIANT * uniqId, ksReportFiltersTypeEnum * type, VARIANT * val );

Синтаксис COM:

HRESULT GetCondition( long Index, VARIANT * UniqId, ksReportFiltersTypeEnum * Type, VARIANT * Val, BOOL * Result );

Входные параметры:

index | \- индекс в массиве.  
---|---  
  
Выходные параметры:

uniqId | \- уникальный номер свойства VT_R8,  
---|---  
type | \- условие фильтрации,  
val | \- значение фильтра; тип значения фильтра зависит от типа свойства, для которого задается фильтр.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Свойство только для чтения.

Подразделы:

(отсутствуют)
