# SetEdge - Установить указатель на интерфейс ребра, перпендикулярно которому будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость перпендикулярная ребру (Интерфейсы ksPlanePerpendicularDefinition, IPlanePerpendicularDefinition) ](ksplaneperpendiculardefinition.html) > [IPlanePerpendicularDefinition - методы ](ksplaneperpendiculardefinition_methods.html) |  Scroll [ [ [ ](ksplaneperpendiculardefinition_setpoint.html "К следующему разделу")](ksplaneperpendiculardefinition_methods.html "На уровень выше")](ksplaneperpendiculardefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplaneperpendiculardefinition.html)

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
