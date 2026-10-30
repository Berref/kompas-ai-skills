# ksCreateViewObject - Создать объект заданного типа, используя визуальный процесс создания объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kscursor.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kscopyobjex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateViewObject](kscreateviewobject.html).

Синтаксис Automation:

long ksCreateViewObject (long type);

Входной параметр:

type | \- тип объекта.  
---|---  
  
[Типы объектов и интерфейсы...](objtypes.html)

Возвращаемое значение:

указатель на созданный объект | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод распространяется на все объекты вида, кроме слоя, контура, нетипизированного макроэлемента, вставленного фрагмента и дуги эллипса.

Так как сиcтема может работать только с одним процессом, то нужно завершить другие "процессные" методы: [ksDocument2D::ksCursor](ksdocument2d_kscursor.html), [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html), [ksDocument2D::ksCommandWindow](ksdocument2d_kscommandwindow.html).

Подразделы:

(отсутствуют)
