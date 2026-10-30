# ksCopyObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
ViewParam par;

int number = 5;

par.x = 20;

par.y = 60;

par.scale = 1;

par.ang = 0;

par.color = RGB(10,20,10);

par.state = stACTIVE;

strcpy(par.name, "user view");

//создали вид

reference v = CreateSheetView(&par, &number);

//создали слой

Layer(5);

LineSeg(20, 10, 20, 30, 1);

LineSeg(20, 30, 40, 30, 1);

LineSeg(40, 30, 40, 10, 1);

LineSeg(40, 10, 20, 10, 1);

//копируем вид (для вида точки задаются в листовых координатах)

reference p = ksCopyObj(l1, 20, 60, 40, 80, 1, 0 );

LightObj (p, 1);

Message("Подсветили скопированный вид");

LightObj (p, 0);

//сдвинули скопированный вид

MoveObj(p, 50, 0);
