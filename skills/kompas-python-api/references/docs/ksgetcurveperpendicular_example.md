# ksGetCurvePerpendicular, ksPointsOnCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//равномерное размещение точек и перпендикуляров к ним на кривой

reference pObj;

int count = 10;

RequestInfo info;

double x, y;

memset (&info, 0, sizeof (info));

info.prompt = "Укажите кривую";

int j = Cursor (&info, &x, &y, 0);

if (j)

{

if (ExistObj(pObj = FindObj(x, y, 1e6)))

{

//узнаем тип объекта

int type = GetObjParam (pObj, 0, 0, 0); //указатель на графический объект

if (type == CIRCLE_OBJ || //окружность

type == ARC_OBJ || //дуга

type == NURBS_OBJ || //nurbs

type == LINESEG_OBJ || //отрезок

type == BEZIER_OBJ || //bezier

type == CONTOUR_OBJ || //контур

type == POLYLINE_OBJ || //полилиния

type == ELLIPSE_OBJ || //эллипс

type == ELLIPSE_ARC_OBJ || //дуга эллипса

type == RECTANGLE_OBJ || //прямоугольник

type == REGULARPOLYGON_OBJ) //многоугольник

{

//получим массив точек

reference pointArr = ksPointsOnCurve (pObj, //указатель на кривую

count); //количество точек

if (pointArr)

{

for (uint i = 0; i < count; i)

{

//в цикле получим все точки на кривой

MathPointParam par;

if (GetArrayItem (pointArr, // указатель на массив

i, // индекс в массиве

// (нумерация начинается с 0)

&par, // указатель на структуру элемента

sizeof (MathPointParam)))

// размер структуры элемента

{

//построим точку

Point (par.x, par.y, 0);

//найдем перпендикуляр к кривой в точке

double angl = ksGetCurvePerpendicular(pObj, par.x, par.y);

//построим перпендикуляр (отрезок длиной 10 мм)

double x1 = par.x, y1 = par.y, x2 = par.x, y2 = par.y;

MovePoint ( &x1, &y1, angl, 5);

MovePoint ( &x2, &y2, angl180, 5);

LineSeg (x1, y1, x2, y2, 2);

}

else

MessageBoxResult (); //ошибка доступа к объекту массива

}

}

else

MessageBoxResult (); //ошибка

}

else

Error ("Выбранный объект - не кривая");

}

}
