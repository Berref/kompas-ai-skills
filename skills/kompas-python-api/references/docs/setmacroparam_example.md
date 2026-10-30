# SetMacroParam - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// пример построения прямоугольника с последующим его редактированием

void DrawRect ()

{

struct

{

double a;

double b;

}

r;

if (EditMacroMode())

//режим редактирования

GetMacroParam (m, &r, sizeof (r));

else

//cоздание нового макроэлемента

{

r.a = 20;

r.b = 10;

}

ReadDouble ("задайте ширину",r.a,0,100, &r.a);

ReadDouble ("задайте высоту",r.b,0,100, &r.b);

Macro(); /* определение макроэлемента */

// Прямоугольник

LineSeg(0, 0, r.a, 0, 0);

LineSeg(r.a, 0, r.a, r.b, 0);

LineSeg(r.a, r.b, 0, r.b, 0);

LineSeg(0, r.b, 0, 0, 0);

reference m = EndObj();

//записать параметры в макроэлемент

SetMacroParam (m, &r, sizeof(r), NULL, NULL, -1);

};
