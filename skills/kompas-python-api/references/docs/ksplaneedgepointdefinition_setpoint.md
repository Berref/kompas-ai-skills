# SetPoint - Установить указатель на интерфейс вершины, через которую требуется построить плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость через ребро и вершину (Интерфейсы ksPlaneEdgePointDefinition,IPlaneEdgePointDefinition) ](ksplaneedgepointdefinition.html) > [IPlaneEdgePointDefinition - методы ](ksplaneedgepointdefinition_methods.html) |  Scroll [ [ [ ](ksplanemiddledefinition.html "К следующему разделу")](ksplaneedgepointdefinition_methods.html "На уровень выше")](ksplaneedgepointdefinition_setedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplaneedgepointdefinition.html)

Синтаксис Automation:

BOOL SetPoint (LPDISPATCH point);

Синтаксис COM:

BOOL SetPoint (LPENTITY point);

Входной параметр:

point | \- указатель на интерфейс вершины [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
