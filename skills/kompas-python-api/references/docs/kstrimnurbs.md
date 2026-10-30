# ksTrimNurbs - Усечь NURBS

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](ksundocontainer.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kstrimcurve.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksTrimNurbs](ksdocument2d_kstrimnurbs.html).

Синтаксис:

int ksTrimNurbs (reference pObj,

double tMin, double tMax);

Входные параметры:

pObj | \- указатель на кривую NURBS или 0 для создаваемой кривой NURBS.  
---|---  
tMin, tMax | \- границы интервала для усечения.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
