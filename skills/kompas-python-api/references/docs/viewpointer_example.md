# ViewPointer - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ViewPointer_Example (void)

{

ViewPointerParam par;

memset (&par, 0, sizeof (ViewPointerParam));

par.x1 = 55; par.y1 = 50; // координаты вершины (острия) стрелки

par.x2 = 40; par.y2 = 50; // координаты конечной точки стрелки

par.xt = 40; par.yt = 52; // координаты текста

strcpy(par.str, A); // надпись

reference p = ViewPointer (&par); //параметры стрелки вида

if (ExistObj(p))

LightObj(p, 1);

};
