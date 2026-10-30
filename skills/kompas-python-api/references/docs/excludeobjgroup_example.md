# ExcludeObjGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ExcludeObjGroup_Example (void) {

reference gr,p ;

gr = NewGroup(0); /* задание группы объектов */

LineSeg (10, 10, 10, 20, 1); /* объекты записываются */

LineSeg (10, 20, 40, 20, 1); /* в модель текущего вида */

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

p = LineSeg(0, 0, 80, 0, 3); /* осевая линия */

EndGroup(); /* закончить формирование группы */

ExcludeObjGroup(gr, p); /* исключить объект p */

LightObj(gr, 1); /* подсветить группу */

if (Yes_No(Удалять группу?))

DeleteObj(gr);

}; /* ExcludeObjGroup_Example */
