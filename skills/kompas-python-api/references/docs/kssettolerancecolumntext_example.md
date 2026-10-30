# ksSetToleranceColumnText - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// редактирование допуска формы

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите допуск формы";

int j = Cursor(&info, &x ,&y, 0);

if (j)

{

if (ExistObj(pObj = FindObj (x,y, 1000000.)))

{

//узнаем тип объекта

int type =GetObjParam (pObj,0,0,0); //указатель на графический объект

if (type == TOLERANCE_OBJ)

{

unsigned int numb;

//открыть допуск формы для редактирования

ksOpenTolerance(pObj);

TextLineParam linePar;

//в цикле будем брать все существующие ячейки

while (ksGetToleranceColumnText(&numb, &linePar)!=0)

{

TextItemParam itemPar;

for (int j=0; j< GetArrayCount(linePar.pTextItem); j++)

{

GetArrayItem (linePar.pTextItem, j, &itemPar,

sizeof (TextItemParam));

if (strlen (itemPar.s))

{

strcat (itemPar.s, "!!!");

SetArrayItem (linePar.pTextItem,

j, &itemPar,

sizeof(TextItemParam));

}

}

ksSetToleranceColumnText(numb, &linePar);

}

EndObj(); //закрыли объект "допуск формы"

}

else

Error ("Указанный объект - не допуск формы");

}

else

Error("нет объекта");

}
