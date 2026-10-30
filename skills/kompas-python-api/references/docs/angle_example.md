# Angle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Angle_Example (void)

{

double Ang;

//Вычисление угла отрезка 0,0; 60,40

LineSeg ( 0, 0, 60, 40, 1);

Ang = Angle (0, 0, 60, 40);

gprintf(Угол = %6.2f, Ang);

};
