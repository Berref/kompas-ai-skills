# Интерфейс событий менеджера выделенных объектов ksSelectionMngNotify/ISelectionMngNotify

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) |  Scroll [ [ [ ](ksselectionmngnotify_events.html "К следующему разделу")](eventscommon.html "На уровень выше")](ksstampnotify_isnotifyprocess.html "К предыдущему разделу")  
---|---  
  
ksSelectionMngNotify | \- интерфейс Automation  
---|---  
ISelectionMngNotify | \- интерфейс COM  
  
Позволяют контролировать выделение объектов документа.

В Automation источник событий для графического документа SelectionMngNotify можно получить при помощи метода [ksDocument2D::GetSelectionMngNotify](ksdocument2d_getselectionmngnotify.html).

Для документа-модели источником является Менеджер выделенных объектов [ksSelectionMng](ksselectionmng.html).

В СOM контейнером для подписки на данный интерфейс является указатель на графический документ или документ-модель.

Подразделы:

[ISelectionMngNotify - события ](ksselectionmngnotify_events.html)

[ISelectionMngNotify - методы ](ksselectionmngnotify_methods.html)
