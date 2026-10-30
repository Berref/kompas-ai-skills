# ksOpenMacro - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//самостоятельный объект вида

reference l = LineSeg(10, 10, 20, 20, 1);

Macro(0);

//внутренний объект макроэлемента

reference l1 = LineSeg(50,100, 100, 150, 1);

reference p = EndObj();

ksOpenMacro (p);

//внутренний объет макроэлемента

Macro(0);

reference cir = Circle(50, 50, 20, 1);

reference p1 = EndObj();

EndObj();
