# ksClearGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference gr = NewGroup(1); // временная группа геометрии

::LineSeg(100, 100, -100, -100, 1);

::LineSeg(10, 10, -10, -10, 1);

EndGroup();

// Удалить или нет временные объекты

bool deleteTmp = ::YesNo("Удалить временные объекты") == 1 ? true : false;

::ksClearGroup(gr, deleteTmp/*true - удалять временные объекты, false - не удалять*/);

::StoreTmpGroup(gr); // записываем результаты в документ
