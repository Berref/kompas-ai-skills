# ksColouring - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//заливка цветом

Mtr(30,20,0,0.5);

char buf [128];

//построить заштрихованный квадрат

LineSeg (20, 30, 70, 30, 2);

LineSeg (70, 30, 70, 80, 2);

LineSeg (70, 80, 20, 80, 2);

LineSeg (20, 80, 20, 30, 2);

// залить квадрат цветом

if(ksColouring(RGB(168,0,168))) {

LineSeg (20, 30, 70, 30, 2);

LineSeg (70, 30, 70, 80, 2);

LineSeg (70, 80, 20, 80, 2);

LineSeg (20, 80, 20, 30, 2);

reference p = EndObj();

//взять параметры заливки - цвет

unsigned long col;

int t = GetObjParam(p, &col, sizeof(col), ALLPARAM);

sprintf(buf, " t = %d, color=%d ", t, col);

Message(buf);

DeleteMtr();

Mtr(0,0,0,2);

col = RGB(0, 255, 255);

//изменить параметры заливки - цвет

if(SetObjParam(p, &col, sizeof(col), ALLPARAM))

Message(" Изменили объект");

else

MessageBoxResult();

DeleteMtr();

}

else

MessageBoxResult();
