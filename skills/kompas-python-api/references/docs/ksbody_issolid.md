# IsSolid - Является ли объект твердым телом или поверхностью

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbody_massinertiaparam.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_getintersectionfaceswithbody.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbody.html)

Синтаксис Automation:

BOOL IsSolid();

Синтаксис COM:

BOOL IsSolid();

Возвращаемое значение:

TRUE | \- объект является твердым телом,  
---|---  
FALSE | \- объект является поверхностью.  
  
Примечание:

Твердое тело может состоять из набора поверхностей.

Подразделы:

(отсутствуют)
