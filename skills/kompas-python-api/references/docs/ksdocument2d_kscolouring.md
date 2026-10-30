# ksColouring - Создать фоновую заливку цветом

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksconicarc.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_kscircle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksColouring](kscolouring.html).

Синтаксис Automation:

long ksColouring (long color);

Входной параметр:

color | \- цвет заливки.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Заливка - составной объект. Объекты вида, вводимые между методами [ksDocument2D::ksColouring](ksdocument2d_kscolouring.html) и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат заливке и образуют ее границу.

ksDocument2D::ksEndObj возвращает указатель на заливку.

Подразделы:

(отсутствуют)
