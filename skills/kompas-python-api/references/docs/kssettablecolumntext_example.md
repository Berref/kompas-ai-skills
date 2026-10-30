# ksSetTableColumnText - Пример использования

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

if (ExistObj (pObj = FindObj (x, y, 100000)))

{

//узнаем тип объекта

int type =GetObjParam (pObj,0,0,0); //указатель на графический объект

//проверить, таблица ли полученный объект

if (type == TABLE_OBJ)

{

unsigned int numb;

reference p;

//открыть таблицу для редактирования

ksOpenTable (pObj);

TextParam par;

//в цикле будем брать все существующие ячейки

while ((ksGetTableColumnText (&numb, &par))!=0)

{

p=par.pTextLine;

TextLineParam linePar;

for (int i=0; i < GetArrayCount(p); i)

{

GetArrayItem(p , i, &linePar, sizeof(TextLineParam));

TextItemParam itemPar;

for (int j=0; j< GetArrayCount(linePar.pTextItem); j)

{

GetArrayItem (linePar.pTextItem, j, &itemPar,

sizeof (TextItemParam));

if (strlen(itemPar.s))

{

strcat(itemPar.s, "!!!");

SetArrayItem (linePar.pTextItem, j, &itemPar,

sizeof(TextItemParam));

}

}

SetArrayItem(p , i, &linePar, sizeof(TextLineParam));

}

//очистим массив текстовых строк

ksSetTableColumnText(numb, &par);

}

EndObj();//закрыли объект "таблица"

}

else

Error("Указанный объект - не таблица");

}

else

Error("нет объекта");

}
