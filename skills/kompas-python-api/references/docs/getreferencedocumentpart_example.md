# GetReferenceDocumentPart пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
if (ksGetCurrentDocument (1)) // документ должен быть графическим

{

//получим указатель на технические требования

reference pTT = GetReferenceDocumentPart (1);

if (pTT)

{

TechnicalDemandParam par;

//получим параметры описания ТТ

GetObjParam (pTT, &par, sizeof (par), TECHNICAL_DEMAND_PAR);

char buf[128];

sprintf (buf, "число строк TT =%d",par.strCount);

Message (buf);

//открываем ТТ на редактирование

//(ТТ должны быть открыты, чтобы менять тексты)

OpenTechnicalDemand (par.pGab, //динамический массив

// листов технических требований или 0

par.style); //стиль текста для технических требований

// (если 0 - умолчательное значение)

//пройдемся по ТТ и получим текст

TextLineParam parLine;

for (int i = 0; i < par.strCount; i++)

{

//берем текущую строку

GetObjParam (pTT, &parLine,

sizeof (TextLineParam),

TT_FIRST_STR+i);

TextItemParam parItem;

for (int j=0, count1 = GetArrayCount(parLine.pTextItem); j < count1; j++)

{

//берем текущий компонент строки

GetArrayItem (parLine.pTextItem,

j, &parItem,

sizeof (TextItemParam));

strcat (parItem.s, "!!!");

//меняем текущий компонент строки

SetArrayItem (parLine.pTextItem,

j, &parItem,

sizeof (TextItemParam));

Message (parItem.s);

}

//меняем текущую строку

SetObjParam (pTT, &parLine,

sizeof (TextLineParam),

TT_FIRST_STR+i);

}

//закрываем ТТ

CloseTechnicalDemand ();

return;

}

}

Error ("Документ должен быть листом");
