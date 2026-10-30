# GetGroup - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void GetGroup_Example (void)

{

reference gr, p ;

gr = NewGroup(1); // задание группы объектов

LineSeg (-15, 0, 15, 0, 3); // объекты записываются

LineSeg ( 0, -15, 0, 15, 3); // во временный список

Circle (0, 0, 10, 1);

EndGroup(); // закончить формирование группы

SaveGroup (gr, Отверстие);

p = GetGroup (Отверстие);

LightObj (p, 1);

};
