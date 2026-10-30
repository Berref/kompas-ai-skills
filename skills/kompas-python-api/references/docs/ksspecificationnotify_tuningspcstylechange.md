# TuningSpcStyleChange - Настройки спецификации изменились

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий спецификации ksSpecificationNotify/ISpecificationNotify ](ksspecificationnotify.html) > [ISpecificationNotify - события ](ksspecificationnotify_events.html) |  Scroll [ [ [ ](ksspecificationnotify_methods.html "К следующему разделу")](ksspecificationnotify_events.html "На уровень выше")](ksspecificationnotify_tuningspcstylebeginchange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationnotify.html)

Синтаксис Automation:

BOOL TuningSpcStyleChange (BSTR libName, long numb, BOOL isOk);

Синтаксис COM:

BOOL TuningSpcStyleChange (char * libName, long numb, BOOL isOk);

Входные параметры:

libName | \- имя библиотеки стилей спецификации,  
---|---  
numb | \- номер стиля спецификации,  
isOk | \- результат изменения настроек спецификации.  
  
Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

Индекс метода установлен в [перечислении событий для спецификации...](ksspecificationnotifyenum.html).

Подразделы:

(отсутствуют)
