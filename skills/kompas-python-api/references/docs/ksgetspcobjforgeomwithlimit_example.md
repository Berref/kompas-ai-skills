# ksGetSpcObjForGeomWithLimit - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset (&info, 0, sizeof(info));

info.prompt = "Укажите макроэлемент болт";

reference g;

int j = Cursor (&info, &x ,&y, 0);

if (j)

{

if (ExistObj(pObj = FindObj(x, y, 1e6)) && GetObjParam(pObj, 0, 0, 0) == MACRO_OBJ )

{

//найдем объект спецификации по заданной геометрии

reference spcObj = ::ksGetSpcObjForGeomWithLimit ("graphic.lyt", //имя

//библиотеки стилей

1, //номер

//стиля спецификации

pObj ,

0, //присланная

//геометрия входит

// в объект спецификации

1, //-первый объект

25, //номер раздела

313277777065.0);

if (spcObj)

{

char buf[TEXT_LENGTH];

//получим наименование объекта спецификации

ksGetSpcObjectColumnText (spcObj, //объект спецификации

SPC_CLM_NAME , //тип колонки

1, //номер колонки данного типа

1, //номер блока

buf, //указатель

TEXT_LENGTH); //длина строки s

Message(buf);

}

else

Error("Это не объект спецификации Болт");

}

else

Error("Это не макроэлемент");

}
