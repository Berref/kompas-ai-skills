# AddStyle - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

unsigned short StyleID;

CurveStyleParam CrvStyle;

StyleID = AddStyle (CURVE_STYLE, &CrvStyle,

sizeof (CurveStyleParam), 0);

}

Пример создания стиля кривой, содержащего фрагменты (кривой "с картинками")

LibStyle par; //структура параметров стиля из библиотеки

strcpy(par.fileName, "d:\\\0\\\1.lcs") ;

par.styleNumber = 1;

//получим некий стиль кривой, на базе которого сделаем свой стиль

unsigned short tl = AddStyle(CURVE_STYLE_EX, &par, sizeof(par), 1);

CurveStyleParam curPar;

//берем параметры стиля

GetStyleParam(CURVE_STYLE_EX, tl, &curPar, sizeof(curPar));

//если стиль с картинками продолжаем

if (curPar.curveType == 2) {

CurvePatternEx par;

int count = GetArrayCount(curPar.pattern);

//убеждаемся, что в стиле есть преривистые участки

if (count){

//берем первый участок

GetArrayItem(curPar.pattern, // указатель на массив

0, // индекс в массиве (нумерация начинается с 0)

&par,// указатель на структуру элемента

sizeof(par)); // размер структуры элемента

//устанавливаем признак, что картинку возьмем из фрагмента

par.pictureType = 1;

//удаляем массивы полилиний прежней картинки

DeleteArray(par.picture.polygon);

DeleteArray(par.picture.fill);

//подставляем фрагмент

strcpy(par.frwName, "d:\\\0\\\1.frw");

//заменяем первый участок в стиле

SetArrayItem(curPar.pattern, // указатель на массив

0, // индекс в массиве (нумерация начинается с 0)

&par,// указатель на структуру элемента

sizeof(par)); // размер структуры элемента

}

}

//создаем новый стиль, который будет иметь картинку, взятую из фрагмента

unsigned short tl1 = AddStyle(CURVE_STYLE_EX, &curPar, sizeof(curPar), 0);

//создадим окружность с этим стилем

Circle(100,100, 50, tl1);
