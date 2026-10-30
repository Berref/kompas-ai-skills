# BeginCreatePartFromFile - Начало создания компонента в сборке (до диалога выбора имени)

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html) > [IDocument3DNotify - события ](ksdocument3dnotify_events.html) |  Scroll [ [ [ ](idocument3dnotify_begindeletematerial.html "К следующему разделу")](ksdocument3dnotify_events.html "На уровень выше")](ksdocument3dnotify_beginchoiceproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify.html)

Синтаксис Automation:

BOOL BeginCreatePartFromFile (BOOL part, ksEntity * plane);

Синтаксис COM:

BOOL BeginCreatePartFromFile (BOOL part, LPENTITY plane);

Входные параметры:

part | TRUE - вставить деталь,  
---|---  
FALSE - вставить сборку,  
plane | \- плоскость, на которой создается деталь.  
  
Возвращаемое значение:

TRUE | \- создать компонент в сборке,  
---|---  
FALSE | \- создание компонента в сборке запрещено.  
  
Примечание:

Индекс метода задан в [перечислении событий документа-модели...](ksdocument3dnotifyenum.html).

Подразделы:

(отсутствуют)
