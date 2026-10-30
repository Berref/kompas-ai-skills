# StampBeginClearCells - Начало очистки ячейки штампа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий основной надписи графического документа ksStampNotify/IStampNotify ](ksstampnotify.html) > [IStampNotify - события ](ksstampnotify_stampevents.html) |  Scroll [ [ [ ](ksstampnotify_stampcellbeginedit.html "К следующему разделу")](ksstampnotify_stampevents.html "На уровень выше")](ksstampnotify_endeditstamp.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstampnotify.html)

Синтаксис Automation:

BOOL StampBeginClearCells(VARIANT numbers);

Входные параметры:

numbers | \- список очищаемых ячеек.  
---|---  
  
Возвращаемое значение:

TRUE | \- редактировать ячейку,  
---|---  
FALSE | \- редактирование ячейки запрещено.  
  
Синтаксис COM:

BOOL StampBeginClearCells(VARIANT numbers);

Входные параметры:

Number | \- список очищаемых ячеек.  
---|---  
  
Возвращаемое значение:

TRUE | \- редактировать ячейку,  
---|---  
FALSE | \- редактирование ячейки запрещено.  
  
Примечание:

•Если очищается одна ячейка, то тип параметра numbers VT_I4.

•Если очищаются несколько ячеек, то передается массив SafeArray тип VT_ARRAY | VT_I4.

Подразделы:

(отсутствуют)
