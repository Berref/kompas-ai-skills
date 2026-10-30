# ksMovePointOnCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//неравномерное размещение точек и перпендикуляров к ним на кривой

static double pointLen[] = { 0, 5, 10, 15, 10, 5 };

int count = 6;

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите точку на кривой";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, 1e6))){

//узнаем тип объекта

int type = GetObjParam(pObj, 0, 0, 0); //указатель на графический объект

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

type == REGULARPOLYGON_OBJ //многоугольник

) {

for (int i = 0; i < count; i) {

if (ksMovePointOnCurve(pObj, //указатель на кривую

&x, &y, //координаты точки

pointLen[i], //расстояние на которое нужно сместить точку

1)) { //направление продвижения точки(1 - в направлении построения кривой, -1 в обратном направлении)

//построим точку

Point(x, y, 0);

//найдем перпендикуляр к кривой в точке

double angl = ksGetCurvePerpendicular(pObj, x, y);

//построим перпендикуляр (отрезок длиной 10 мм)

double x1 = x, y1 = y, x2 = x, y2 = y;

MovePoint ( &x1, &y1, angl, 5);

MovePoint ( &x2, &y2, angl180, 5);

LineSeg (x1, y1, x2, y2, 2);

}

}

}

else

Error("Выбранный объект не кривая");

}

}
