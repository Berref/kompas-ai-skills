# MarkerLeader - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void MarkerLeader_Example (void) {

reference p;

MarkerLeaderParam leaderPar;

memset(&leaderPar, 0, sizeof(BrandLeaderParam));

leaderPar.cText0 = 1; // число строк в знаке

leaderPar.cText1 = 1; // число строк над ножкой

leaderPar.cText2 = 1; // число строк под ножкой

leaderPar.x=50; leaderPar.y=50; // начало полки

leaderPar.arrowType = 2; // тип стрелки

leaderPar.pText = CreateArray(CHAR_STR_ARR,0);

AddArrayItem(leaderPar.pText, -1, п.11, 5);

AddArrayItem(leaderPar.pText, -1, Ну, 3);

AddArrayItem(leaderPar.pText, -1, Ту, 3);

leaderPar.pPolyline =CreateArray(POLYLINE_ARR,0);

reference pPoly = CreateArray(POINT_ARR , 0);

MathPointParam mPar;

mPar.x = 10; mPar.y = 10;

AddArrayItem(pPoly , -1, &mPar, sizeof(mPar));

AddArrayItem(leaderPar.pPolyline , -1, &pPoly, sizeof(pPoly));

mPar.x = 30; mPar.y = 10;

ClearArray(pPoly);

AddArrayItem(pPoly , -1, &mPar, sizeof(mPar));

AddArrayItem(leaderPar.pPolyline , -1, &pPoly, sizeof(pPoly));

p = MarkerLeader(&leaderPar);

}; /* MarkerLeader_Example */
