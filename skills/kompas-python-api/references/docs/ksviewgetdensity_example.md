# ksViewGetDensity - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char buf[128];

//вызываем диалог выбора плотности

double density = ksViewGetDensity(0); // дескриптор окна родителя или NULL

sprintf(buf, " densyty = %f г/мм3", density);

Message(buf);
