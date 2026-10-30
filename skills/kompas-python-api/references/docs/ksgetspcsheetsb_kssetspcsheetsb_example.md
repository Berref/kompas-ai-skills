# ksGetSpcSheetSB, ksSetSpcSheetSB - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//откроем спецификацию

reference pDoc = OpenDocument ("d:\\\0\\\4.spw", 0);

if (pDoc)

{

//заполним массив листов сборки, которые нужно подключить к спецификации

reference arr = CreateArray(CHAR_STR_ARR, 0);

char buf [255];

strcpy (buf, "d:\\\0\\\1.cdw");

AddArrayItem (arr, -1, buf, strlen(buf)1);

strcpy (buf, "d:\\\0\\\2.cdw");

AddArrayItem (arr, -1, buf, strlen(buf)1);

//подключим листы сборочного чертежа к спецификации

ksSetSpcSheetSB (pDoc, arr);

DeleteArray (arr);

//просмотрим листы сборки, подключенные к спецификации

reference p = ksGetSpcSheetSB (pDoc);

if (p)

{

for (uint i=0, count = GetArrayCount( p); i < count; i)

{

char buf1[255];

GetArrayItem(p, i, buf1, 255);

Message(buf1);

}

}

SaveDocument(pDoc, 0);

CloseDocument(pDoc);

}
