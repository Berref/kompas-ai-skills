# NewGroup, EndGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void NewGroup_Example (void) {

reference gr ;

double x,y,m,ang;

Phantom FANTOM;

gr = NewGroup(1); /* задание группы объектов */

LineSeg (-15, 0, 15, 0, 3); /* объекты записываются */

LineSeg ( 0, -15, 0, 15, 3); /* во временный список */

Circle (0, 0, 10, 1);

EndGroup(); /* закончить формирование группы */

/* ввод точки с отображением фантома и копирование группы*/

FANTOM.phType=1;

FANTOM.type1.gr=gr;

FANTOM.type1.xBase=0; FANTOM.type1.yBase=0;

FANTOM.type1.scale=1; FANTOM.type1.ang=0;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.promt = " Точка привязки ";

if (Cursor(&info, &x, &y, &FANTOM))

CopyObj(gr, x, y, m, ang);

if (YesNo(Удалять?))

DeleteObj(gr);

}; /* NewGroup_Example */
