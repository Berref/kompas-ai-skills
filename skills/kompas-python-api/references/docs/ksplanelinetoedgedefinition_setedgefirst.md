# SetEdgeFirst - Установить указатель на интерфейс первого ребра, через которое будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость через ребро параллельно/перпендикулярно другому ребру (Интерфейсы ksPlaneLineToEdgeDefinition, IPlaneLineToEdgeDefinition) ](ksplanelinetoedgedefinition.html) > [ksPlaneLineToEdgeDefinition - методы ](ksplanelinetoedgedefinition_methods.html) |  Scroll [ [ [ ](ksplanelinetoedgedefinition_setedgesecond.html "К следующему разделу")](ksplanelinetoedgedefinition_methods.html "На уровень выше")](ksplanelinetoedgedefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanelinetoedgedefinition.html)

Синтаксис Automation:

BOOL SetEdgeFirst (LPDISPATCH edge1);

Синтаксис COM:

BOOL SetEdgeFirst (LPENTITY edge1);

Входной параметр:

edge1 | \- указатель на интерфейс ребра [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
