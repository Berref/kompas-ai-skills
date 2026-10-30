# SetEdge - Установить указатель на интерфейс ребра, через которое будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость через ребро параллельно/перпендикулярно грани (Интерфейсы ksPlaneLineToPlaneDefinition, IPlaneLineToPlaneDefinition) ](ksplanelinetoplanedefinition.html) > [IPlaneLineToPlaneDefinition - методы ](ksplanelinetoplanedefinition_methods.html) |  Scroll [ [ [ ](ksplanelinetoplanedefinition_setplane.html "К следующему разделу")](ksplanelinetoplanedefinition_methods.html "На уровень выше")](ksplanelinetoplanedefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanelinetoplanedefinition.html)

Синтаксис Automation:

BOOL SetEdge (LPDISPATCH edge);

Синтаксис COM:

BOOL SetEdge (LPENTITY edge);

Входной параметр:

edge | \- указатель на интерфейс ребра [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
