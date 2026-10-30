# Bezier, _Bezier - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Bezier_Example (void)

{

double x[5]={15, 35, 55, 75, 95 };

double y[5]={15, 75, 25, 95, 15 };

Bezier (1, 0); // определение кривой

Point (10, 10, 1);

Point (30, 70, 1);

Point (50, 20, 1);

Point (70, 90, 1);

Point (90, 10, 1);

EndObj (); // закончить формирование кривой

// задание производных в узлах

BezierPointParam par;

double x[] = { 0, 20, 50, 70, 100, 50 };

double y[] = { 0, 20, 10, 20, 0, -50 };

double ang[] = { 0, 30, 40, 45, -45, -30 };

double left[] = { 1, 1, 2, 3, 1, 1 };

double right[]= { 2, 2, 1, 1, 3, 4 };

reference p = Bezier (0, 1);

for (int i=0; i<5; i)

{

par.x = x[i]; par.y = y[i];

par.ang = ang[i];

par.left = left[i]; par.right = right[i];

BezierPoint(&par);

}

EndObj(); // закончить формирование кривой

_Bezier (&par, 6, 0, 1);

};
