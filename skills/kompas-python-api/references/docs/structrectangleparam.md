# RectangleParam - Структура параметров прямоугольника

[Структуры параметров и константы](3d_define.html) > [Структуры параметров графических объектов ](bk1735830.html) |  Scroll [ [ [ ](structregularpolygonparam.html "К следующему разделу")](bk1735830.html "На уровень выше")](structrectparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksRecangletParam](ksrectangleparam.html).

double | x, y | координаты базовой точки прямоугольника - одной из его вершин,  
---|---|---  
double | ang | угол наклона стороны прямоугольника, выходящей из базовой точки,  
double | height | высота прямоугольника,  
double | wight | " ширина" прямоугольника - длина стороны, характеризующейся углом наклона ang,  
unsigned short | style | стиль линии,  
reference | pCorner | динамический массив CORNER_ARR структур параметров скругленных (или усеченных) углов CornerParam.  
  
[Системные стили линий...](lstyles.html)

[Структура параметров CornerParam...](structcornerparam.html)

Подразделы:

(отсутствуют)
