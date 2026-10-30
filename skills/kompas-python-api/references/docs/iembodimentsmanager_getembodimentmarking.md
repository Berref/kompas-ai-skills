# GetEmbodimentMarking - Получить обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_getembodimentstree.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_getcurrentembodimentmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BSTR GetEmbodimentMarking( long Index,

ksVariantMarkingTypeEnum MarkingType,

BOOL AddSystemDelimer);

Синтаксис COM:

HRESULT GetEmbodimentMarking( long Index,

ksVariantMarkingTypeEnum MarkingType,

BOOL AddSystemDelimer,

BSTR * Result);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс обозначения,  
---|---  
MarkingType | \- часть обозначения из перечисления [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
AddSystemDelimer | \- добавлять системные разделители.  
  
Подразделы:

(отсутствуют)
