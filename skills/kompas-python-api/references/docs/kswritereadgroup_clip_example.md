# ksWriteGroupToClip, ksReadGroupFromClip - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//делаем активным документ 1.cdw

OpenDocument("c:\\\1.cdw", 0);

double x, y, x1,y1;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите начальную точку окна";

if (Cursor(&info, &x, &y, 0)) {

info.prompt = "Укажите конечную точку окна";

Phantom phantom; // ltdefine.h

memset(&phantom, 0, sizeof(phantom));

//Задаем тип резиноыой нити - прямоугольник и передаем в Cursor, чтобы ввести область выделения

phantom.phType = 3; //прямоугольник

phantom.type3.xBase = x;

phantom.type3.yBase = y;

if (Cursor(&info, &x1, &y1, &phantom)) {

//создадим пустую рабочую группу

reference gr = NewGroup(0);

EndGroup();

//помещаем в группу геометрию, которая попала в область выделения

if (SelectGroup(gr, 1, x, y, x1, y1)) {

// группу выделения записываем в буфер обмена

int rez = ksWriteGroupToClip(gr, // указатель на группу

1); // 1 - с копированием; 0 - с удалением из текущего документа

if (rez) {

//делаем активным другой документ, например 1.frw, куда нужно перенести геометрию из буфера обмена

OpenDocument("d:\\\0\\\1.frw", 0);

//обнулить структуру info;

memset(&info, 0, sizeof(info));

memset(&phantom, 0, sizeof(phantom));

int j = 1;

//группу считываем из буфера обмена

phantom.type1.gr = ksReadGroupFromClip();

phantom.phType = 1; //сдвиг группы

phantom.type1.scale = 1; //сдвиг группы

while (j) {

j = Cursor(&info, &x ,&y, &phantom);

if ( j == -1) {

MoveObj(phantom.type1.gr, x, y); //смещаем группу в новый цетр

StoreTmpGroup(phantom.type1.gr); //временную группу делаем постоянной

ClearGroup(phantom.type1.gr);

DeleteObj(phantom.type1.gr);

//группу считываем из буфера обмена

phantom.type1.gr = ksReadGroupFromClip(); //временная группа

}

}

}

}

}

}
