# GetMarking - Обозначение исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodiment ](iembodiment.html) > [IEmbodiment - методы ](iembodiment_methods.html) |  Scroll [ [ [ ](iembodiment_makeasembodiment.html "К следующему разделу")](iembodiment_methods.html "На уровень выше")](iembodiment_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodiment.html)

Синтаксис Automation:

BSTR GetMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer );

Синтаксис COM:

HRESULT GetMarking( ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BSTR * Result );

Возвращаемое значение:

| \- обозначение исполнения.  
---|---  
  
Входные параметры:

MarkingType | \- какую часть обозначения надо вернуть,  
---|---  
AddSystemDelimer | \- с разделителями.  
  
Метод возвращает обозначение исполнения.

Подразделы:

(отсутствуют)
