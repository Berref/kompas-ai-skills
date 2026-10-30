# ksMtr - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference gr = NewGroup (0);

LineSeg (50, 50, 100, 100, 1);

LineSeg (100, 100, 150, 50, 1);

Circle (50, 50, 10, 1);

Circle (150, 50, 10, 1);

EndGroup ();

//масштаб по оси Х - 2 и по оси Y - 1

ksMtr (0, 0, 0, 2, 1);

TransformObj (gr);

DeleteMtr();
