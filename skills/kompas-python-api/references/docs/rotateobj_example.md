# RotateObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void RotateObj_Example (void)

{

reference gr ;

double x,y,ang;

gr = NewGroup (0); //задание группы объектов

LineSeg (-15, 0, 15, 0, 3); // объекты записываются

LineSeg (0, -15, 0, 15, 3); // в модель текущего вида

Circle (0, 0, 10, 1);

EndGroup(); /* закончить формирование группы */

RequestInfo info;

memset (&info, 0, sizeof(info));

info.promt = " Центр поворота ";

// задание параметров поворота

if ((Cursor(&info,&x,&y, 0)) && (ReadFloat (Угол поворота, 0, 0, 360, ang)))

RotateObj (gr, x, y, ang); // поворот группы gr

};
