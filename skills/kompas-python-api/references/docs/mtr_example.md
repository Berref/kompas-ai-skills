# Mtr, DeleteMtr - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Mtr_Example (void) {

int t = 1; /*сплошная основная */

reference l1, l2, l3, l4 ;

double B=100, H=40;

/* задание 4-х отрезков прямоугольника */

/* длиной B и высотой H */

/* в системе координат с началом 50,50, */

/* и поворотом 45 градусов */

Mtr (50, 50, 45, 1);

l1 = LineSeg (0, 0, 0, H, t);

l2 = LineSeg (0, H, B, H, t);

l3 = LineSeg (B, H, B, 0, t);

l4 = LineSeg (B, 0, 0, 0, t);

DeleteMtr ();

}; /* Mtr_Example */
