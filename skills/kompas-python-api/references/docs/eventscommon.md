# События в КОМПАС Общие сведения

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы событий API5 ](af1881424.html) |  Scroll [ [ [ ](kskompasobjectnotify5.html "К следующему разделу")](af1881424.html "На уровень выше")](af1881424.html "К предыдущему разделу")  
---|---  
  
Генерация событий в КОМПАС осуществляется при помощи компактных интерфейсов событий, в которых события группируются по тематике. Подписка на события проводится во время подключения библиотеки при помощи предопределенной функции [LibInterfaceNotifyEntry()](libinterfacenotifyentry.html).

Для Automation реализация основана на стандартном механизме ConnectionPoint. Основные объекты, такие как [KompasObject](kompasobject.html), [ksDocument2D](ksdocument2d.html) и т.п., которые являются источниками событий, наследуют интерфейс IConnectionPointContainer, позволяют подписаться на один основной интерфейс и предоставляют дополнительные объекты-источники событий. Подписаться на события или отменить подписку можно стандартным способом при помощи методов интерфейса IConnectionPoint: IConnectionPoint::Advise и IConnectionPoint::Unadvise.

Для COM реализация основана на интерфейсах IUnknown, которые предоставляет библиотека. Подписаться на события или отменить подписку можно при помощи экспортных функций: [ksConnectionAdvise](ksconnectionadvise.html) и [ksConnectionUnadvise](ksconnectionunadvise.html).

Библиотека сама должна позаботиться о своевременной отписке от неактуальных событий. Например, в момент закрытия документа нужно обработать соответствующее событие и отписаться от всех событий, связанных с данным документом (см. таблицу связей). При закрытии приложения следует отписаться от всех событий.

[Интерфейс событий приложения...](kskompasobjectnotify.html)

[Интерфейс событий документа, работа с файлом...](ksdocumentfilenotify.html)

[Интерфейс событий документа-модели...](ksdocument3dnotify.html)

[Интерфейс событий графического документа...](ksdocument2dnotify.html)

[Интерфейс событий менеджера выделенных объектов...](ksselectionmngnotify.html)

[Интерфейс событий объектов графического документа...](ksobject2dnotify.html)

[Интерфейс событий объектов документа-модели...](ksobject3dnotify.html)

[Интерфейс событий основной надписи графического документа...](ksstampnotify.html)

[Интерфейс событий объекта спецификации...](ksspcobjectnotify.html)

[Интерфейс событий спецификации...](ksspecificationnotify.html)

[Интерфейс событий документа-спецификации...](ksspcdocumentnotify.html)

[Связь объектов системы с интерфейсами событий...](events_interfaces_links.html)

Подразделы:

[Интерфейс событий приложения ksKompasObjectNotify/IKompasObjectNotify ](kskompasobjectnotify5.html)

[Интерфейс событий документа; работа с файлом ksDocumentFileNotify/IDocumentFileNotify ](ksdocumentfilenotify.html)

[Интерфейсы событий графического документа ksDocument2DNotify/ IDocument2DNotify ](ksdocument2dnotify.html)

[Интерфейс событий объектов графических документов ksObject2DNotify/ IObject2DNotify ](ksobject2dnotify.html)

[Интерфейс событий документа-модели ksDocument3DNotify/IDocument3DNotify ](ksdocument3dnotify.html)

[Интерфейс событий документа-модели ksObject3DNotify/IObject3DNotify ](ksobject3dnotify.html)

[Интерфейс событий основной надписи графического документа ksStampNotify/IStampNotify ](ksstampnotify.html)

[Интерфейс событий менеджера выделенных объектов ksSelectionMngNotify/ISelectionMngNotify ](ksselectionmngnotify.html)

[Интерфейс событий документа-спецификации ksSpcDocumentNotify/ISpcDocumentNotify ](ksspcdocumentnotify.html)

[Интерфейс событий спецификации ksSpecificationNotify/ISpecificationNotify ](ksspecificationnotify.html)

[Интерфейс событий объекта спецификации ksSpcObjectNotify/ISpcObjectNotify ](ksspcobjectnotify.html)

[Интерфейс дополнительных параметров для событий документа-модели ksDocument3DNotifyResult/IDocument3DNotifyResult ](ksdocument3dnotifyresult.html)
