# ksSpecRough пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ksSpecRough_Example (void)

{

SpecRoughParam *par;

par.style = 1; //стиль

par.sign = 0;

par.t = 1;

par.s [4] = «Rz40»;

SpecRoughObj = ksSpecRough(&par);

};
