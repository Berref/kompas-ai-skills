# Типы параметрических ограничений

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Константы системы ](bk1808863.html) |  Scroll [ [ [ ](datatypes.html "К следующему разделу")](bk1808863.html "На уровень выше")](lentypes.html "К предыдущему разделу")  
---|---  
  
Параметр constrType может иметь следующие значения для выбора типа параметрического ограничения:

CONSTRAINT_FIXED_POINT | 1 | \- фиксация точки  
---|---|---  
CONSTRAINT_POINT_ON_CURVE | 2 | \- точка на кривой  
CONSTRAINT_HORIZONTAL | 3 | \- горизонталь  
CONSTRAINT_VERTICAL | 4 | \- вертикаль  
CONSTRAINT_PARALLEL | 5 | \- параллельность двух прямых или отрезков  
CONSTRAINT_PERPENDICULAR | 6 | \- перпендикулярность двух прямых или отрезков  
CONSTRAINT_EQUAL_LENGTH | 7 | \- равенство длин двух отрезков  
CONSTRAINT_EQUAL_RADIUS | 8 | \- равенство радиусов двух дуг или окружностей  
CONSTRAINT_HOR_ALIGN_POINTS | 9 | \- выравнивание двух точек по горизонтали  
CONSTRAINT_VER_ALIGN_POINTS | 10 | \- выравнивание двух точек по вертикали  
CONSTRAINT_MERGE_POINTS | 11 | \- совпадение двух точек  
CONSTRAINT_TANGENT_TWO_CURVES | 15 | \- коллинеарность отрезков  
CONSTRAINT_SYMMETRY_TWO_POINTS | 16 | \- симметрия двух точек относительно отрезка  
CONSTRAINT_COLLINEAR | 17 | \- коллинеарность двух отрезков  
CONSTRAINT_FIXED_ANGLE | 18 | \- фиксированный угол  
CONSTRAINT_FIXED_LENGHT | 19 | \- фиксированная длина  
CONSTRAINT_POINT_ON_CURVE_MIDDLE | 20 | \- точка на середине кривой  
CONSTRAINT_BISECTOR | 21 | \- биссектриса  
CONSTRAINT_CONCENTRICITY | 22 | \- совпадение центров окружностей, дуг, эллипсов и точек  
  
Примечание.

При использовании API 7 аналогом данного набора является перечисление [ksConstraintTypeEnum](ksconstrainttypeenum.html)

Подразделы:

(отсутствуют)
