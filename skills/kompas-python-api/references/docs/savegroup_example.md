# SaveGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void SaveGroup_Example (void) {

reference gr ;

char name[40];

gr = NewGroup(0); /* определение группы объектов */

LineSeg (10, 10, 10, 20, 1); /* объекты записываются */

LineSeg (10, 20, 40, 20, 1); /* в модель текущего вида */

LineSeg (40, 20, 40, 30, 1);

LineSeg (40, 30, 70, 30, 1);

LineSeg (70, 30, 70, 10, 1);

LineSeg (70, 10, 10, 10, 1);

EndGroup(); /* закончить формирование группы */

LightObj(gr, 2); /* подсветить группу */

if (Yes_No(Сохранять группу в модели?)) {

ReadString(Имя группы, name, 40);

SaveGroup(gr, name);

}

LightObj(gr, 0); /* снять выделение группы */

}; /* SaveGroup_Example */
