# ksRegularPolygon - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
RegularPolygonParam par;

par.count = 8; // количество вершин многоугольника

par.xc = 100; // центр окружности

par.yc = 100;

par.ang = 35; // угол первой вершины

par.radius = 40; // радиус окружности

par.describe = 1; // признак описанного многоугольника.

par.style = 1; // стиль линии

par.pCorner = ::CreateArray (CORNER_ARR, 0); // динамический массив

// структур параметров углов CORNER_ARR

CornerParam cpar; // структура параметров угла

cpar.index = 5; // индекс угла

cpar.fillet = 0; // признак фаски

cpar.l1 = 40; // длина фаски 1 сегмента

cpar.l2 = 45; // длина фаски 2 сегмента

::AddArrayItem(par.pCorner, -1, &cpar, sizeof(CornerParam)); // добавить угол в массив

cpar.index = 2; // индекс угла

cpar.fillet = 1; // признак скругления

cpar.l1 = 20; // радиус

cpar.l2 = 20; // радиус

::AddArrayItem(par.pCorner, -1, &cpar, sizeof(CornerParam)); // добавить угол в массив

::ksRegularPolygon(&par, 3); // создаётся многоугольник с осями
