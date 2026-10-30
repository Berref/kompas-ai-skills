# ksMakeEncloseContours, ksHatch - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
RequestInfo info;

//обнулить структуру info;

memset(&info, 0, sizeof(info));

double x, y;

info.prompt = "Укажите точку внутри области";

int j = Cursor(&info, &x ,&y, 0);

if (j) {

HatchParam par;

memset(&par, 0, sizeof(par));

par.step = 2;

par.ang = 45;

//границы штриховки вычисляем

par.pBoundaries = ksMakeEncloseContours(0, x, y);

//штриховка

reference h = ksHatch(&par);

if (h) {

LightObj(h, 1);

Message("Создали штриховку в виде по точке внутри области");

LightObj(h, 0);

}

else

Error("Ошибка в задании штриховки");

}
