# RotateObj - Повернуть объект

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](setobjparam.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](placementexw.html "К предыдущему разделу")  
---|---  
  
[Пример...](rotateobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksRotateObj](ksdocument2d_ksrotateobj.html).

Синтаксис:

int RotateObj (reference obj, double xc, double yc, double ang);

Входные параметры:

obj | \- указатель на объект,  
---|---  
xc, yc | \- координаты центра поворота,  
ang | \- угол поворота (в градусах).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель obj равен нулю, то поворачиваются выделенные объекты документа.

Подразделы:

(отсутствуют)
