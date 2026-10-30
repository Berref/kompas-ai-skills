# ksGetWorkWindowColor - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
unsigned long color = ksGetWorkWindowColor ();

char buf [128];

sprintf (buf, "Цвет фона рабочего окна = %ld ", color);

Message (buf);
