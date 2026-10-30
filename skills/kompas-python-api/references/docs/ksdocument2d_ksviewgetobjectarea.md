# ksViewGetObjectArea - Получить группу графических объектов, определяющих область выделения, используя визуальный процесс

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Группы объектов ](bt1732733.html) |  Scroll [ [ [ ](bt1734633.html "К следующему разделу")](bt1732733.html "На уровень выше")](ksdocument2d_ksstoretmpgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksViewGetObjectArea](ksviewgetobjectarea.html).

Синтаксис Automation:

long ksViewGetObjectArea();

Возвращаемое значение:

указатель на временную группу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Так как сиcтема может работать только с одним процессом, то нужно завершить другие процессные функции: [ksDocument2D::ksCursor](ksdocument2d_kscursor.html), [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html), [ksDocument2D::ksCommandWindow](ksdocument2d_kscommandwindow.html), [ksDocument2D::ksEditViewObject](ksdocument2d_kseditviewobject.html).

Подразделы:

(отсутствуют)
