# Equidistant - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pContour;

RequestInfo info;

//обнулить структуру info;

memset (&info, 0, sizeof(info));

double x, y;

info.prompt = "Укажите контур";

int j = Cursor (&info, &x, &y, 0);

if (j)

{

if (ExistObj (pContour = FindObj (x, y, 1e6)) &&

GetObjParam (pContour, 0, 0, 0) == CONTOUR_OBJ) {

//если нашли объект и этот объект - контур, строим эквидистанту

EquidistantParam equidParam;

//обнулить структуру info;

memset(&equidParam, 0, sizeof(equidParam));

equidParam.geoObj = pContour; // геометрический объект

//-базовая кривая эквидистанты

equidParam.side = 0 ; // признак, с какой стороны строить эквидистанту

equidParam.cutMode = 1; // тип обхода углов контура: 0-обход срезом, 1- обход дугой

equidParam.degState = 0; // флаг разрешения вырожденных сегментов эквидистанты:

// 0-вырожденные сегменты запрещены,

//1-вырожденные сегменты разрешены

equidParam.radRight = 1; // радиус эквидистанты справа по направлению кривой

equidParam.radLeft = 1; // радиус эквидистанты слева

equidParam.style = 1; // тип линии

for (int i = 0; i < 4; i++) {

equidParam.radRight += i;

equidParam.radLeft += i;

Equidistant(&equidParam); //параметры эквидистанты

}

}

}
