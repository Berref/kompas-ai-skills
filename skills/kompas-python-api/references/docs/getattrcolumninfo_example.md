# GetAttrColumnInfo - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ReadObjAttr() {

struct {

double d;

char s[MAX_TEXT_LENGTH];

long l;

} sBuf;

double x, y;

reference pObj;

int j;

char buf[127];

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите объект";

do {

j = Cursor(&info, &x, &y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

LightObj(pObj, 1);

//создадим итератор для хождения по атрибутам объекта

reference iter = CreateAttrIterator(pObj, 0,0,0,0,0);

//встали на первый атрибут

reference attr = MoveAttrIterator(iter, 'F', 0);

if (attr) {

Message("тип и ключи атрибута");

unsigned int k1,k2,k3,k4;

double numb;

GetAttrKeysInfo(attr,&k1,&k2,&k3,&k4,&numb);

sprintf (buf, "k1=%d k2=%d k3=%d k4=%d numb=%f ",k1,k2,k3,k4,numb);

Message(buf);

Message("количество колонок");

unsigned int col;

GetAttrTabInfo(attr, 0, &col);

sprintf (buf, "column=%d",col);

Message(buf);

Message("информация о колонках");

ColumnInfo par; //структура для первой колонки

par.columns = CreateArray(ATTR_COLUMN_ARR);

par.fieldEnum = CreateArray(CHAR_STR_ARR);

for (int i=0; i < col; i) {

GetAttrColumnInfo (attr, i, &par);

ShowCol(par,i, FALSE);

}

DeleteArray(par.columns);

DeleteArray(par.fieldEnum);

Message("строка атрибута");

GetAttrRow (attr, 0, 0, &sBuf, sizeof(sBuf));

sprintf (buf, "d=%f s=%s l=%ld",sBuf.d, sBuf.s, sBuf.l);

Message(buf);

Message("заменим строку атрибута");

sBuf.d = numb;

strcpy(sBuf.s,"1234567\nasdfgh\nzxcvb");

sBuf.l = 88888l;

SetAttrRow(attr, 0, 0, &sBuf, sizeof(sBuf), "111");

memset(&sBuf,0, sizeof(sBuf));

GetAttrRow (attr, 0, 0, &sBuf, sizeof(sBuf));

sprintf (buf, "d=%f s=%s l=%ld",sBuf.d, sBuf.s, sBuf.l);

Message(buf);

}

else

Message("атрибут не найден");

LightObj(pObj, 0);

}

}

} while (j);

}
