# ksContour - Создать контур

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksduplicateboundaries.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksaddobjecttomacro.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [Contour](contour.html).

Синтаксис Automation:

long ksContour (long style);

Входной параметр:

style | \- стиль линии.  
---|---  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Контур - составной объект. Объекты, вводимые между методами [ksDocument2D::ksContour](ksdocument2d_kscontour.html) и [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html), принадлежат контуру.

2\. В контуре могут лежать отрезки, дуги, окружности (они превращаются в дуги), сплайны.

3\. Конечная точка предыдущего звена должна совпадать с начальной точкой последующего звена.

4\. ksDocument2D::ksEndObj возвращает указатель на контур.

Подразделы:

(отсутствуют)
