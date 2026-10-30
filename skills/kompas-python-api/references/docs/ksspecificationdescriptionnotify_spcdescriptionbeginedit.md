# SpcDescriptionBeginEdit - Начало редактирования описания спецификации

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationDescriptionNotify ](ksspecificationdescriptionnotify.html) > [ksSpecificationDescriptionNotify - события ](ksspecificationdescriptionnotify_events.html) |  Scroll [ [ [ ](ksspecificationdescriptionnotify_spcdescriptionedit.html "К следующему разделу")](ksspecificationdescriptionnotify_events.html "На уровень выше")](ksspecificationdescriptionnotify_spcdescriptionadd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationdescriptionnotify.html)

Синтаксис Automation:

BOOL SpcDescriptionBeginEdit (ISpecificationDescription * Descr);

Входные параметры:

Descr | \- указатель на интерфейс [ISpecificationDescription](ispecificationdescription.html) редактируемого описания спецификации.  
---|---  
  
Возвращаемое значение:

TRUE | \- редактировать описание спецификации,  
---|---  
FALSE | \- запрещает редактирование описания спецификации.  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksSpecificationNotifyEnum](ksspecificationnotifyenum.html).

Подразделы:

(отсутствуют)
