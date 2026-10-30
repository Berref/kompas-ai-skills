# ksOrdinatedDimension - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
OrdinatedDimParam par; // параметры размера высоты

memset(&par, 0, sizeof(par));

// автоматическое простановка номинала, с подчеркиванием

par.tPar.bitFlag = _AUTONOMINAL|_UNDER_LINE;

par.tPar.pText = CreateArray(CHAR_STR_ARR ,0);

par.dPar.type = OD_FRONTVIEW; // тип - для вида спереди, с полкой и стрелкой, возможна выносная линия

par.sPar.x0 = 0; // координаты точки, задающей нулевой уровень

par.sPar.y0 = 0;

par.sPar.x1 = 0; // координаты точки, задающей измеряемый уровень

par.sPar.y1 = 100;

par.sPar.x2 = 100; // координата точки, задающей положение размерной надписи

par.sPar.y2 = 1; // полка выше линии выноски

reference p = OrdinatedDimension(&par); // создание размера высоты

memset(&par, 0, sizeof(par));

GetObjParam(p, &par, sizeof(par), ALLPARAM); // получить параметры размера

par.sPar.y2 = -1; // полка ниже лини выноски

SetObjParam(p, &par, sizeof(par), ALLPARAM); // сохранить параметры размера
