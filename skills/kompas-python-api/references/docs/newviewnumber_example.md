# NewViewNumber пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference v;

char buf[128];

int number = NewViewNumber();

ViewParam par;

memset (&par, 0, sizeof (ViewParam));

par.x = 10;

par.y = 20;

par.scale = 0.5;

par.ang = 45;

par.color = RGB(10,20,10);

par.state = stACTIVE;

strcpy (par.name, "user view");

//создали вид

v=CreateSheetView(&par, &number);

int numb = GetViewNumber( v);

sprintf (buf,"создали вид numb=%d, number=%d", numb, number);

Message(buf);
