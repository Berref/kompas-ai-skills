# Contour - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Contour_Example (void) {

reference p;

Contour(1); /* определение контура */

LineSeg (10, 10, 10, 20, 1);

LineSeg (10, 20, 40, 20, 1);

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

p = EndObj(); /* закончить формирование контура */

}; /* Contour_Example */
