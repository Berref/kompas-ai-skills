# ksGetObjConstraints, ksDestroyObjConstraint - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
static char *str [] = {"фиксировать точку", "точка на кривой",

"горизонталь", "вертикаль",

"параллельность двух прямых или отрезков",

"перпендикулярность двух прямых или отрезков",

"равенство длин двух отрезков",

"равенство радиусов двух дуг/окружностей",

"выравнивать две точки по горизонтали",

"выравнивать две точки по вертикали",

"совпадение двух точек"};

reference p;

RequestInfo info;

//обнулить структуру info;

memset(&info, 0, sizeof(info));

double x, y;

info.prompt = "Укажите объект";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

if (ExistObj (p = FindObj (x, y, 1e6))) {

//вернуть ограничения данного объектка

reference arr = ksGetObjConstraints (p);

int count = GetArrayCount (arr);

char buf [255];

sprintf (buf, " число ограничений = %d ", count);

Message (buf);

ConstraintParam par;

for (int i = 0; i < count; i) {

GetArrayItem (arr, i, &par, sizeof (ConstraintParam));

sprintf (buf, " constrType=%s ",str [par.constrType-1]);

Message (buf);

switch (par.constrType) {

case CONSTRAINT_POINT_ON_CURVE : { //точка на кривой

LightObj (par.partner, 1);

sprintf (buf, "Подсветили партнера->index=%d ", par.partnerIndex);

Message (buf);

LightObj (par.partner, 0);

break;

}

case CONSTRAINT_MERGE_POINTS : //объединение точек

case CONSTRAINT_HOR_ALIGN_POINTS : //выравнивать точки по оси X

case CONSTRAINT_VER_ALIGN_POINTS : { //выравнивать точки по оси Y

LightObj(par.partner, 1);

sprintf (buf, "Подсветили партнера->index=%d\n наш index = %d ",

par.partnerIndex, par.index);

Message (buf);

LightObj (par.partner, 0);

break;

}

case CONSTRAINT_FIXED_POINT : { //фиксировать точку

sprintf (buf, "наш index = %d ", par.partnerIndex);

Message (buf);

break;

}

case CONSTRAINT_PARALLEL : //параллельность двух

//прямых или отрезков

case CONSTRAINT_PERPENDICULAR : //перпендикулярность двух

//прямых или отрезков

case CONSTRAINT_EQUAL_LENGTH : //равенство длин двух отрезков

case CONSTRAINT_EQUAL_RADIUS : { //равенство радиусов двух

//дуг/окружностей

LightObj (par.partner, 1);

Message ("Подсветили партнера");

LightObj (par.partner, 0);

break;

}

}

if (YesNo("Удалить ограничение?"))

ksDestroyObjConstraint (p, &par);

}

}

}
