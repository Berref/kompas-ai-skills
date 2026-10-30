# Refresh - Обновить массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbodycollection_setbyindex.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksbodycollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После вызова данной функции возникает полное соответствие массива с массивом тел трехмерной детали или сборки и удаляются все предыдущие изменения в массиве.

Подразделы:

(отсутствуют)
