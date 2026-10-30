# ksUpdateMacro - Очистить макроэлемент и положить в него группу

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](bt1730613.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_kssetmacrowaitdblclickedit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksUpdateMacro](ksupdatemacro.html).

Синтаксис Automation:

long ksUpdateMacro (long macro, long gr);

Входные параметры:

macro | \- указатель на макроэлемент,  
---|---  
gr | \- указатель на группу.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод удаляет всю геометрию макроэлемента.

Подразделы:

(отсутствуют)
