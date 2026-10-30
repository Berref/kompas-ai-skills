# ksDistancePntLineForPoint - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset (&info, 0, sizeof(info));

info.prompt = "Укажите отрезок";

reference g;

int j = Cursor (&info, &x, &y, 0);

if (j)

{

//найдем объект и убедимся, что это отрезок

if (ExistObj(pObj = FindObj (x, y, 1e6)) && GetObjParam (pObj, 0, 0, 0) == LINESEG_OBJ)

{

info.prompt = "Укажите точку";

//получим точку

j = Cursor (&info, &x ,&y, 0);

if (j)

{

LineSegParam par;

//берем параметры отрезка

GetObjParam (pObj, &par, sizeof (LineSegParam), ALLPARAM);

//получаем расстояние от точки до отрезка

double len = ksDistancePntLineForPoint (x, y, //координаты точки

par.x1, par.y1, //координаты точки на прямой

par.x2, par.y2); //координаты точки на прямой

char buf[TEXT_LENGTH];

sprintf (buf, "расстояние = %f ", len);

Message (buf);

}

}

else

Error("Это не отрезок");

}
