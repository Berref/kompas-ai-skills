# StampCellBeginEdit - Начало редактирования в ячейке штампа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий основной надписи графического документа ksStampNotify/IStampNotify ](ksstampnotify.html) > [IStampNotify - события ](ksstampnotify_stampevents.html) |  Scroll [ [ [ ](ksstampnotify_stampcelldblclick.html "К следующему разделу")](ksstampnotify_stampevents.html "На уровень выше")](ksstampnotify_stampbeginclearcells.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstampnotify.html)

Синтаксис Automation:

BOOL StampCellBeginEdit (long number);

Входные параметры:

Number | \- номер редактируемой ячейки.  
---|---  
  
Возвращаемое значение:

TRUE | \- редактировать ячейку,  
---|---  
FALSE | \- редактирование ячейки запрещено.  
  
Синтаксис COM:

BOOL StampCellBeginEdit (long number);

Входные параметры:

Number | \- номер редактируемой ячейки.  
---|---  
  
Возвращаемое значение:

TRUE | \- редактировать ячейку,  
---|---  
FALSE | \- редактирование ячейки запрещено.  
  
Примечание:

Индекс события задан в [перечислении событий штампа...](ksstampnotifyenum.html).

Подразделы:

(отсутствуют)
