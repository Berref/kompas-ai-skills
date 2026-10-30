# ksClearGroup - Очистить группу

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с группами объектов ](cm1745630.html) > [Функции работы с группами объектов ](group_obj_fncts_common.html) |  Scroll [ [ [ ](ksgetgroupname.html "К следующему разделу")](group_obj_fncts_common.html "На уровень выше")](getgroupw.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscleargroup_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksClearGroup](ksdocument2d_kscleargroup.html).

Синтаксис:

int ksClearGroup (reference g,

unsigned char deleteTmp);

Входные параметры:

g | \- указатель на очищаемую группу (0 - очищается группа выделения),  
---|---  
deleteTmp | \- признак удаления временных элементов: 1 - временные элементы удаляются, 0 - временные элементы сохраняются.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
