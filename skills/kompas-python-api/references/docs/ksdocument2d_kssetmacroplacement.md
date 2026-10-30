# ksSetMacroPlacement - Установить точку привязки и угол поворота - систему координат макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_kssetmacroplacementex.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_kssetmacroparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [SetMacroPlacement](setmacroplacement.html).

Синтаксис Automation:

long ksSetMacroPlacement (long macro,

double x,

double y,

double angl,

long relativ);

Входные параметры:

macro | \- указатель на макроэлемент (0 - редактируемый макроэлемент),  
---|---  
x, y | \- координаты точки привязки,  
angl | \- угол поворота от оси OX против часовой стрелки (в градусах),  
relativ | признак системы координат: 1 - x, y, angl показывают смещение относительно СК редактируемого макроэлемента, 0 - абсолютные значения x, y, angl в СК вида.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Смотрите также:

1\. Методы [ksDocument2D::ksGetMacroPlacement](ksdocument2d_ksgetmacroplacement.html), [ksDocument2D::ksSetMacroPlacementEx](ksdocument2d_kssetmacroplacementex.html)

2\. [Рекомендации по обеспечению корректного редактирования библиотекой макроэлементов, геометрия которых зеркально отражена относительно исходного ее построения...](mirrored_macro.html)

Подразделы:

(отсутствуют)
