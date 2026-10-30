# CopyObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void CopyObj_Example (void)

{

reference gr ;

double x,y,ang; scale;

/* задание группы объектов */

gr = NewGroup(0);

/* объекты записываются в модель текущего вида */

LineSeg (-15, 0, 15, 0, 3);

LineSeg ( 0, -15, 0, 15, 3); /* */

Circle (0, 0, 10, 1);

/* закончить формирование группы */

EndGroup();

RequestInfo info;

memset(&info, 0, sizeof(info));

info.promt = " Новое положение базовой точки ";

/* задание параметров копирования */

if ((Cursor (&info, &x, &y, 0)) &&

(ReadFloat (Угол поворота, 0, 0, 360, ang)) &&

(ReadFloat(Масштаб, 1, 0, 999, scale)))

CopyObj(gr, 0, 0, x, y, ang, scale); /* копирование группы gr */

/* базовая точка совпадает с 0,0 */

};
