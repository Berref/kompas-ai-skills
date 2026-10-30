# ksConvertTextToCurve - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pText;

RequestInfo info;

//обнулить структуру info;

memset (&info, 0, sizeof (info));

double x, y;

info.prompt = "Укажите текст";

int j = Cursor (&info, &x, &y, 0);

if (j) {

if (ExistObj (pText = FindObj (x, y, 1e6)) &&

GetObjParam (pText, 0, 0, 0) == TEXT_OBJ) {

reference gr = ksConvertTextToCurve (pText);

if (gr) {

Phantom phantom; // ltdefine.h

memset (&phantom, 0, sizeof (phantom));

phantom.type1.gr = gr; //временная группа

phantom.phType = 1; //сдвиг группы

phantom.type1.scale = 1; //сдвиг группы

j = Cursor (&info, &x ,&y, &phantom);

if (j == -1) { //поставить в модель

MoveObj (phantom.type1.gr, x, y); //смещаем группу в новый цетр

StoreTmpGroup (phantom.type1.gr);//временную группу делаем постоянной

ClearGroup (phantom.type1.gr);

DeleteObj (phantom.type1.gr);

}

}

}

else

Error ("Это не текст");

}
