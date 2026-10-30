# SetEmbodimentMarking - Установить обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](ibilletobsolete.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_setcurrentembodiment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BOOL SetEmbodimentMarking( long Index,

ksVariantMarkingTypeEnum MarkingType,

BSTR Marking);

Синтаксис COM:

HRESULT SetEmbodimentMarking( long Index,

ksVariantMarkingTypeEnum MarkingType,

BSTR Marking,

BOOL * Result);

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Index | \- индекс обозначения,  
---|---  
MarkingType | \- часть обозначения из перечисления [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
Marking | \- обозначение.  
  
Подразделы:

(отсутствуют)
