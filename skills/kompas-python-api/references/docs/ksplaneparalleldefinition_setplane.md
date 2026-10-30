# SetPlane - Установить указатель на интерфейс плоскости, параллельно которой будет проходить новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Параллельная плоскость (Интерфейсы ksPlaneParallelDefinition, IPlaneParallelDefinition) ](ksplaneparalleldefinition.html) > [IPlaneParallelDefinition - методы ](ksplaneparalleldefinition_methods.html) |  Scroll [ [ [ ](ksplaneparalleldefinition_setpoint.html "К следующему разделу")](ksplaneparalleldefinition_methods.html "На уровень выше")](ksplaneparalleldefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplaneparalleldefinition.html)

Синтаксис Automation:

BOOL SetPlane (LPDISPATCH plane);

Синтаксис COM:

BOOL SetPlane (LPENTITY plane);

Входной параметр:

plane | \- указатель на интерфейс плоскости [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
