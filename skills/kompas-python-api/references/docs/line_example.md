# Line - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Line_Example (void)

{

reference l1, l2, l3, l4 ;

double B=100, H=40;

// задание четырех прямых прямоугольника длиной B и высотой H

l1 = Line (0, 0, 90);

l2 = Line (0, H, 0);

l3 = Line (B, H, 90);

l4 = Line (B, 0, 0);

};
