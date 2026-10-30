# ksTrimNurbs - Усечь NURBS

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Операции редактирования ](bt1734633.html) |  Scroll [ [ [ ](ksdocument2d_kstrimmcurve.html "К следующему разделу")](bt1734633.html "На уровень выше")](ksdocument2d_kstransformobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksTrimNurbs](kstrimnurbs.html).

Синтаксис Automation:

long ksTrimNurbs (long pObj,

double tMin,

double tMax );

Входные параметры:

pObj | \- указатель на кривую NURBS или 0 для создаваемой кривой NURBS,  
---|---  
tMin, tMax | \- границы интервала для усечения.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
