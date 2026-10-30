# SetEdgeSecond - Установить указатель на интерфейс второго ребра, параллельно или перпендикулярно которому будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость через ребро параллельно/перпендикулярно другому ребру (Интерфейсы ksPlaneLineToEdgeDefinition, IPlaneLineToEdgeDefinition) ](ksplanelinetoedgedefinition.html) > [ksPlaneLineToEdgeDefinition - методы ](ksplanelinetoedgedefinition_methods.html) |  Scroll [ [ [ ](ksplaneangledefinition.html "К следующему разделу")](ksplanelinetoedgedefinition_methods.html "На уровень выше")](ksplanelinetoedgedefinition_setedgefirst.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanelinetoedgedefinition.html)

Синтаксис Automation:

BOOL SetEdgeSecond (LPDISPATCH edge2);

Синтаксис COM:

BOOL SetEdgeSecond (LPENTITY edge2);

Входной параметр:

edge2 | \- указатель на интерфейс ребра [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
