# ksIsCursorOrPlacementDocument - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

#ifndef __LIBTOOL_H

#include <libtool.h>

#endif

int type, flag=0;

//функция обратной связи для выполнения цикла в Cursor

int far __export pascal CallBackC (int com, double *x, double *y, RequestInfo *info,

void *phantom, int/* dynamic */) {

Phantom *valueub = (Phantom *)phantom;

rub->type1.ang = 90;

ksChangeObjectInLibRequest (&info, &rub);

switch (com) {

case 1:

case 2:

type = com;

break;

case -1: //поставить в модель

if (ksIsCursorOrPlacementDocument () == 1)

{

MoveObj(rub->type1.gr, *x, *y);

StoreTmpGroup(rub->type1.gr); //поставить временную группу в вид

ClearGroup(rub->type1.gr);

}

break;

}

//группа для фантома должна быть временная и обновляться при изменении вида

//отрисовки

if (rub->type1.gr)

DeleteObj(rub->type1.gr);

rub->type1.gr = NewGroup(1); // временная группа

if((flag==1 && com==1)||(flag==2 && com==2))

type = 3;

//обновляется не только изображение но и меню для запроса

switch (type ) {

case 1:

Circle (0, 0, 20, 1);

info->commands = !Квадрат !Треугольник ;

flag = 1;

break;

case 2:

LineSeg(-10, 0, 10, 0, 1);

LineSeg(10, 0, 0, 20, 1);

LineSeg(0, 20, -10, 0, 1);

info->commands = !Окружность !Квадрат;

flag = 2;

break;

case 3:

LineSeg(-10, 0, 10, 0, 1);

LineSeg(10, 0, 10, 20, 1);

LineSeg(10, 20, -10, 20, 1);

LineSeg(-10, 20, -10, 0, 1);

info->commands = !Окружность !Треугольник;

flag = 0;

break;

}

EndGroup();

return 1;

}

void Cursor_Example (void) {

type = 1;

int j = 1;

struct Phantom rub;

rub.type1.xBase = 0;

rub.type1.yBase = 0;

rub.type1.scale = 1;

rub.phType = 1;

rub.type1.ang = 0;

double x, y;

rub.type1.gr = NewGroup(1); // временная группа

Circle (0, 0, 20, 1);

EndGroup();

RequestInfo info;

memset(&info, 0, sizeof(info));

info.commands = "!Квадрат !Треугольник";

info.callBack = CallBackС;//указываем адрес функции обратной связи для Cursor,

Cursor(&info , &x, &y, &rub);

}; /* Cursor*/

}
