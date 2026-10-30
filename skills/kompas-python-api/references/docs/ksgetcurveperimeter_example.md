# ksGetCurvePerimeter, ksCalcInertiaProperties, ksCalcMassInertiaProperties - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите кривую";

int j = Cursor(&info, &x, &y, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, 1e6))){

//узнаем тип объекта

int type = GetObjParam( pObj,0,0,0); //указатель на графический объект

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

//периметр кривой

double perimeter = ksGetCurvePerimeter(pObj, ST_MIX_MM); //указатель на кривую

char buf[255];

sprintf(buf, "Периметр = %f", perimeter);

Message(buf);

InertiaParam inertiaPar;

//рассчитаем плоские моментно - центровочные характеристики кривой

int rez = ksCalcInertiaProperties(pObj, //указатель на кривую или группу кривых

&inertiaPar, //указатель на структуру моментно-центровочных характеристик

ST_MIX_MM); //размерность в интервале [ST_MIX_SM..ST_MIX__M]

if (rez) {

sprintf(buf, "Центр xc = %f yc = %f площадь = %f", inertiaPar.xc, inertiaPar.yc, inertiaPar.f);

Message(buf);

sprintf(buf, "Моменты инерции относительно исходных осей x и y\nlx = %f ly = %f lxy = %f", inertiaPar.lx, inertiaPar.ly, inertiaPar.lxy);

Message(buf);

sprintf(buf, "Центральные моменты инерции\nmx = %f my = %f mxy = %f", inertiaPar.mx, inertiaPar.my, inertiaPar.mxy);

Message(buf);

sprintf(buf, "Главные центральные моменты инерции\njx = %f jy = %f угол = %f", inertiaPar.jx, inertiaPar.jy, inertiaPar.a);

Message(buf);

MassInertiaParam mInertiaPar;

//для тела выдавливания моментно-центровочные характеристики

rez = ksCalcMassInertiaProperties(pObj, // указатель на кривую или группу кривых

&mInertiaPar, // указатель на структуру массово-центровочных характеристик

ST_MIX_MM|ST_MIX_GR|ST_MIX_EXT , // набор флагов

2.7, // плотность (г/мм3)

100); // если тело вращения-угол раствора в градусах, тело выдавливания - толщина

if (rez) {

sprintf(buf, "плотность = %f масса = %f объем = %f", mInertiaPar.r, mInertiaPar.m, mInertiaPar.v);

Message(buf);

sprintf(buf, "координаты центра тяжести\n xc= %f yc = %f zc = %f", mInertiaPar.xc, mInertiaPar.yc, mInertiaPar.zc);

Message(buf);

sprintf(buf, "центробежные моменты инерции\n lxy= %f lxz = %f lyz = %f", mInertiaPar.lxy, mInertiaPar.lxz, mInertiaPar.lyz);

Message(buf);

sprintf(buf, "осевые моменты инерции\n lx= %f ly = %f lz = %f", mInertiaPar.lx, mInertiaPar.ly, mInertiaPar.lz);

Message(buf);

sprintf(buf, "плоскостные моменты инерции\n jy0z= %f jx0z = %f lx0y = %f", mInertiaPar.jy0z, mInertiaPar.jx0z, mInertiaPar.jx0y);

Message(buf);

sprintf(buf, "Главные центробежные моменты инерции\n jxy= %f jxz = %f jyz = %f", mInertiaPar.jxy, mInertiaPar.jxz, mInertiaPar.jyz);

Message(buf);

sprintf(buf, "Главные осевые моменты инерции \n jx= %f jy = %f jz = %f", mInertiaPar.jx, mInertiaPar.jy, mInertiaPar.jz);

Message(buf);

}

}

else

Error ("Ошибка");

}

else

Error("Выбранный объект не кривая");

}

}
