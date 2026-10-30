# ksPoint3DToAssociationView - Преобразовать координаты 3D точки в координаты ассоциативного вида

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kspolylinebyparam.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kspointintomtr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksPoint3DToAssociationView](kspoint3dtoassociationview.html).

Синтаксис Automation:

BOOL ksPoint3DToAssociationView (long view,

double x3D, double y3D, double z3D,

double * x2D, double * y2D );

Входные параметры:

view | \- указатель на ассоциативный вид,  
---|---  
x3D, y3D, z3D | \- координаты 3D точки.  
  
Выходные параметры:

x2D, y2D | \- координаты 3D точки в ассоциативном виде.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Если указатель на вид не задан (view = 0), то функция будет выполняться для текущего вида.

Подразделы:

(отсутствуют)
