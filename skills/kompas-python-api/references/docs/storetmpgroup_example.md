# StoreTmpGroup- Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void StoreTmpGroup_Example (void) {

reference gr ;

gr = NewGroup(1); /* задание группы объектов */

LineSeg (-15, 0, 15, 0, 3); /* объекты записываются */

LineSeg ( 0, -15, 0, 15, 3); /* во временный список */

Circle (0, 0, 10, 1);

EndGroup(); /* закончить формирование группы */

if (Yes_No(Фиксируем группу?)) {

StoreTmpGroup(gr);

}; /* StoreTmpGroup*/
