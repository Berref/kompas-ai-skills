# Rotate - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Rotate_Example (void) {

double x[2], y[2];

LineSeg ( 10, 60, 60, 90, 1);

Rotate (10, 60, 0, 0, 90, x[0], y[0]);

Rotate (60, 90, 0, 0, 90, x[1], y[1]);

LineSeg (x[0], y[0], x[1], y[1], 1);

}; /* Rotate_Example */
