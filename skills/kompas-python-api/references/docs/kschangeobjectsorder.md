# ksChangeObjectsOrder - Изменить порядок отрисовки объектов чертежа

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksclearregion.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kschangeobjectinlibrequestw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksChangeObjectsOrder](ksdocument2d_kschangeobjectsorder.html).

Синтаксис:

int ksChangeObjectsOrder (reference group, reference obj, int orderType);

Входной параметр:

obj | \- указатель на объект относительно которого изменяется отрисовка группы,  
---|---  
group | \- указатель на группу объектов, для которой требуется изменить последовательность отрисовки,  
orderType | \- [тип изменения порядка объектов](changeordertype.html).  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
