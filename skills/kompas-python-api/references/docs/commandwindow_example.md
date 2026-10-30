# CommandWindow - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void CommandWindow_Example (void) {

RequestInfo info;

memset(&info, 0, sizeof(info));

info.commands = "!Окружность !Отрезок ";

info.commands = Объекты

int j=CommandWindow(&info);

switch (j) {

case 1:

Circle(10,10,10,1);

break;

case 2:

LineSeg(10,10, 20, 10, 1);

break;

}

}; /* CommandWindow_Example */
