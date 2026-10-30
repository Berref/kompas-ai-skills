# ksSetObjConstraint - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//Установить ограничение "равенство радиусов двух дуг/окружностей"

reference p;

RequestInfo info;

//обнулить структуру info;

memset(&info, 0, sizeof(info));

double x, y;

info.prompt = "Укажите первую дугу или окружность";

int j = Cursor (&info, &x ,&y, 0);

if (j) {

if (ExistObj(p = FindObj (x, y, 1e6))) {

info.prompt = "Укажите вторую дугу или окружность";

j = Cursor (&info, &x ,&y, 0);

reference p1;

if (j) {

if (ExistObj (p1 = FindObj (x, y, 1e6))) {

ConstraintParam par;

memset (&par, 0, sizeof (par));

par.constrType = CONSTRAINT_EQUAL_RADIUS;

par.partner = p1;

ksSetObjConstraint (p, &par);

}

}

}

}
