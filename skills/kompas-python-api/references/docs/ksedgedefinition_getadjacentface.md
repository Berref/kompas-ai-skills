# GetAdjacentFace - Получить указатель на интерфейс грани, в цикл которой входит ребро

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Ребро (Интерфейсы ksEdgeDefinition, IEdgeDefinition) ](ksedgedefinition.html) > [IEdgeDefinition - методы ](ksedgedefinition_methods.html) |  Scroll [ [ [ ](ksedgedefinition_getcurve3d.html "К следующему разделу")](ksedgedefinition_methods.html "На уровень выше")](ksedgedefinition_edgecollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksedgedefinition.html)

Синтаксис Automation:

LPDISPATCH GetAdjacentFace (BOOL facePlus );

Синтаксис COM:

LPFACEDEFINITION GetAdjacentFace (BOOL facePlus );

Входные параметры:

facePlus | \- TRUE - ориентация грани относительно отрезка положительная, \- FALSE - ориентация грани относительно отрезка отрицательная.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksFaceDefinition](ksfacedefinition.html) или [IFaceDefinition](ksfacedefinition.html).  
---|---  
  
Подразделы:

(отсутствуют)
