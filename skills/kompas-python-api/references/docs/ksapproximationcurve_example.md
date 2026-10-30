# ksApproximationCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
if (ksGetCurrentDocument(1)) {

reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите кривую для аппроксимации";

int j;

double eps = 0.1; //точность аппроксимации

bool curentLayer = true;//строить на текущий слой

bool delParent = false; //не удалять подложку

do {

j = Cursor(&info, &x, &y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, 1e6))){

j = GetObjParam(pObj, 0,0,0);

if (j == BEZIER_OBJ || j == NURBS_OBJ || j == ELLIPSE_OBJ || j == ELLIPSE_ARC_OBJ

|| j == EQUID_OBJ || j == CONTOUR_OBJ) {

reference pApp = ksApproximationCurve(pObj, // указатель на кривую

eps, // точность аппроксимации 1e-7...1

curentLayer,

0, 1);// тип размещения по слоям 0 - на слой кривой 1- в текущий слой

LightObj(pApp, 1);

if (delParent)

DeleteObj(pObj);

Message("Аппроксимированная кривая");

LightObj(pApp, 0);

}

else

Error("Неверно указана кривая для аппроксимации");

}

}

}while (j);

}

else

Error("Документ не активизирован или не является листом/фрагментом");
