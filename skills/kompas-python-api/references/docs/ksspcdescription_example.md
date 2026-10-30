# Пример использования функций работы с описаниями спецификации

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference doc = ::ksGetCurrentDocument(0); // текущий документ

if (doc) {

SpcDescrParam param; // параметры описания

::memset(&param, 0, sizeof(SpcDescrParam)); // очистить параметры

::strcpy(param.layoutName, "C:\\\gr\\\graphic.lyt"); // имя файла библиотеки

//стилей спецификаций

param.styleId = 15; // номер стиля в библиотеке

if (::ksAddSpcDescription(doc, &param)) { // добавить описание в документ

bool state; // состояние описания СП

if (::ksGetSpcDescription(doc, 0, &param, &state)) { // считать описание с индексом 0

char buf[1000]; // создать сообщение

::sprintf(buf, "индекс СП: %d,\nИмя библиотеки: %s,\nНомер стиля: %d,\nИмя файла: %s,\nСостояние: %s",

0, param.layoutName, param.styleId, param.spcName, state ? "Активный" : "Неактивный");

::Message(buf); // вывести сообщение

}

param.styleId = 2; // номер стиля в библиотеке

if (::ksSetSpcDescription(doc, 0, &param, state)) // изменить описание с индексом 0

if (::ksGetSpcDescription(doc, 0, &param, &state)) { // считать описание с индексом 0

char buf[1000]; // создать сообщение

::sprintf(buf, "индекс СП: %d,\nИмя библиотеки: %s,\nНомер стиля: %d,\nИмя файла: %s,\nСостояние: %s",

0, param.layoutName, param.styleId, param.spcName, state ? "Активный" : "Неактивный");

::Message(buf); // вывести сообщение

}

::ksDeleteSpcDescription(doc, 0); // удалить описание с индексом 0

}

}
