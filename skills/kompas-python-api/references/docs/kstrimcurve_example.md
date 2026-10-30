# ksTrimCurve - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference iter = ::CreateIterator(ALL_OBJ, 0); // итератор по всем объектам

if (iter) {

reference obj = ::MoveIterator(iter, 'F'); // первый объект

// если объект геометрический - усечем его

if (::IsGeomObject(obj)) {

reference newCurve = ::ksTrimCurve(obj, 0, 20, 0, -20, 1, false);

if (newCurve) {

::LightObj(newCurve, 1); // подсветим объект

::Message ("Усекли кривую"); // выдадим сообщение

::LightObj(newCurve, 0); // погасим подсветку объекта

}

}

::DeleteIterator(iter); // удалить итератор

}
