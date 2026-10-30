# GetCurrentEmbodimentMarking - Обозначение текущего исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_getembodimentmarking.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_findembodiment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BSTR GetCurrentEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType,

BOOL AddSystemDelimer);

Синтаксис COM:

HRESULT GetCurrentEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType,

BOOL AddSystemDelimer,

BSTR * Result);

Возвращаемое значение:

| \- обозначение текущего исполнения.  
---|---  
  
Входные параметры:

MarkingType | \- часть обозначения из перечисления [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
---|---  
AddSystemDelimer | \- добавлять системные разделители.  
  
Метод позволяет получить обозначение текущего исполнения.

Подразделы:

(отсутствуют)
