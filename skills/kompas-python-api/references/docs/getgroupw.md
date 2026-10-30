# GetGroupW - Получить указатель на группу по ее имени (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](kscleargroup.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](getgroup.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetGroup](ksdocument2d_ksgetgroup.html).

Синтаксис:

reference LIB_FUNC GetGroupW (LPWSTR name);

Входной параметр:

name | \- имя группы.  
---|---  
  
Возвращаемое значение:

указатель на группу | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [GetGroup](getgroup.html).

Подразделы:

(отсутствуют)
