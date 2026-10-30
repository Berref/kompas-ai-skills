# ksGetCursorPosition - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//получить координаты курсора

typeCursorPos = YesNo("С учетом привязок?") == 1 ? 1 : 0;

int j ;

double x, y;

do {

ksGetCursorPosition(&x, &y, typeCursorPos); // координаты курсора в миллиметрах,

// 0 - без учета привязок 1 - с учетом привязок,

char buf[255];

sprintf(buf, " x = %0.2f y = %0.2f; Продолжать? ", x, y);

j = YesNo(buf);

} while(j == 1);
