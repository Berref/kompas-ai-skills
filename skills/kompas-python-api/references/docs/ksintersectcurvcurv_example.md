# ksIntersectCurvCurv - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference line = ::LineSeg(-100, -100, 100, 100, 1); // отрезок

reference cir = ::Circle (20, 20, 35, 1); // окружность

reference array = ::CreateArray(POINT_ARR, 0); // создать пустой массив точек пересечения

if (::ksIntersectCurvCurv(line, cir, array) > 0) { // найти точки пересечения кривых

int count = ::GetArrayCount(array); // количество элементов в массиве

char buf[128];

::sprintf(buf, "кол-во элементов = %i", ::GetArrayCount(arr));

::Message(buf);

MathPointParam par;

for (int i = 0; i < count; i) {

if (::GetArrayItem(array, i, &par, sizeof(MathPointParam))) {

::sprintf(buf, "координаты %i-й точки : %g ; %g", i, par.x, par.y);

::Message(buf);

}

}

}
