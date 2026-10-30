# Base - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Base_Example (void)

{

reference p;

BaseParam basePar;

memset (&basePar, 0, sizeof (BaseParam));

basePar.x1 = 50; basePar.y1 =50; // базовая точка

basePar.x2 = 50; basePar.y2 =30; // конечная точка ножки

strcpy (basePar.str, A); // надпись

p = Base (&basePar);

};
