# ksConicArc - Построить коническое сечение

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksellipse.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_kscolouring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksConicArc](ksconicarc.html).

Синтаксис Automation:

long ksConicArc (LPDISPATCH param);

Входной параметр:

param | \- указатель на интерфейс конического сечения [ksConicArcParam](ksconicarcparam.html).  
---|---  
  
Возвращаемое значение:

указатель на коническое сечение | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Коническим сечением может быть дуга окружности, дуга эллипса или кривая NURBS.

Подразделы:

(отсутствуют)
