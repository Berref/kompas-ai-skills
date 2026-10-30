# AddProjectionOf - Добавить в эскиз проекцию объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы формообразующих операций ](int_operation.html) > [Эскиз (Интерфейсы ksSketchDefinition, ISketchDefinition) ](kssketchdefinition.html) > [ISketchDefinition - методы ](kssketchdefinition_methods.html) |  Scroll [ [ [ ](kssketchdefinition_beginedit.html "К следующему разделу")](kssketchdefinition_methods.html "На уровень выше")](kssketchdefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssketchdefinition.html)

Синтаксис Automation:

long AddProjectionOf (LPDISPATCH entity);

Синтаксис COM:

long AddProjectionOf (LPENTITY entity);

Входной параметр:

entity | \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на группу объектов, получившихся в результате проецирования.  
---|---  
  
Примечание:

1\. Данный метод работает только в режиме редактирования эскиза.

2\. Параметр entity может быть указателем на ребро, вершину или грань.

Подразделы:

(отсутствуют)
