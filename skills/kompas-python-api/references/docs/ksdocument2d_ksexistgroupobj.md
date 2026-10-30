# ksExistGroupObj - Проверить группу на наличие объектов

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Группы объектов ](bt1732733.html) |  Scroll [ [ [ ](ksdocument2d_ksgetgroup.html "К следующему разделу")](bt1732733.html "На уровень выше")](ksdocument2d_ksexcludeobjgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ExistGroupObj](existgroupobj.html).

Синтаксис Automation:

long ksExistGroupObj (long group);

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
