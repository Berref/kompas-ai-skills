# ksTanLinePointCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//поиск окружностей сопряжения для прямой и окружности

RequestInfo info;

::memset(&info, 0, sizeof(info));

info.commands = "Укажите объект";

double x, y;

int j;

reference pArray = ::CreateArray(POINT_ARR, 0);

do { //найдем объект

j = ::Cursor(&info, &x ,&y, 0);

if (j) {

reference pObj = ::FindObj(x, y, 1e6);

if(::ExistObj(pObj)){

info.commands = "Укажите точку";

if (::Cursor(&info, &x ,&y, 0)) {

::ksTanLinePointCurve(x, y, // координаты точки

pObj, // указатель на кривую

pArray); // массив точек касания

MathPointParam par; // Структура параметров математической точки

::memset(&par, 0, sizeof(MathPointParam));

for(int i = 0, count = ::GetArrayCount(pArray); i < count; i) {

::GetArrayItem(pArray, i, &par, sizeof(MathPointParam));

::LineSeg(x, y, par.x, par.y, 1);

}

::ClearArray(pArray);

}

}

else

::Error("объект не найден");

}

} while(j);
