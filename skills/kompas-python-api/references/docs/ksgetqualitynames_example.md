# ksGetQualityNames - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference names = ::CreateArray(CHAR_STR_ARR, 0); // динамический массив строк

// получить поля допусков для размера 139 мм, верхнее отклонение 0.16 мм,

// нижнее - 0 мм, система отверстия, с учётом ограничений

if (::ksGetQualityNames(names, 139, 0.16, 0, 1/*system*/, 1/*withLimitation*/)) {

string s(""); // строка сообщения

int count = ::GetArrayCount(names); // кол-во элементов в массиве

for (int i = 0; i < count; i++) { // пройдём по всему массиву

char item[255]; // буфер

if (::GetArrayItem(names, i, item, 255)) { // взять текущую строку из массива

s += item; // добавить её к сообщению

s += " "; // разделитель

}

} // выводим сообщение

::Message((char*)s.c_str()); // удалить массив

::DeleteArray(names);

}
