# ksEditViewObject - Запустить визуальный процесс редактирования объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Редактирование графических объектов ](bt1730357.html) |  Scroll [ [ [ ](ksdocument2d_ksexistobj.html "К следующему разделу")](bt1730357.html "На уровень выше")](bt1730357.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksEditViewObject](kseditviewobject.html).

Синтаксис Automation:

int ksEditViewObject (long ref);

Входной параметр:

ref | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- объект отредактирован,  
---|---  
0 | \- объект не отредактирован.  
  
Примечание:

Так как сиcтема может работать только с одним процессом, требуется завершить другие процессные функции: [ksDocument2D::ksCursor](ksdocument2d_kscursor.html) [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html), [ksDocument2D::ksCommandWindow](ksdocument2d_kscommandwindow.html), [ksDocument2D::ksCreateViewObject](ksdocument2d_kscreateviewobject.html).

Подразделы:

(отсутствуют)
