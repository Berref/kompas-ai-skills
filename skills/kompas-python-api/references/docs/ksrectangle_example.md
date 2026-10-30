# ksRectangle - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
RectangleParam par; // структура параметров прямоугольника

::memset(&par, 0, sizeof(RectangleParam));

par.x = -73.55; // базовая точка 1

par.y = 39.95; //

par.ang = 0.00; // угол вектора направления от 1-ой точки ко 2-ой

par.height = -66.68; // высота

par.weight = 79.90; // ширина

par.pCorner = ::CreateArray(CORNER_ARR, 0); // Создание массива параметров углов

par.style = 1; // стиль линии

::ksRectangle(&par, 0); // создать прямоугольник
