# SymmetryObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void SymmetryObj_Example (void) {

reference gr ;

gr = NewGroup(0); /* задание группы объектов */

LineSeg (10, 10, 10, 20, 1); /* объекты записываются */

LineSeg (10, 20, 40, 20, 1); /* в модель текущего вида */

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

EndGroup(); /* закончить формирование группы */

/* симметрия относительно оси X */

if (Yes_No(Выполнять осевую симметрию))

SymmetryObj(gr, 0, 0, 100, 0, 0);

}; /* SymmetryObj_Example */
