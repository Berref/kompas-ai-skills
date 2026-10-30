# ksGetTextAlign, ksSetTextAlign - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference iter = ::CreateIterator(TEXT_OBJ, 0); // итератор по всем текстам документа

if (iter) {

reference txt = ::MoveIterator(iter, 'F'); // первый текст

while (::ExistObj(txt)) { // пройдем по всем текстам

if (::ksGetTextAlign(txt) == txta_Left) // если точка привязки текста слева

::ksSetTextAlign(txt, txta_Right); // установим ее справа

txt = ::MoveIterator(iter, 'N'); // следующий текст

}

}

::DeleteIterator(iter); // удалим итератор
