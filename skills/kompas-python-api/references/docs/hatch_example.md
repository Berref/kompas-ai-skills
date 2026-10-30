# Hatch - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Hatch_Example (void) {

reference p;

LineSeg (10, 10, 10, 20, 1);

LineSeg (10, 20, 40, 20, 1);

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

Hatch(1, 45, 3, 0, 0,0); /* определение штриховки */

LineSeg (10, 10, 10, 20, 1);

LineSeg (10, 20, 40, 20, 1);

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

p = EndObj(); /* закончить формирование штриховки */

}; /* Hatch_Example */
