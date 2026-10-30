# GetDummyEmbodimentMarking - Обозначение исполнения для макета

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_getgabarit.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_getbodybyid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BSTR GetDummyEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer );

Синтаксис COM:

HRESULT GetDummyEmbodimentMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BSTR * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
  
Входные параметры:

MarkingType | \- индекс части обозначения из перечисления [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
---|---  
AddSystemDelimer | \- добавлять системные разделители.  
  
Подразделы:

(отсутствуют)
