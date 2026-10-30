# SetPoint - Изменить указатель на интерфейс точки с указанным номером

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы вспомогательной геометрии ](int_geometry.html) > [Ось через две точки (Интерфейсы ksAxis2PointsDefinition,IAxis2PointsDefinition) ](ksaxis2pointsdefinition.html) > [ksAxis2PointsDefinition - методы ](ksaxis2pointsdefinition_methods.html) |  Scroll [ [ [ ](ksaxis2planesdefinition.html "К следующему разделу")](ksaxis2pointsdefinition_methods.html "На уровень выше")](ksaxis2pointsdefinition_getpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksaxis2pointsdefinition.html)

Синтаксис Automation:

BOOL SetPoint (long number, LPDISPATCH point);

Синтаксис COM:

BOOL SetPoint (long number, LPENTITY point);

Входные параметры:

point | \- указатель на интерфейс точки [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
number | \- номер точки (1 или 2).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
