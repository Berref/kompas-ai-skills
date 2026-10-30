# ksCentreMarker - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
CentreParam cPar; // структура параметров объекта "обозначение центра"

::memset(&cPar, 0, sizeof(cPar));

cPar.x = 50; // точка привязки

cPar.y = 50;

cPar.type = 2; // тип обозначения центра - две оси

cPar.lenXpTail = 40; // длина "хвостиков"

cPar.lenXmTail = 60;

cPar.lenYpTail = 20;

cPar.lenYmTail = 45;

::ksCentreMarker(&cPar); // создать объект "обозначение центра"
