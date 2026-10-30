# BeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа; работа с файлом ksDocumentFileNotify/IDocumentFileNotify ](ksdocumentfilenotify.html) > [ksDocumentFileNotify/IDocumentFileNotify - события ](ksdocumentfilenotify_events.html) |  Scroll [ [ [ ](ksdocumentfilenotify_beginsavedocument.html "К следующему разделу")](ksdocumentfilenotify_events.html "На уровень выше")](ksdocumentfilenotify_beginprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocumentfilenotify.html)

Синтаксис Automation:

BOOL BeginSaveAsDocument();

Синтаксис COM:

BOOL BeginSaveAsDocument();

Возвращаемое значение:

TRUE | \- сохранить документ,  
---|---  
FALSE | \- документ сохранить нельзя.  
  
Примечание:

1\. Индекс события задан в перечислении событий [ksDocumentFileNotifyEnum](ksdocumentfilenotifyenum.html).

2\. В Automation источником событий для подписки на данный интерфейс являются объекты:

•[ksDoсument2D](ksdocument2d.html)[ (](ksdocument2d.html)[чертеж, фрагмент](ksdocument2d.html)[),](ksdocument2d.html)

•[ksSpcDocument](ksspcdocument.html)[ ](ksspcdocument.html)[(спецификация),](ksspcdocument.html)

•[ksDocumentTxt ](ksdocumenttxt.html)[(текстовый документ),](ksdocumenttxt.html)

•[ksDocument3D](ksdocument3d.html)[ (документ-модель).](ksdocument3d.html)

3\. В СOM источником событий для подписки на данный интерфейс является указатель на документ.

Подразделы:

(отсутствуют)
