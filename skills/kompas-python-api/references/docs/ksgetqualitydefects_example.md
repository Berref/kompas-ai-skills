# ksGetQualityDefects - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double high = 0, low = 0; // отклонения

char name[20]; // поле допуска

::strcpy(name, "H7"); // умолчательное значение

if (ReadString("Укажите поле допуска", name, 4)) { // запрос поля допуска у пользователя

double dimValue = 15; // значение размера в мм

if (ReadDouble("Введите размер в мм:", 15, 0, 500, &dimValue)) { // запрос значения размера у пользователя

::ksGetQualityDefects(name, dimValue, &high, &low, true/*inMM*/); // получить отклонения в мм

char buf[255]; // строка сообщения

::sprintf(buf, "Поле допуска %s\nЗначение = %g, high = %g, low = %g",

name, dimValue, high, low); // формируем сообщение

::Message(buf); // выводим сообщение
