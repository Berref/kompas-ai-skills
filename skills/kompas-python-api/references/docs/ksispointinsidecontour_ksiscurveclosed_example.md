# ksIsPointInsideContour, ksIsCurveClosed - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите контур";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

//выбрать контур

if(ExistObj(pObj = FindObj(x, y, 1e6)) && GetObjParam(pObj, 0,0,0) == CONTOUR_OBJ ){

//проверим контур на замкнутость

int close = ksIsCurveClosed(pObj);

char buf[250];

sprintf(buf, " контур %s", close ? "замкнут" : "разомкнут");

Message(buf);

info.prompt = "Укажите точку";

do {

//задать точку

j = Cursor(&info, &x ,&y, 0);

if (j) {

//проверяем расположение точки

int side = ksIsPointInsideContour(pObj, x, y, 0.001);

sprintf(buf, " точка %s", side==1 ? "вне контура" : side==2 ? "на контуре" : "внутри контура");

Message(buf);

}

} while(j);

}

else

Error("Это не контур");

}
