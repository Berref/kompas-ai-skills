# ksDuplicateBoundaries - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset (&info, 0, sizeof (info));

info.prompt = "Укажите штриховку или заливку";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, 1e6))) {

int objType = GetObjParam(pObj, 0, 0, 0);

if (objType == HATCH_OBJ || objType == COLORFILL_OBJ) {

Phantom phantom; // ltdefine.h

memset(&phantom, 0, sizeof(phantom));

//в фантом положим копию границы

phantom.type1.gr = ksDuplicateBoundaries( pObj);

phantom.phType = 1; //сдвиг группы

phantom.type1.scale = 1; //сдвиг группы

info.prompt = "Укажите точку привязки границы";

j = Cursor(&info, &x ,&y, &phantom);

if (j) {

MoveObj(phantom.type1.gr, x, y); //смещаем группу в новый центр

StoreTmpGroup(phantom.type1.gr); //временную группу делаем постоянной

ClearGroup(phantom.type1.gr);

DeleteObj(phantom.type1.gr);

}

}

else

Error("Объект должен быть штриховкой или заливкой");

}

}
