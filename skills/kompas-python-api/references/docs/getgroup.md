# GetGroup - Получить указатель на группу по ее имени

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](getgroupw.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](existgroupobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](getgroup_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetGroup](ksdocument2d_ksgetgroup.html).

Синтаксис:

reference GetGroup (char *name);

Входной параметр:

name | \- имя группы.  
---|---  
  
Возвращаемое значение:

указатель на группу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [GetGroupW](getgroupw.html).

Подразделы:

(отсутствуют)
