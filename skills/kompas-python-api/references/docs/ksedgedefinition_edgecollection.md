# EdgeCollection - Получить указатель на интерфейс массива ребер, стыкующихся с данным ребром

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Ребро (Интерфейсы ksEdgeDefinition, IEdgeDefinition) ](ksedgedefinition.html) > [IEdgeDefinition - методы ](ksedgedefinition_methods.html) |  Scroll [ [ [ ](ksedgedefinition_getadjacentface.html "К следующему разделу")](ksedgedefinition_methods.html "На уровень выше")](ksedgedefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksedgedefinition.html)

Синтаксис Automation:

LPDISPATCH EdgeCollection (BOOL begin);

Синтаксис COM:

LPEDGECOLLECTION EdgeCollection (BOOL begin);

Входные параметры:

begin | \- TRUE - в начале ребра, \- FALSE - в конце ребра.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEdgeCollection](ksedgecollection.html) или [IEdgeCollection](ksedgecollection.html).  
---|---  
  
Подразделы:

(отсутствуют)
