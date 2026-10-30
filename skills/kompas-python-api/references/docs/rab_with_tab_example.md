# Пример использования функций для редактирования таблицы

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// редактирование таблицы

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите таблицу";

// взять таблицу на чертеже

int j = Cursor(&info, &x ,&y, 0);

if (j)

{

if (ExistObj (pObj = FindObj (x, y, MAXDOUBLE)))

{

//узнаем тип объекта

int type =GetObjParam( pObj,0,0,0); //указатель на графический объект

//проверить, таблица ли полученный объект

if (type == TABLE_OBJ)

{

unsigned int numb;

reference p;

char buf[128];

//открыть таблицу для редактирования

ksOpenTable(pObj);

TextParam par;

//в цикле будем брать все существующие ячейки

while ((ksGetTableColumnText(&numb, &par))!=0)

{

sprintf(buf, "numb =%d ", numb);

Message(buf);

p=par.pTextLine;

TextLineParam par2;

for (int i=0; i < GetArrayCount(p); i)

{

GetArrayItem (p, i, &par2, sizeof(TextLineParam));

sprintf(buf, "i =%d style=%d ", i, par2.style);

Message(buf);

TextItemParam par3;

for (int j=0; j< GetArrayCount(par2.pTextItem); j)

{

GetArrayItem (par2.pTextItem, j, &par3,

sizeof(TextItemParam));

if (!par3.tip)

sprintf(buf, "компонента=%d

h=%5.1f\ns=%s\n fontName=%s\nбитвектор =%d ",j, par3.font.height, par3.s,

par3.font.fontName, par3.font.bitVector);

else

sprintf (buf, "компонента=%d тип = %d

номер спецзнака=%d ",j,par3.tip,par3.iSNumb);

Message(buf);

}

//очистим массив компонент

DeleteArray(par2.pTextItem);

}

//очистим массив текстовых строк

DeleteArray(p);

}

//берем ячейку 2

ColumnNumber(2);

Text(0, 0, 0, 5, 1 ,0,"вторая ячейка");

ksDivideTableItem(3, 1, 2);

ColumnNumber(4);

Text(0, 0, 0, 5, 1 ,0,"4");

EndObj();//закрыли объект "таблица"

}

else

Error("это не таблица");

}

else

Error("нет объекта");

}

Пример редактирования допуска формы

// редактирование допуска формы

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите допуск формы";

//взять допуск формы на чертеже

int j = Cursor(&info, &x ,&y, 0);

if (j)

{

if (ExistObj(pObj = FindObj(x, y, MAXDOUBLE)))

{

//узнаем тип объекта

int type =GetObjParam( pObj,0,0,0); //указатель на графический объект

//проверим,является ли пришедший объект допуском фомы

if (type == TOLERANCE_OBJ)

{

unsigned int numb;

reference p;

char buf[128];

//открыть допуск формы для редактирования

ksOpenTolerance(pObj);

ToleranceParam par;

//возьмем параметры допуска формы

GetObjParam (pObj, //указатель на графический объект

&par, //указатель на структуру параметров

sizeof (ToleranceParam), //размер

//структуры параметров

ALLPARAM); //тип считывания параметров

sprintf (buf, "базовая точка=%d стиль=%d

расположение-%s\nx=%5.1f y=%5.1f",

par.tBase, par.style, par.type ?

"вертикальное":"горизонтальное", par.x, par.y);

Message(buf);

//в цикле будем брать все существующие ячейки

while ((p=ksGetToleranceColumnText(&numb))!=0)

{

sprintf(buf, "numb =%d ", numb);

Message(buf);

TextLineParam par2;

for (int i=0; i < GetArrayCount(p); i)

{

GetArrayItem(p , i, &par2, sizeof(TextLineParam));

sprintf(buf, "i =%d style=%d ", i, par2.style);

Message(buf);

TextItemParam par3;

for (int j=0; j< GetArrayCount(par2.pTextItem); j)

{

GetArrayItem (par2.pTextItem, j, &par3,

sizeof(TextItemParam));

if (!par3.tip)

sprintf (buf, "компонента=%d h=%5.1f\ns=%s\n

fontName=%s\nбитвектор =%d

",j,par3.font.height,par3.s

par3.font.fontName, par3.font.bitVector);

else

sprintf (buf, "компонента=%d тип = %d номер

спецзнака=%d ",j,par3.tip,par3.iSNumb);

Message(buf);

}

DeleteArray(par2.pTextItem); //очистим массив компонент

}

//очистим массив текстовых строк

DeleteArray(p);

}

//заменим параметры допуска формы

par.x = 10;

par.y = 10;

int rez = SetObjParam (pObj, //указатель на графический объект

&par, //указатель на структуру параметров

sizeof(ToleranceParam), //размер структуры параметров

ALLPARAM); //тип считывания параметров

// заменим текст в ячейке 2

ColumnNumber(2);

TextLine (NEW_LINE ,0,0 ,"вторая ячейка");

//разделим ячейку 3 вертикальным ребром с типом " тонкая"

ksDivideTableItem(3, 1, 2);

//перестроим виртуальную сетку

ksRebuildTableVirtualGrid();

// введем текст в ячейку 4

ColumnNumber(4);

TextLine (NEW_LINE ,0,0 ,"4");

EndObj();//закрыли объект "допуск формы"

}

else

Error("это не допуск формы");

}

else

Error("нет объекта");

}
