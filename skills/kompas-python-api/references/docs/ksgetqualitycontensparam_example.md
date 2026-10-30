# ksGetQualityContensParam - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char name[20]; // поле допуска

::strcpy(name, "H7"); // умолчательное значение

if (ReadString("Укажите поле допуска", name, 4)) { // запрос поля допуска у пользователя

char buf[255]; // буфер

string s(""); // строка сообщения

if (!::strcmp(name, "")) { // пустая строка - идём итератором

// итератор по системе отверстия с учётом ограничений наложенных в системе

reference iter = ::ksCreateQualityIterator(1/*system*/, 1/*withLimitation*/);

if (iter) { // итератор создан

QualityContensParam param; // структура параметров квалитета

int first = 0; // начало чтения

// продолжаем чтение пока не считаем все квалитеты

while (::ksMoveQualityIterator(iter, &param, false/*inMM*/, !first ? 'F' : 'N')) {

::sprintf(buf, "Система %s, Тип квалитета %i, Поле допуска %s\n",

(param.systemQuality == 1 ? "Вала" : "Отверстия"), param.kindQuality,

param.name); // формируем строку для текущего квалитета

s += buf; // добавляем к сообщению

int count = ::GetArrayCount(param.pQualityItems); // кол-во интервалов

for (int i = 0; i < count; i++) { // проходим по всем интервалам

QualityItemParam item; // запись об одном интервале для какого-то квалитета

// считываем текущюю запись

if (::GetArrayItem(param.pQualityItems, i, &item, sizeof(QualityItemParam))) {

// выводим параметры интервала в строку

::sprintf(buf, "Значение: %i < X < %i, high = %g, low = %g\n",

item.minLimit, item.maxLimit, item.high, item.low);

s += buf; // добавляем к сообщению

}

}

::Message((char*)s.c_str()); // выводим сообщение

s = ""; // очищаем строку сообщения

::DeleteArray(param.pQualityItems); // удаляем массив интервалов

param.pQualityItems = 0;

if (!first) // пришли первый раз

first = 1; // взводим флаг

}

::DeleteIterator(iter); // удалить итератор

}

}

else { // имя есть

QualityContensParam param; // структура параметров квалитета

// считываем параметры указанного квалитета

if (::ksGetQualityContensParam(name, &param, false/*inMM*/)) {

::sprintf(buf, "Система %s, Тип квалитета %i, Поле допуска %s\n",

(param.systemQuality == 1 ? "Вала" : "Отверстия"), param.kindQuality,

param.name); // формируем строку для текущего квалитета

s += buf; // добавляем к сообщению

int count = ::GetArrayCount(param.pQualityItems); // кол-во интервалов

for (int i = 0; i < count; i++) { // проходим по всем интервалам

QualityItemParam item; // запись об одном интервале для какого-то квалитета

// считываем текущюю запись

if (::GetArrayItem(param.pQualityItems, i, &item, sizeof(QualityItemParam))) {

// выводим параметры интервала в строку

::sprintf(buf, "Значение: %i < X < %i, high = %g, low = %g\n",

item.minLimit, item.maxLimit, item.high, item.low);

s += buf; // добавляем к сообщению

}

}

::Message((char*)s.c_str()); // выводим сообщение

s = ""; // очищаем строку сообщения

::DeleteArray(param.pQualityItems); // удаляем массив интервалов

param.pQualityItems = 0;

}

}

}
