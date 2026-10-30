# RemoveMateConstraint - Удалить сопряжение из сборки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_runtakecreateobjectproc.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_rebuilddocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL RemoveMateConstraint (long constraintType,

LPDISPATCH object1,

LPDISPATCH object2);

Синтаксис COM:

BOOL RemoveMateConstraint (unsigned int constraintType,

LPENTITY obj1,

LPENTITY obj2);

Входные параметры:

constraintType | \- тип сопряжения из перечисления [MateConstraintType](mateconstrainttype.html),  
---|---  
object1 | \- указатель на интерфейс первого объекта, на который наложено сопряжение ([ksEntity](ksentity.html) или [IEntity](ksentity.html)),  
object2 | \- указатель на интерфейс второго объекта, на который наложено сопряжение (ksEntity или ksEntity).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
