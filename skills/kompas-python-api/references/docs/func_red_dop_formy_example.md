# Пример использования функций для редактирования допуска формы

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// редактирование допуска формы

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите допуск формы";

int j = Cursor(&info, &x, &y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

//узнаем тип объекта

int type =GetObjParam( pObj,0,0,0); //указатель на графический

объект

if (type == TOLERANCE_OBJ) {

unsigned int numb;

char buf[128];

//открыть допуск формы для редактирования

ksOpenTolerance(pObj);

ToleranceParam par;

//параметры допуска формы

GetObjParam( pObj, //указатель на графический объект

&par, //указатель на структуру параметров

sizeof(ToleranceParam), //размер структуры

параметров

ALLPARAM); //тип считывания параметров

sprintf(buf, "базовая точка=%d стиль=%d расположение-%s\nx=%5.1f

y=%5.1f ",

par.tBase, par.style, par.type ?

"вертикальное":"горизонтальное", par.x, par.y);

Message(buf);

TextLineParam par1;

//в цикле будем брать все существующие ячейки

while (ksGetToleranceColumnText(&numb, &par1)!=0) {

sprintf(buf, "numb =%d ", numb);

Message(buf);

sprintf(buf, "style=%d ", par1.style);

Message(buf);

TextItemParam par3;

for (int j=0; j< GetArrayCount(par1.pTextItem); j) {

GetArrayItem(par1.pTextItem, j, &par3, sizeof(TextItemParam));

if (!par3.tip)

sprintf(buf, "компонента=%d h=%5.1f\ns=%s\n

fontName=%s\nбитвектор =%d ",j,par3.font.height,par3.s,

par3.font.fontName, par3.font.bitVector);

else

sprintf(buf, "компонента=%d тип = %d номер спецзнака=%d

",j,par3.tip,par3.iSNumb);

Message(buf);

}

DeleteArray(par1.pTextItem); //очистим массив компонент

}

//заменим параметры

par.x = 10;

par.y = 10;

SetObjParam( pObj, //указатель на графический объект

&par, //указатель на структуру параметров

sizeof(ToleranceParam ), //размер структуры

параметров

ALLPARAM); //тип считывания параметров

ColumnNumber(2);

TextLine (NEW_LINE ,0,0 ,"вторая ячейка");

ksDivideTableItem(3, 1, 2);

ColumnNumber(4);

TextLine (NEW_LINE ,0,0 ,"4");

// ksSetTableBorderStyle(1,2,1);

// ksClearTableColumnText(0);

EndObj();//закрыли объект "допуск формы"

}

else

Error("это не допуск формы");

}

else

Error("нет объекта");

}
