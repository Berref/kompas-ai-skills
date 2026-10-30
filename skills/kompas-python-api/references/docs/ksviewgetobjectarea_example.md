# ksViewGetObjectArea - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//определим группу выделения

reference gr = ksViewGetObjectArea();

if (gr) {

//поставим временную группу в модель

StoreTmpGroup(gr);

//подсветим

LightObj(gr, 1);

Message("Область выделения");

//выключим подсветку

LightObj(gr, 0);

}

else

Message("Группы нет");
