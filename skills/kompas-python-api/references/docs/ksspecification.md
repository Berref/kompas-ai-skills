# Интерфейс спецификации ksSpecification

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) |  Scroll [ [ [ ](ksspecification_methods.html "К следующему разделу")](cb1747230.html "На уровень выше")](cb1747230.html "К предыдущему разделу")  
---|---  
  
[События...](ksspecificationnotify_events.html)

Интерфейс для работы со спецификацией.

Примечания:

1\. Для [Автоматизации](automation.html) используется интерфейс ksSpecification.

2\. Для COM используется интерфейс [ISpecification3D](ispecification3d.html) и группа экспортных функций. Указатель на интерфейс ISpecification3D можно получить из интерфейса [IDocument3D](ksdocument3d.html) через стандартную функцию QueryInterface.

3\. Указатель на интерфейс можно получить при помощи методов [ksDocument2D::GetSpecification](ksdocument2d_getspecification.html), [ksSpcDocument::GetSpecification](ksspcdocument_getspecification.html), [ksDocument3D::GetSpecification](ksdocument3d_getspecification.html).

4\. События интерфейса позволяют контролировать редактирование описаний спецификации. В Automation источником событий для подписки на данный интерфейс является объект ksSpecification. В COM источником для подписки является документ (графический, документ-модель, спецификация).

Смотрите также:

•[ksDocument2D](ksdocument2d.html),

•[ksDocument3D](ksdocument3d.html),

•[ksSpcDocument](ksspcdocument.html).

Подразделы:

[ksSpecification - методы ](ksspecification_methods.html)
