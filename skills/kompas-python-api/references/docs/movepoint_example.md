# MovePoint - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void MovePointExample (void) {

double x1, y1, x2, y2 ;

x1 = 10;

y1 = 60;

x2 = 60;

y2 = 90;

LineSeg ( x1, y1, x2, y2, 1);

MovePoint (&x1, &y1, 90, 100);

MovePoint (&x2, &y2, 90, 100);

LineSeg ( x1, y1, x2, y2, 1);

}; /* MovePointExample */
