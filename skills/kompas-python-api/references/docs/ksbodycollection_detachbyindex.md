# DetachByIndex - Удалить объект из массива по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbodycollection_findit.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_detachbybody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodycollection.html)

Синтаксис Automation:

BOOL DetachByIndex(long index);

Синтаксис COM:

BOOL DetachByIndex(long index);

Входные параметры:

index | \- индекс удаляемого объекта в массиве.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Элемент массива из модели не удаляется.

Подразделы:

(отсутствуют)
