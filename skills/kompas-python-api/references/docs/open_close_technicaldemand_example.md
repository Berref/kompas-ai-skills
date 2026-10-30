# Пример задания технических требований

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void TechnicalDemand_Example (void) {

reference p;

reference pGab = CreateArray(RECT_ARR,0) ;

RectParam par;

par.pTop.x= 230; par.pTop.y = 80;

par.pBot.x= 415; par.pBot.y = 65;

AddArrayItem(pGab,-1, &par, sizeof(RectParam));

par.pTop.x= 45; par.pTop.y = 30;

par.pBot.x= 230; par.pBot.y = 15;

AddArrayItem(pGab,-1, &par, sizeof(RectParam));

// размещение на 2 страницах

reference tDem;

if(OpenTechnicalDemand( pGab)) {

TextLine (NEW_LINE ,0,0 ,1111111);

TextLine (NEW_LINE ,0,0 ,222222);

TextLine (NEW_LINE ,0,0 ,3333333);

TextLine (NEW_LINE ,0,0 ,4444444);

TextLine (NEW_LINE ,0,0 ,5555555);

TextLine (NEW_LINE ,0,0 ,6666666);

tDem =CloseTechnicalDemand();

}

DeleteArray(pGab);

// размещение на 1 странице

if(OpenTechnicalDemand( 0)) {

TextLine (NEW_LINE ,0,0 ,1111111);

TextLine (NEW_LINE ,0,0 ,222222);

TextLine (NEW_LINE ,0,0 ,3333333);

TextLine (NEW_LINE ,0,0 ,4444444);

TextLine (NEW_LINE ,0,0 ,5555555);

TextLine (NEW_LINE ,0,0 ,6666666);

CloseTechnicalDemand();

}

}; /* TechnicalDemand_Example */
