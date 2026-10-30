# SetPlane - Установить указатель на интерфейс плоского объекта, параллельно которому должна пройти новая плоскость

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Нормальная плоскость (Интерфейсы ksPlaneNormalToSurfaceDefinition, IPlaneNormalToSurfaceDefinition) ](ksplanenormaltosurfacedefinition.html) > [IPlaneNormalToSurfaceDefinition - методы ](ksplanenormaltosurfacedefinition_methods.html) |  Scroll [ [ [ ](ksplaneperpendiculardefinition.html "К следующему разделу")](ksplanenormaltosurfacedefinition_methods.html "На уровень выше")](ksplanenormaltosurfacedefinition_setface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplanenormaltosurfacedefinition.html)

Синтаксис Automation:

BOOL SetPlane (LPDISPATCH plane);

Синтаксис COM:

BOOL SetPlane (LPENTITY plane);

Входной параметр:

plane | \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
