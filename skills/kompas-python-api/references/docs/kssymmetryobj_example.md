# ksSymmetryObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference cir =Circle(20, 10, 20, 1);

reference p = ksSymmetryObj(cir, 20, 35, 40, 35, 1); // указатель на объект

LightObj (p, 1);

Message("подсветили полученный объект");

LightObj (p, 0);
