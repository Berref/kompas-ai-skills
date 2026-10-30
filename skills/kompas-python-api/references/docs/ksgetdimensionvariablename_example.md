# ksGetDimensionVariableName - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference iter = ::CreateIterator(LDIMENSION_OBJ, 0); // создаем итератор по линейным размерам

if (iter) {

reference obj = ::MoveIterator(iter, 'F'); // первый объект

char buf[128]; // буфер для имени переменной

while (::ExistObj(obj)) { // размер существует

if (::ksGetDimensionVariableName(obj, buf, 128)) // получим имя параметрической переменной размера

::Message(buf); // выведем имя переменнной

else // у размера нет переменной

::Message("Размер не имеет переменной"); // сообщение

obj = ::MoveIterator(iter, 'N'); // следующий объект

}

::DeleteIterator(iter); // удалим итератор
