# ksViewGetObjectArea - Получить группу графических объектов, определяющих область выделения, используя визуальный процесс

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](newgroup.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](ksmakeenclosecontoursex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksviewgetobjectarea_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksViewGetObjectArea](ksdocument2d_ksviewgetobjectarea.html).

Синтаксис:

reference ksViewGetObjectArea();

Возвращаемое значение:

указатель на временную группу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Так как сиcтема может работать только с одним процессом, нужно завершить другие процессные функции: [Cursor](cursor.html), [Placement](placement.html), [CommandWindow](commandwindow.html), [ksEditViewObject](kseditviewobject.html).

Подразделы:

(отсутствуют)
