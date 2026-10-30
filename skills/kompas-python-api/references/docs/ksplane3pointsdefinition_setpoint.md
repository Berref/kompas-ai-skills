# SetPoint - Изменить указатель на интерфейс точки с указанным номером

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Плоскость через три вершины (Интерфейсы ksPlane3PointsDefinition, IPlane3PointsDefinition) ](ksplane3pointsdefinition.html) > [ksPlane3PointsDefinition - методы ](ksplane3pointsdefinition_methods.html) |  Scroll [ [ [ ](ksplanenormaltosurfacedefinition.html "К следующему разделу")](ksplane3pointsdefinition_methods.html "На уровень выше")](ksplane3pointsdefinition_getsurface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksplane3pointsdefinition.html)

Синтаксис Automation:

BOOL SetPoint (long number, LPDISPATCH point);

Синтаксис COM:

BOOL SetPoint (long number, LPENTITY point);

Входные параметры:

point | \- указатель на интерфейс точки [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
number | \- номер точки (от 1 до 3).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
