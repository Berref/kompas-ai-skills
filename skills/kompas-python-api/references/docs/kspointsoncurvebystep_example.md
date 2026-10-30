# ksPointsOnCurveByStep - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x = 100, y = 100, step = 10.5;

// указанная кривая

reference pObj = ::FindObj(x, y, 1000);

if (::ExistObj(pObj)) { // проверим существование объекта

reference arr = ::ksPointsOnCurveByStep(pObj, step); // массив точек

uint count = ::GetArrayCount(arr); // количество полученных точек

MathPointParam point;

// нарисуем точки

for (uint i = 0; i < count; i++)

if (::GetArrayItem(arr, i, &point, sizeof(MathPointParam)))

::Point(point.x, point.y, 4);

}
