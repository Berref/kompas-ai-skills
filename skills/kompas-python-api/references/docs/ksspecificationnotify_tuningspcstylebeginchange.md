# TuningSpcStyleBeginChange - Начало изменения настроек спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий спецификации ksSpecificationNotify/ISpecificationNotify ](ksspecificationnotify.html) > [ISpecificationNotify - события ](ksspecificationnotify_events.html) |  Scroll [ [ [ ](ksspecificationnotify_tuningspcstylechange.html "К следующему разделу")](ksspecificationnotify_events.html "На уровень выше")](ksspecificationnotify_synchronizationbegin.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationnotify.html)

Синтаксис Automation:

BOOL TuningSpcStyleBeginChange (BSTR libName, long numb);

Синтаксис COM:

BOOL TuningSpcStyleBeginChange (char * libName, long numb);

Входные параметры:

libName | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации.  
  
Возвращаемое значение:

TRUE | \- изменить настройки спецификации,  
---|---  
FALSE | \- изменение настроек спецификации запрещено.  
  
Примечание:

Индекс метода установлен в [перечислении событий для спецификации...](ksspecificationnotifyenum.html).

Подразделы:

(отсутствуют)
