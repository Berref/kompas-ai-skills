# SetVertex - Установить указатель на интерфейс опорной вершины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Интерфейсы объекта “Контрольная точка” - ksControlPointDefinition, IControlPointDefinition ](kscontrolpointdefinition.html) > [IControlPointDefinition - методы ](kscontrolpointdefinition_methods.html) |  Scroll [ [ [ ](ksconjunctivepointdefinition.html "К следующему разделу")](kscontrolpointdefinition_methods.html "На уровень выше")](kscontrolpointdefinition_getvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscontrolpointdefinition.html)

Синтаксис Automation:

VARIANT_BOOL SetVertex (LPDISPATCH Val);

Синтаксис COM:

BOOL SetVertex (LPENTITY Val);

Входной параметр:

Val | \- указатель на интерфейс опорной вершины [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Позволяет задать опорную вершину, на которой будет построена контрольная точка. Опорной вершиной может быть объект "вершина" (тип o3d_vertex).

Подразделы:

(отсутствуют)
