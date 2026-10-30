# Leader - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Leader_Example (void) {

reference p;

TextLineParam tLinePar;

memset(&tLinePar, 0, sizeof(TextLineParam));

tLinePar.style=0; //номер стиля строки текста

// массив неопределенной длины компонент строки текста

tLinePar.pTextItem = CreateArray(TEXT_ITEM_ARR,0);

TextItemFont tFont; // параметры шрифта компоненты строки текста

tFont.fontName[0]=\0; // имя шрифта

tFont.height=0; // высота текста

tFont.ksu=0; // сужение текста

tFont.color = RGB(0,0,0); // цвет

tFont.bitVector=0; // флаг параметров

TextItemParam ItemPar; // параметры компоненты строки текста

ItemPar.tip = 0;

ItemPar.font = tFont; // параметры шрифта для компоненты текста

ItemPar.iSNumb = 0; // номер символа

LeaderParam leaderPar;

memset(&leaderPar, 0, sizeof(LeaderParam));

leaderPar.x=50; leaderPar.y=50; // начало полки

leaderPar.arrowType = 1; // тип стрелки

leaderPar.dirX=1; // полка вправо

leaderPar.signType=0; // тип знака

leaderPar.around=0; // знак обработки по контуру выключен

leaderPar.cText0=1; // число строк над полкой

leaderPar.cText1=1; // число строк под полкой

leaderPar.cText2=1; // число строк над ножкой

leaderPar.cText3=1; // число строк под ножкой

leaderPar.pTextline = CreateArray(TEXT_LINE_ARR,0);

strcpy(ItemPar.s,строка над полкой);

// массив символов для компоненты текста

AddArrayItem(tLinePar.pTextItem, -1, &ItemPar, sizeof(ItemPar));

AddArrayItem(leaderPar.pTextline, -1, &tLinePar, sizeof(tLinePar));

ClearArray(tLinePar.pTextItem);

strcpy(ItemPar.s,строка под полкой);

// массив символов для компоненты текста

AddArrayItem(tLinePar.pTextItem, -1, &ItemPar, sizeof(ItemPar));

AddArrayItem(leaderPar.pTextline, -1, &tLinePar, sizeof(tLinePar));

ClearArray(tLinePar.pTextItem);

strcpy(ItemPar.s,2); // массив символов для компоненты текста

AddArrayItem(tLinePar.pTextItem, -1, &ItemPar, sizeof(ItemPar));

AddArrayItem(leaderPar.pTextline, -1, &tLinePar, sizeof(tLinePar));

ClearArray(tLinePar.pTextItem);

strcpy(ItemPar.s,3);

// массив символов для компоненты текста

AddArrayItem(tLinePar.pTextItem, -1, &ItemPar, sizeof(ItemPar));

AddArrayItem(leaderPar.pTextline, -1, &tLinePar, sizeof(tLinePar));

leaderPar.pPolyline =CreateArray(POLYLINE_ARR,0);

reference pPoly = CreateArray(POINT_ARR , 0);

//две ножки по одной точке в каждой

MathPointParam mPar;

mPar.x = 10; mPar.y = 10;

AddArrayItem(pPoly , -1, &mPar, sizeof(mPar));

AddArrayItem(leaderPar.pPolyline , -1, &pPoly, sizeof(pPoly));

mPar.x = 30; mPar.y = 10;

ClearArray(pPoly);

AddArrayItem(pPoly , -1, &mPar, sizeof(mPar));

AddArrayItem(leaderPar.pPolyline , -1, &pPoly, sizeof(pPoly));

p = Leader(&leaderPar);

}; /* Leader_Example */
