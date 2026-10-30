# OrientedEdgeCollection - Получить массив ориентированных ребер

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Цикл грани(Интерфейсы ksLoop, ILoop) ](ksloop.html) > [ILoop - методы ](ksloop_methods.html) |  Scroll [ [ [ ](int_geometry.html "К следующему разделу")](ksloop_methods.html "На уровень выше")](ksloop_isouter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksloop.html)

Получить массив ориентированных ребер.

Синтаксис Automation:

LPDISPATCH OrientedEdgeCollection (LPDISPATCH edge);

Синтаксис COM:

LPORIENTEDEDGECOLLECTION OrientedEdgeCollection (LPEDGEDEFINITION edge);

Входные параметры:

edge | \- указатель на интерфейс [ksEdgeDefinition](ksedgedefinition.html) или [IEdgeDefinition](ksedgedefinition.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksOrientedEdgeCollection](ksorientededgecollection.html) или [IOrientedEdgeCollection](ksorientededgecollection.html).  
---|---  
  
Примечание:

Если параметр edge = NULL, то метод вернет весь массив. Если edge <> NULL, то будет возвращен массив ориентированных ребер, которые содержат данное ребро.

Подразделы:

(отсутствуют)
