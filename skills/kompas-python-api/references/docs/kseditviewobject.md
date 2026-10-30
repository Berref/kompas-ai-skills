# ksEditViewObject - Запустить визуальный процесс редактирования объекта

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksgetcurveperpendicularbyt.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](destroyobjects.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscreateviewobject_kseditviewobject_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksEditViewObject](ksdocument2d_kseditviewobject.html).

Синтаксис:

int ksEditViewObject(reference obj);

Входной параметр:

obj | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- объект отредактирован,  
---|---  
0 | \- объект не отредактирован.  
  
Примечание:

Функция распространяется на все объекты вида кроме:

LAYER_OBJ | \- слой,  
---|---  
CONTOUR_OBJ | \- контур,  
MACRO_OBJ | \- нетипизированный макроэлемент,  
FRAGMENT_OBJ | \- вставной фрагмент,  
ELLIPSE_ARC_OBJ | \- дуга эллипса.  
  
Подразделы:

(отсутствуют)
