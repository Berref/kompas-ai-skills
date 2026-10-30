# Refresh - Обновить массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Массив ориентированных ребер (Интерфейсы ksOrientedEdgeCollection, IOrientedEdgeCollection) ](ksorientededgecollection.html) > [IOrientedEdgeCollection - методы ](ksorientededgecollection_methods.html) |  Scroll [ [ [ ](ksorientededge.html "К следующему разделу")](ksorientededgecollection_methods.html "На уровень выше")](ksorientededgecollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksorientededgecollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова данной функции возникает полное соответствие массива с массивом ориентированных ребер и удаляются все предыдущие изменения в массиве.

Подразделы:

(отсутствуют)
