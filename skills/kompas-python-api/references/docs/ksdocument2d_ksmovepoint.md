# ksMovePoint - Сдвинуть точку в указанном направлении на указанное расстояние

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksparametrizeobjects.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksmakeenclosecontoursex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [MovePoint](movepoint.html).

Синтаксис Automation:

BOOL ksMovePoint (double* x,

double* y,

double ang,

double len);

Входные параметры:

x, y | \- координаты точки,  
---|---  
ang | \- угол вектора сдвига в градусах,  
len | \- длина вектора сдвига.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Параметры x и y являются одновременно и входными, и выходными. На входе они представляют собой начальные координаты точки, а в результате работы метода они преобразуются в координаты точки после сдвига.

Подразделы:

(отсутствуют)
