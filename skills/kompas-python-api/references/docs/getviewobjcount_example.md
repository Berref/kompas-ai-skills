# GetViewObjCount - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void GetViewObjCount_Example (void)

{

long n;

char buf[80];

LineSeg(20, 10, 20, 30, 1);

LineSeg(20, 30, 40, 30, 1);

LineSeg(40, 30, 40, 10, 1);

LineSeg(40, 10, 20, 10, 1);

n = GetViewObjCount(0); // в текущем виде/фрагменте

sprintf (buf,"Количество объектов=%5d);

Message(buf);

};
