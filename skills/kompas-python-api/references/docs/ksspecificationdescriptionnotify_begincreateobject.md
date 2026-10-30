# BeginCreateObject - Начало создания объекта СП (до диалога выбора раздела)

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksSpecificationDescriptionNotify ](ksspecificationdescriptionnotify.html) > [ksSpecificationDescriptionNotify - события ](ksspecificationdescriptionnotify_events.html) |  Scroll [ [ [ ](ksspecificationdescriptionnotify_calcpositions.html "К следующему разделу")](ksspecificationdescriptionnotify_events.html "На уровень выше")](ksspecificationdescriptionnotify_begincalcpositions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecificationdescriptionnotify.html)

Синтаксис Automation:

BOOL BeginCreateObject (long typeObj);

Входные параметры:

typeObj | 0 - базовый объект, 1 - объект вспомогательный, -1 - тип объекта не определен.  
---|---  
  
Возвращаемое значение:

TRUE | \- создать объект спецификации,  
---|---  
FALSE | \- запрещает создание объекта спецификации.  
  
Примечание:

Индекс события задан в перечислении событий для для Менеджера библиотек [ksSpecificationNotifyEnum](ksspecificationnotifyenum.html).

Подразделы:

(отсутствуют)
