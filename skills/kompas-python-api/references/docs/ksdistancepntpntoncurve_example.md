# ksDistancePntPntOnCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x, y;

if (::Cursor(NULL, &x, &y, NULL)) { // указываем кривую

reference curve = ::FindObj(x, y, 1000); // найти ближайшую кривую

double x1, y1;

if (::ExistObj(curve) && ::Cursor(NULL, &x, &y, NULL) // проверим, существует ли кривая

&& ::Cursor(NULL, &x1, &y1, NULL)) { // и укажем две точки на кривой

double len = ::ksDistancePntPntOnCurve(curve, x, y, x1, y1); // расстояние между точками

char buf[128];

::sprintf(buf, "Расстояние между точками = %g", len);

::Message(buf); // выведем результат

}

}
