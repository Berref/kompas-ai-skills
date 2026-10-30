# AddMateConstraint - Добавить сопряжение в сборку

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_attributecollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_addimportedsurfaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL AddMateConstraint (long constraintType,

LPDISPATCH object1,

LPDISPATCH object2,

short direction,

short fixed,

double value);

Синтаксис COM:

BOOL AddMateConstraint (long constraintType,

LPENTITY obj1,

LPENTITY obj2,

short direction,

short fixed,

double val);

Входные параметры:

constraintType | \- тип сопряжения из перечисления [MateConstraintType](mateconstrainttype.html),  
---|---  
object1 | \- указатель на интерфейс первого объекта, на который накладывается сопряжение ([ksEntity](ksentity.html) или [IEntity](ksentity.html)),  
object2 | \- указатель на интерфейс второго объекта, на который накладывается сопряжение (ksEntity или iEntity),  
direction | \- ориентация (1 - объекты однонаправленные, 0 - направление не учитывается, -1 - объекты разнонаправленные),  
fixed | \- признак фиксации деталей перед выполнением (0 - детали не фиксируются, 1 - фиксируется первая деталь, 2 - фиксируется вторая деталь),  
val | \- параметр для ограничений (расстояние или угол между объектами).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Примечание:

Направление задаётся знаком параметра val.

Подразделы:

(отсутствуют)
