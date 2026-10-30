# SaveDocument - Документ сохранен

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа; работа с файлом ksDocumentFileNotify/IDocumentFileNotify ](ksdocumentfilenotify.html) > [ksDocumentFileNotify/IDocumentFileNotify - события ](ksdocumentfilenotify_events.html) |  Scroll [ [ [ ](ksdocumentfilenotify_methods.html "К следующему разделу")](ksdocumentfilenotify_events.html "На уровень выше")](ksdocumentfilenotify_processdeactivate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentfilenotify.html)

Синтаксис Automation:

BOOL SaveDocument();

Синтаксис COM:

BOOL SaveDocument();

Возвращаемое значение:

| \- не используется.  
---|---  
  
Примечание:

1\. Индекс события задан в [перечислении событий документа...](ksdocumentfilenotifyenum.html).

2\. В Automation источником событий для подписки на данный интерфейс являются объекты:

•[ksDoсument2D](ksdocument2d.html)[ (чертеж, фрагмент),](ksdocument2d.html)

•[ksSpcDocument](ksspcdocument.html) (спецификация),

•[ksDocumentTxt](ksdocumenttxt.html) (текстовый документ),

•[ksDocument3D](ksdocument3d.html) (документ-модель).

3\. В СOM источником для подписки на данный интерфейс является указатель на документ.

Подразделы:

(отсутствуют)
