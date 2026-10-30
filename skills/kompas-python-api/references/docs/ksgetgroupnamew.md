# ksGetGroupNameW - Получить имя группы по указателю на группу (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](ksmakeenclosecontoursex.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](ksgetgroupname.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetGroupName](ksdocument2d_ksgetgroupname.html).

Синтаксис:

int LIB_FUNC ksGetGroupNameW (reference gr,

LPWSTR name,

int size);

Входные параметры:

gr | \- указатель на группу,  
---|---  
name | \- указатель строки для имени группы,  
size | \- размер строки.  
  
Выходной параметр:

-1 | \- у группы есть имя, но размер size меньше требуемой длины имени группы (имя не передается),  
---|---  
0 | \- ошибка указания группы,  
1 | \- именная группа (имя есть),  
2 | \- рабочая группа (имени нет).  
  
Возвращаемое значение:

| строка с именем группы.  
---|---  
  
Примечание.

При использовании ANSI следует использовать функцию [ksGetGroupName](ksgetgroupname.html).

Подразделы:

(отсутствуют)
