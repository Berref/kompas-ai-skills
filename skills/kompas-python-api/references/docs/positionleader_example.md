# PositionLeader - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void PositionLeader_Example (void) {

reference p;

PosLeaderParam leaderPar;

memset(&leaderPar, 0, sizeof(PosLeaderParam));

leaderPar.x=50; leaderPar.y=50; // начало полки

leaderPar.arrowType = 1; // тип стрелки

leaderPar.dirX=-1; // полка влево)

leaderPar.pText = CreateArray(CHAR_STR_ARR,0);

AddArrayItem(leaderPar.pText, -1, 11, 3);

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

p = PositionLeader(&leaderPar);

}; /* PositionLeader_Example */
