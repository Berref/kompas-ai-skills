# ksGetObjGabaritRect - Получить габаритный прямоугольник объекта

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Навигация ](bt1742269.html) |  Scroll [ [ [ ](ksdocument2d_ksgetviewobjcount.html "К следующему разделу")](bt1742269.html "На уровень выше")](bt1742269.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetObjGabaritRect](getobjgabaritrect.html).

Синтаксис Automation:

long ksGetObjGabaritRect (long p,

LPDISPATCH param);

Входные параметры:

p | \- указатель на объект,  
---|---  
param | \- указатель на интерфейс параметров прямоугольника [ksRectParam](ksrectparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Габаритный прямоугольник возвращается в координатах листа.

Подразделы:

(отсутствуют)
