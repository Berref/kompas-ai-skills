# ksMoveObj - Сдвинуть объект

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_ksreadgroupfromclip.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_ksenableundo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [MoveObj](moveobj.html).

Синтаксис Automation:

long ksMoveObj (long ref,

double dx,

double dy);

Входные параметры:

ref | \- указатель на объект,  
---|---  
dx, dy | \- вектор смещения объекта.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель ref равен нулю, то сдвигаются выделенные объекты документа.

Подразделы:

(отсутствуют)
