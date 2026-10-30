# MoveObj - Сдвинуть объект

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](placementex.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](lightobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](moveobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksMoveObj](ksdocument2d_ksmoveobj.html).

Синтаксис:

int MoveObj (reference obj, double dx, double dy);

Входные параметры:

obj | \- указатель на объект,  
---|---  
dx, dy | \- вектор смещения объекта.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель obj равен нулю, то сдвигаются выделенные объекты документа.

Подразделы:

(отсутствуют)
