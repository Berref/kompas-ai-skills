# Nurbs, NurbsPoint - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Nurbs_Example (void) {

static NurbsPointParam par[]={{ 0,0,1}, {20,20,1}, {50,10,1}, {70,20,1}, {100,0,1}, {50,-50,1}};

//построить Nurbs-кривую

if (Nurbs(3, 0, 1))

for (int i=0; i<6; i) {

NurbsPoint(&par[i]);

}

reference p = EndObj();

LightObj(p, 1);

Message(NURBS);

LightObj(p, 0);

}

}; /* Nurbs_Example */
