# TanLineAngCircle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void TanLineAngCircle_Example (void) {

double x[2], y[2];

int k, i;

Circle ( 60, 60, 30, 1);

TanLineAngCircle (60, 60, 30, 45, &k, x, y);

gprintf(Количество касаний = %2d, k);

}; /* TanLineAngCircle_Example */
