# Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) > [События в КОМПАС Общие сведения ](eventscommon.html) |  Scroll [ [ [ ](ksobject3dnotify_events.html "К следующему разделу")](eventscommon.html "На уровень выше")](ksdocument3dnotify_isnotifyprocess.html "К предыдущему разделу")  
---|---  
  
ksObject3DNotify | \- интерфейс Automation  
---|---  
IObject3DNotify | \- интерфейс COM  
  
Позволяют контролировать редактирование объектов документа-модели.

В Automation источник событий для подписки [Object3DNotify](object3dnotify.html) можно получить при помощи метода [ksPart::GetObject3DNotify](object3dnotify.html).

В СOM контейнером для подписки является указатель на компонент - IPart.

Дополнительный параметр при подписке задает объекты, для которых предназначен данный интерфейс событий. Таким параметром является либо [тип объекта](obj3dtype.html) (o3d_unknown...o3d_sketch, o3d_axis2Planes...o3d_thread, o3d_part, o3d_feature), либо указатель на объект.

•Если задан тип объекта, события генерируются для всех объектов этого типа.

•Если задан указатель на объект, события генерируются только для этого объекта.

•Если задан тип объектов o3d_unknown, события генерируются для всех объектов.

В процессе обработки события можно получить информацию о редактировании объекта при помощи интерфейса [IObject3DNotifyResult](ksobject3dnotifyresult.html) для COM или [ksObject3DNotifyResult](ksobject3dnotifyresult.html) для Automation.

В Automation получить интерфейс результата можно при помощи метода [ksPart::GetObject3DNotifyResult](kspart_getobject3dnotifyresult.html).

В COM получить интерфейс результата можно при помощи экспортной функции [IPart::GetObject3DNotifyResult](kspart_getobject3dnotifyresult.html).

Подразделы:

[ksObject3DNotify - события ](ksobject3dnotify_events.html)

[IObject3DNotify - методы ](ksobject3dnotify_methods.html)
