# GetVertex - Получить указатель на интерфейс опорной вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Контрольная точка” - ksControlPointDefinition, IControlPointDefinition ](kscontrolpointdefinition.html) > [IControlPointDefinition - методы ](kscontrolpointdefinition_methods.html) |  Scroll [ [ [ ](kscontrolpointdefinition_setvertex.html "К следующему разделу")](kscontrolpointdefinition_methods.html "На уровень выше")](kscontrolpointdefinition_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscontrolpointdefinition.html)

Синтаксис Automation:

LPDISPATCH GetVertex();

Синтаксис COM:

LPENTITY GetVertex();

Возвращаемое значение:

| \- указатель на интерфейс плоскости [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Примечание:

Возвращает указатель на интерфейс опорной вершины, на которой построена контрольная точка. Опорной вершиной может быть объект "вершина" (тип o3d_vertex).

Подразделы:

(отсутствуют)
