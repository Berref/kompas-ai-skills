# GetObjGabaritRect - Получить габаритный прямоугольник объекта

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Навигация по графическому документу ](cm1745694.html) > [Функции навигации ](navigation_fncts.html) |  Scroll [ [ [ ](getviewobjcount.html "К следующему разделу")](navigation_fncts.html "На уровень выше")](findobj.html "К предыдущему разделу")  
---|---  
  
[Пример...](getobjgabaritrect_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetObjGabaritRect](ksdocument2d_ksgetobjgabaritrect.html).

Синтаксис:

int GetObjGabaritRect (reference p, RectParam *par);

Входные параметры:

p | \- указатель на объект,  
---|---  
par | \- указатель на структуру размеров габаритного прямоугольника [RectParam](structrectparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Габаритный прямоугольник возвращается в координатах листа.

Подразделы:

(отсутствуют)
