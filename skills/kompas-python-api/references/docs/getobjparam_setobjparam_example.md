# GetObjParam, SetObjParam - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void GetObjParam_Example(void) {

char buf [128];

reference p;

LineSegParam par;

int t;

Mtr(30, 20, 45, 1);

p = LineSeg(0, 0, 30, 0, 1);

/* взять параметры отрезка */

t = GetObjParam(p, &par, sizeof(par), ALLPARAM);

sprintf(buf, " t=%d, x1=%4.1f y1=%4.1f x2=%4.1f y2=%4.1f tl=%d",t,

par.x1, par.y1, par.x2, par.y2, par.style);

Message(buf);

/* заменить параметры отрезка */

par.x2 = 0; par.y2 = 40; par.style = 2;

if(SetObjParam(p, &par, sizeof(par), ALLPARAM))

Message(" Изменили объект");

else MessageBoxResult();

DeleteMtr();

} /* _Example */

/***************************************************************************/

/*Второй пример использования GetObjParam и SetObjParam*/

// редактирование позиционной линии выноски

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите позиционную линию выноски";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

if (GetObjParam(pObj, 0,0,0) == POSLEADER_OBJ) {

PosLeaderParam leaderPar;

GetObjParam(pObj, //указатель на графический объект

&leaderPar, //указатель на структуру параметров

sizeof(LeaderParam), //размер структуры параметров

ALLPARAM); //тип считывания параметров

leaderPar.x = 10;

leaderPar.y = 10;

int rez = SetObjParam(pObj, //указатель на графический объект

&leaderPar, //указатель на структуру параметров

sizeof(LeaderParam), //размер структуры параметров

ALLPARAM); //тип считывания параметров

if (rez) {

LightObj(pObj,1);

Message ("линия выноски по параметрам");

LightObj(pObj,0);

}

else

MessageBoxResult(); //сообщение об ошибке

}

else

Error("Объект не позиционная линия выноски");

}

}
