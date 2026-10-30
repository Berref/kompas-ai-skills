# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [IMateConstraintCollection - методы ](ksmateconstraintcollection_methods.html) |  Scroll [ [ [ ](ksmateconstraintcollection_first.html "К следующему разделу")](ksmateconstraintcollection_methods.html "На уровень выше")](ksmateconstraintcollection_getsafearraybyobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraintcollection.html)

Синтаксис Automation:

long FindIt (LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPMATECONSTRAINT entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс [ksMateConstraint](ksmateconstraint.html) или [IMateConstraint](ksmateconstraint.html).  
---|---  
  
Подразделы:

(отсутствуют)
