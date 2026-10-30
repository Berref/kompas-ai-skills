# ksGetCursorLimit - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x, y; // координаты точки

RequestInfo info; // параметры запроса

memset(&info, 0, sizeof(info)); // очищаем параметры запроса

info.prompt = "Укажите объект"; // строка подсказки

double lim = ::ksGetCursorLimit(); // радиус ловушки курсора

while (::Cursor(&info, &x, &y, 0)) { // запуск процесса указания точки

reference obj = ::FindObj(x, y, lim); // ближайщий объект

if (::ExistObj(obj)) // если объект найден и существует

::LightObj(obj, 1); // подсвечиваем объект

}
