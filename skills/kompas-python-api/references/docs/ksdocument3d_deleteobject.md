# DeleteObject - Удалить объект: деталь, операцию, сопряжение

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_entitycollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_defaultplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL DeleteObject (LPDISPATCH obj);

Синтаксис COM:

BOOL DeleteObject (LPUNKNOWN obj);

Входной параметр:

obj | \- указатель на интерфейс IDispatch или IUnknown удаляемого объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечания:

1\. Удалить можно любой трехмерный объект.

2\. Если в качестве входного параметра переданы:

•поверхность [ksFaceDefinition](ksfacedefinition.html),

•ребро [ksEdgeDefinition](ksedgedefinition.html),

•вершина [ksVertexDefinition](ksvertexdefinition.html),

то будет удален весь формообразующий элемент, которому принадлежит удаляемый объект.

3\. Если в качестве входного параметра передано описание объекта, полученное методом [ksEntity::GetDefinition](ksentity_getdefinition.html), то после удаления недопустимо использование интерфейса описания удаленного объекта, породившего его интерфейса [ksEntity](ksentity.html) и других интерфейсов удаленного объекта.

Подразделы:

(отсутствуют)
