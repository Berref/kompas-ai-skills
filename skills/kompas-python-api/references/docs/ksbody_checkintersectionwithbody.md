# CheckIntersectionWithBody - Проверить наличия пересечений с другим телом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [Трехмерное тело (Интерфейсы ksBody, Body) ](ksbody.html) > [IBody - методы ](ksbody_methods.html) |  Scroll [ [ [ ](ksbody_curveintersection.html "К следующему разделу")](ksbody_methods.html "На уровень выше")](ksbody_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbody.html)

Синтаксис Automation:

LPDISPATCH CheckIntersectionWithBody (LPDISPATCH otherBody,

BOOL checkTangent);

Синтаксис COM:

LPINTERSECTIONRESULT CheckIntersectionWithBody (LPBODY otherBody,

BOOL checkTangent);

Входные параметры:

otherBody | \- тело, с которым проверяется пересечение,  
---|---  
checkTangent | \- считать касания пересечениями.  
  
Возвращаемое значение:

Интерфейс [ksIntersectionResult](ksintersectionresult.html) | \- в случае успеха,  
---|---  
NULL | \- если пересечений нет.  
  
Подразделы:

(отсутствуют)
