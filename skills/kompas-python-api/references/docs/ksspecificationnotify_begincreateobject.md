# BeginCreateObject - Начало расчета позиций

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий спецификации ksSpecificationNotify/ISpecificationNotify ](ksspecificationnotify.html) > [ISpecificationNotify - события ](ksspecificationnotify_events.html) |  Scroll [ [ [ ](ksspecificationnotify_calcpositions.html "К следующему разделу")](ksspecificationnotify_events.html "На уровень выше")](ksspecificationnotify_begincalcpositions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationnotify.html)

Синтаксис Automation:

BOOL BeginCreateObject (long typeObj);

Синтаксис COM:

BOOL BeginCreateObject (long typeObj);

Входные параметры:

0 | \- базовый объект,  
---|---  
1 | \- объект вспомогательный,  
-1 | \- тип объекта не определен.  
  
Возвращаемое значение:

TRUE | \- создать объект спецификации,  
---|---  
FALSE | \- создание объекта спецификации запрещены.  
  
Примечание:

Индекс метода установлен в [перечислении событий для спецификации...](ksspecificationnotifyenum.html).

Подразделы:

(отсутствуют)
