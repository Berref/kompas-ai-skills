# ExistObj, ExistGroupObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ExistObj_Example (void) {

reference l1, gr ;

LineSeg (10, 10, 10, 20, 1); /* объекты записываются */

LineSeg (10, 20, 40, 20, 1); /* в модель текущего вида */

l1 = LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg(0, 0, 80, 0, 3); /* осевая линия */

gr = NewGroup(0); /* определение группы объектов */

LineSeg (70, 10, 10, 10, 1);

EndGroup(); /* закончить формирование группы */

/* добавить объекты в интерактивном режиме */

SelectGroup(gr, 0, 0, 0, 0, 0);

LightObj(gr, 1); /* подсветить группу */

if ((!(ExistGroupObj(gr))) && (YesNo("Удалять группу?"))) //удалить группу, если она пустая ?

DeleteObj(gr);

if (ExistObj(l1)) LightObj(l1,1);

}; /* ExistObj_Example */
