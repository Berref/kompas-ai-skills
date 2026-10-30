# Cursor- Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
#ifndef __LIBTOOL_H

#include <libtool.h>

#endif

int type, flag=0;

//функция обратной связи для выполнения цикла в Cursor

int far __export pascal CallBackC (int com, double *x, double *y, RequestInfo *info,

void *phantom, int/* dynamic */) {

Phantom *valueub = (Phantom *)phantom;

switch (com) {

case 1:

case 2:

type = com;

break;

case -1: //поставить в модель

MoveObj(rub->type1.gr, *x, *y);

StoryTmpGroup(rub->type1.gr); //поставить временную группу в вид

ClearGroup(rub->type1.gr);

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

Cursor(&info, &x, &y, &rub);

}; /* Cursor*/

struct RequestInfo info;

memset(&info,0,sizeof(RequestInfo)); //Структура информации

info.prompt="Укажите начальную точку";

Cursor(&info,&xBase,&yBase,0);//Начальная точка

struct Phantom f;

memset(&f,0,sizeof(Phantom)); //Фантом

f.type2.xBase = xBase;

f.type2.yBase = yBase;

info.prompt="Укажите точку на окружности";

f.phType=7; // тип "резиновой" нити - окружность

double x,y;

//если был запущен другой процесс то не запускается второй Cursor

if (!ksIsActiveProcessRunnig () && Cursor(&info,&x,&y,&f))

Circle(xBase, yBase, DistancePntPnt (xBase, yBase, x,y),1);

else

Message("Запущен другой процесс");

//Функция обратной связи Cursor для построения пользовательского фантома (в данном случае "резиновый" отрезок)

int far __export pascal CallBackEskLinsvzLin(int com ,double *x,double *y,RequestInfo*,void *phantom,int dynamic) {

Phantom *valueub = (Phantom *)phantom;

if (!dynamic) { //Фиксация точки

if (com == -1) {

StoreTmpGroup(rub->type6.gr);

ClearGroup(rub->type6.gr);

}

DeleteObj(rub->type6.gr);

return 0;

}

else {

if (fabs(xBase -*x) > 0.001 || fabs(yBase -*y) > 0.001) {

DeleteObj(rub->type6.gr);

rub->type6.gr = NewGroup(1);

LineSeg(xBase, yBase, *x, *y, 1);

EndGroup();

}

return 1;

}

}

struct RequestInfo info;

memset(&info,0,sizeof(RequestInfo)); //Структура информации

info.prompt="Укажите начальную точку";

Cursor(&info,&xBase,&yBase,0); //Начальная точка

info.dynamic=1;

info.callBack=CallBackEskLinsvzLin;

struct Phantom f;

memset(&f,0,sizeof(Phantom)); //Фантом

f.type2.xBase = xBase;

f.type2.yBase = yBase;

f.phType=6; //пользовательский фантом

info.prompt="Укажите точку на линии";

f.type6.gr = NewGroup(1);

LineSeg(xBase, yBase, xBase+0.1, yBase,1);

EndGroup();

double x,y;

Cursor(&info,&x,&y,&f);
