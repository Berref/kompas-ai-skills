# ksGetMacroPlacement - Получить точку привязки и угол поворота - систему координат макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksgetmacroplacementex.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksgetmacroparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetMacroPlacement](getmacroplacement.html).

Синтаксис Automation:

long ksGetMacroPlacement (long macro,

double* x,

double* y,

double* angl);

Входной параметр:

macro | \- указатель на макроэлемент (0 - редактируемый макроэлемент).  
---|---  
  
Выходные параметры:

x, y | \- координаты точки привязки,  
---|---  
angl | \- угол поворота от оси OX против часовой стрелки (в градусах).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи,  
-1 | \- у макроэлемента нет СК (не вызывалась функция [ksDocument2D::ksSetMacroPlacement](ksdocument2d_kssetmacroplacement.html)).  
  
Смотрите также:

Функция [ksDocument2D::ksSetMacroPlacement](ksdocument2d_kssetmacroplacement.html)

Подразделы:

(отсутствуют)
