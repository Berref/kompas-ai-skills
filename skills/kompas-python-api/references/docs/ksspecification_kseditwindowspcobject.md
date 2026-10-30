# ksEditWindowSpcObject - Запустить окно редактирования для объекта спецификации, существующего в графическом документе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetcurrentspcobject.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksdeletespcdescription.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksEditWindowSpcObject](kseditwindowspcobject.html).

Синтаксис Automation:

long ksEditWindowSpcObject (long obj);

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

Метод запускает процесс. Так как сиcтема может работать только с одним процессом, то нужно завершить другие "процессные" функции: [ksDocument2D::ksCursor](ksdocument2d_kscursor.html), [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html), [ksDocument2D::ksCommandWindow](ksdocument2d_kscommandwindow.html), [ksDocument2D::ksEditViewObject](ksdocument2d_kseditviewobject.html), [ksDocument2D::ksCreateViewObject](ksdocument2d_kscreateviewobject.html).

Подразделы:

(отсутствуют)
