# Refresh - Обновить массив сопряжений

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Запрос к сиcтеме (Интерфейсы ksRequestInfo3D, IRequestInfo) ](ksrequestinfo3d.html) > [Массив сопряжений (Интерфейсы ksMateConstraintCollection, IMateConstraintCollection) ](ksmateconstraintcollection.html) > [IMateConstraintCollection - методы ](ksmateconstraintcollection_methods.html) |  Scroll [ [ [ ](ksmateconstraintcollection_removemateconstraint.html "К следующему разделу")](ksmateconstraintcollection_methods.html "На уровень выше")](ksmateconstraintcollection_prev.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmateconstraintcollection.html)

Синтаксис Automation:

BOOL Refresh();

Синтаксис COM:

BOOL Refresh();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод не работает для временного массива (полученного от [ksRequestInfo3D::GetMateConstraintCollection](ksrequestinfo3d_getmateconstraintcollection.html)).

Подразделы:

(отсутствуют)
