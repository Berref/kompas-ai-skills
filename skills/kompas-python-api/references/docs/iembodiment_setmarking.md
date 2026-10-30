# SetMarking - Обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodiment ](iembodiment.html) > [IEmbodiment - методы ](iembodiment_methods.html) |  Scroll [ [ [ ](iembodiment_setmaterial.html "К следующему разделу")](iembodiment_methods.html "На уровень выше")](iembodiment_saveas.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodiment.html)

Синтаксис Automation:

BOOL SetMarking( ksVariantMarkingTypeEnum MarkingType, BSTR Marking );

Синтаксис COM:

HRESULT SetMarking( ksVariantMarkingTypeEnum MarkingType, BSTR Marking, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

MarkingType | \- какую часть обозначения надо установить,  
---|---  
Marking | \- обозначение.  
  
Метод устанавливает обозначение исполнения.

Подразделы:

(отсутствуют)
