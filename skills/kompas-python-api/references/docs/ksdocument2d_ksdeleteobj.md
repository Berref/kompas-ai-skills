# ksDeleteObj - Удалить объект

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_ksenableundo.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_ksdecomposeobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [DeleteObj](deleteobj.html).

Синтаксис Automation:

long ksDeleteObj (long ref);

Входной параметр:

ref | \- указатель на объект.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель ref равен нулю, то удаляются выделенные объекты документа.

Подразделы:

(отсутствуют)
