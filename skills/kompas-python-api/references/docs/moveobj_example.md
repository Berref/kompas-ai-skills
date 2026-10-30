# MoveObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void MoveObj_Example (void) {

reference gr ;

double x1,y1,x2,y2;

gr = NewGroup(0); /* задание группы объектов */

LineSeg (-15, 0, 15, 0, 3); /* объекты записываются */

LineSeg ( 0, -15, 0, 15, 3); /* в модель текущего вида */

Circle (0, 0, 10, 1);

EndGroup(); /* закончить формирование группы */

RequestInfo info;

memset(&info, 0, sizeof(info));

info.commands = " Базовая точка "; /* задание вектора сдвига */

if (Cursor(&info,&x1,&y1,0)){

info.commands = " Ее новое положение "; /* задание вектора сдвига */

if (Cursor(&info,&x2,&y2, 0))

MoveObj(gr, x2-x1, y2-y1, 0); /* сдвиг группы gr */

}

}; /* MoveObj_Example */
