# ksGetSpcStyleParam - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
SpcStyleParam par; // параметры стиляСП

::memset(&par.layoutName1, 0, sizeof(SpcStyleParam)); // очищаем структуру

// Получить параметры для стиля спецификации с номером numb из библиотеки nameLib

::ksGetSpcStyleParam ("graphic.lyt", // имя библиотеки стилей

1, // номер стиля спецификации

&par, // структура параметров

sizeof (SpcStyleParam), // размер структуры параметров

ALLPARAM); // вернуть все параметры стиля спецификации

::Message (par.layoutName1); // имя файла библиотеки оформлений для первого листа

::Message(par.tuning.predefinedTextFileName); // имя файла предопределенных текстов

int count = ::GetArrayCount (par.arrColumn); // количество элементов в массиве

for (int i = 0; i < count; i) { // проходим по массиву стилей колонок СП

SpcStyleColumnParam param; // структура параметров стиля

//колонки спецификации

::GetArrayItem(par.arrColumn, i, &param, sizeof(SpcStyleColumnParam));

// считываем i-й элемент массива

}
