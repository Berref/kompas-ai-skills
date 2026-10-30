# ksOpenMacro - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Macro (0);

LineSeg(50,100, 100, 150, 1);

reference p = EndObj();

Message("Создан макроэлемент");

ksOpenMacro (p);

Macro (0);

reference cir = Circle(50, 50, 20, 1);

reference p1 = EndObj();

EndObj();

Message("Макроэлемент отредактирован");
