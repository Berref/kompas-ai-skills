# DeleteObj - Удалить объект

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](existobj.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](decomposeobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](deleteobj_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksDeleteObj](ksdocument2d_ksdeleteobj.html).

Синтаксис:

int DeleteObj (reference obj);

Входной параметр:

obj | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель obj равен нулю, то удаляются выделенные объекты документа.

Подразделы:

(отсутствуют)
