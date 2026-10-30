# SetBaseObj - Установить указатель на интерфейс объекта для сопряжения по номеру

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [Интерфейсы структуры параметров сопряжения (Интерфейсы ksMateConstraint, IMateConstraint) ](ksmateconstraint.html) > [IMateConstraint - методы ](ksmateconstraint_methods.html) |  Scroll [ [ [ ](kschoosemng.html "К следующему разделу")](ksmateconstraint_methods.html "На уровень выше")](ksmateconstraint_getfeature.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraint.html)

Синтаксис Automation:

BOOL SetBaseObj (short number, LPDISPATCH obj);

Синтаксис COM:

BOOL SetBaseObj (short number, LPENTITY obj);

Входные параметры:

number | \- номер объекта для сопряжения (1 или 2),  
---|---  
obj | \- указатель на интерфейс объекта для сопряжения [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
