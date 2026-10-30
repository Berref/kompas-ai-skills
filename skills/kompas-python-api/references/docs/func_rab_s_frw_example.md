# Пример использования функций работы с фрагментами

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ReadFragment_Example (void) {

PlacementParam par;

par.xBase = 30; par.yBase = 40;

par.ang = 0; par.scale = 1 ;

ReadFragment("c:\\\kompas5\\\1.frw", 0, &par);

//Пример вставки фрагмента внешней ссылкой

//определим фрагмент для вставки

pDefFrg = FragmentDefinition("c:\\\kompas5\\\1.frw", "frw1", 1);

if(pDefFrg) {

PlacementParam par;

par.xBase = 80; par.yBase = 70;

par.ang = 45; par.scale = 2 ;

reference pInsFrg = InsertFragment(pDefFrg, 0, &par);

LightObj (pInsFrg, 1);

Message("вставка фрагмента внешней ссылкой");

LightObj (pInsFrg, 0);

}

// Пример вставки локального фрагмента

// определим фрагмент для вставки

reference pDefFrg = 0;

//определим локальный фрагмент

if(LocalFragmentDefinition("local")) {

LineSeg(0, 0, 10, 0, 1);

LineSeg(0, 0, 0, 10, 1);

ArcByPoint(0, 0, 10, 10, 0, 0,10, -1, 1);

pDefFrg = CloseLocalFragmentDefinition();

}

if(pDefFrg) {

PlacementParam par;

par.xBase = 100; par.yBase = 40;

par.ang = 45; par.scale = 1 ;

reference p = InsertFragment(pDefFrg, 0, &par);

LightObj (p, 1);

Message("вставка локального фрагмента");

LightObj (p, 0);

}

}; /* ReadFragment */
