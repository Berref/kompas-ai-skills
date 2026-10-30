# AddObjGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void AddObjGroup_Example (void) {

reference gr,p ;

p = LineSeg(0, 0, 80, 0, 3); /* осевая линия */

gr = NewGroup(0); /* задание группы объектов */

LineSeg (10, 10, 10, 20, 1); /* объекты записываются */

LineSeg (10, 20, 40, 20, 1); /* в модель текущего вида */

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

EndGroup(); /* закончить формирование группы */

AddObjGroup(gr, p); /* добавить объект p */

LightObj(gr, 1); /* подсветить группу */

if (Yes_No(Удалять группу?))

DeleteObj(gr);

}; /* AddObjGroup_Example */
