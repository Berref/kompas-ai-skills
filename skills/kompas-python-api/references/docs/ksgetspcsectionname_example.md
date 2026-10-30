# ksGetSpcSectionName - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// создадим итератор по вспомогательным объектам спецификации в текущем документе

reference iter = ::CreateSpcIterator (0, 0, 1/*вспомогательные объекты спецификации*/);

if (iter) {

// встаем на первый объект спецификации

reference spcObj = ::MoveIterator (iter, 'F');

// проверяем, что объект действительно существует

if (spcObj && ::ExistObj (spcObj)) {

do {

char spcSectionName[128]; // имя раздела спецификации

// запрашиваем имя раздела

if (::ksGetSpcSectionName (spcObj, spcSectionName, sizeof (spcSectionName)))

::Message (spcSectionName);

// встаем на следующий объект спецификации

spcObj = ::MoveIterator (iter, 'N');

} while (spcObj && ::ExistObj (spcObj));

}

::DeleteIterator(iter); // удаляем итератор

}
