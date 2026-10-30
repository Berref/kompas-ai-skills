# TransformObj - Преобразовать объект по установленной матрице

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](cn1724036.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](symmetryobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](transformobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksTransformObj](ksdocument2d_kstransformobj.html).

Синтаксис:

int TransformObj (reference ref);

Входной параметр:

ref | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Для работы с матрицами служат функции [Mtr](mtr.html) и [DeleteMtr](deletemtr.html).

Подразделы:

(отсутствуют)
