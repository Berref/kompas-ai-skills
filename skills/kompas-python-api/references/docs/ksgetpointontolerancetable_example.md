# ksGetPointOnToleranceTable - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите допуск формы";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, 1e6))){

//узнаем тип объекта

int type =GetObjParam( pObj,0,0,0); //указатель на графический объект

if (type == TOLERANCE_OBJ) {

for(unsigned char i = 1; i < 9 ; i) {

MathPointParam parPoint;

if (ksGetPointOnToleranceTable(pObj, // указатель на допуск формы

i, // тип точки на таблице допуска формы

&parPoint)) // координаты точки

Point(parPoint.x, parPoint.y, //координаты точки

(unsigned short)(i-1)); //стиль отрисовки точки

}

}

else

Error("это не допуск формы");

}

else

Error("нет объекта");

}
