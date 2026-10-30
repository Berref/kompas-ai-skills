# ksPolylineEx - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
PolylineParamEx par;

::memset(&par, 0, sizeof(PolylineParamEx));

par.pMathPoint = ::CreateArray(POINT_ARR, 0);

MathPointParam p;

p.x = 0;

p.y = 0;

::AddArrayItem(par.pMathPoint, -1, &p, sizeof(p));

p.x = 100;

p.y = 0;

::AddArrayItem(par.pMathPoint, -1, &p, sizeof(p));

p.x = 150;

p.y = 100;

::AddArrayItem(par.pMathPoint, -1, &p, sizeof(p));

p.x = 0;

p.y = 100;

::AddArrayItem(par.pMathPoint, -1, &p, sizeof(p));

par.style = 1;

par.closed = 1;

reference line = ::ksPolylineEx(&par);

if (line) {

::Message("Изменим стиль");

::memset(&par, 0, sizeof(PolylineParamEx));

::GetObjParam(line, &par, sizeof(par), ALLPARAM);

par.style = 3;

::SetObjParam(line, &par, sizeof(par), ALLPARAM);

}
