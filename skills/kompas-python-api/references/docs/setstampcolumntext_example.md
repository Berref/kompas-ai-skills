# SetStampColumnText, GetStampColumnText пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
if (OpenStamp())

{

unsigned int numb;

reference p;

//в цикле будем брать все существующие графы

while ((p=GetStampColumnText (&numb))!=0)

{

// p - текст текущей графы

char buf[128];

sprintf (buf, "numb =%d ", numb);

Message(buf);

TextLineParam parLine;

for (int i=0, count = GetArrayCount(p); i < count; i++)

{

//берем текущую строку графы

GetArrayItem (p , i, &parLine, sizeof(TextLineParam));

sprintf (buf, "i =%d style=%d ", i, parLine.style);

Message(buf);

TextItemParam parItem;

for (int j=0, count1 = GetArrayCount(parLine.pTextItem); j < count1; j++)

{

//берем текущую компоненту строки

GetArrayItem (parLine.pTextItem, j,

&parItem, sizeof (TextItemParam));

sprintf (buf, "компонента=%d h=%5.1f\ns=%s\n fontName=%s ",j,

parItem.font.height,parItem.s, parItem.font.fontName);

strcat (parItem.s, "!!!");

//меняем текущую компоненту строки

SetArrayItem (parLine.pTextItem, j, &parItem, sizeof (TextItemParam));

Message(buf);

}

DeleteArray (parLine.pTextItem); //очистим массив компонент

}

//меняем текущую строку в массиве

SetArrayItem (p , i, &parLine, sizeof(TextLineParam));

//меняем текущую графу

SetStampColumnText (numb, p);

//очистим массив текстовых строк

DeleteArray (p);

}

CloseStamp();

}

else

Error ("Штамп не найден");
