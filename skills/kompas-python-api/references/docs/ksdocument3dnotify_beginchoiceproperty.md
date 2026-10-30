# BeginChoiceProperty - Начало выбора свойства

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) > [Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html) > [IDocument3DNotify - события ](ksdocument3dnotify_events.html) |  Scroll [ [ [ ](ksdocument3dnotify_begincreatepartfromfile.html "К следующему разделу")](ksdocument3dnotify_events.html "На уровень выше")](ksdocument3dnotify_beginchoicematerial.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3dnotify.html)

Синтаксис Automation:

BOOL BeginChoiceProperty( LPDISPATCH obj, double propID );

Синтаксис COM:

BOOL BeginChoiceProperty( LPUNKNOWN obj, double propID );

Возвращаемое значение:

TRUE | \- Разрешить стандартную процедуру выбора свойства,  
---|---  
FALSE | \- Запретить стандартную процедуру выбора свойства (библиотека самостоятельно обработала выбор свойства).  
  
Подразделы:

(отсутствуют)
