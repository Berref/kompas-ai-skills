# ExistGroupObj - Проверить группу на наличие объектов

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](getgroup.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](excludeobjgroup.html "К предыдущему разделу")  
---|---  
  
[Пример...](existobj_existgroupobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksExistGroupObj](ksdocument2d_ksexistgroupobj.html).

Синтаксис:

int ExistGroupObj (reference group);

Входной параметр:

group | \- указатель на группу.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель группы равен нулю, то проверяется группа выделения (есть ли выделенные объекты документа).

Подразделы:

(отсутствуют)
