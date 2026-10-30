# ksGetSpcTableColumn, ksGetSpcColumnType, ksGetSpcColumnNumb - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char spwName[250];

int j1;

//выберем спецификацию

if((j1 = ksChoiceFile("*.spw","спецификации(*.spw)|*.spw|Все файлы (*.*)|*.*|", spwName, 250, 1)) != 0){

//открыть документ

reference pDoc = OpenDocument (spwName, 0);

//создать итератор по объектам СП

reference iter = CreateSpcIterator(0, 0, 0);

//встаем на первый объект спецификации

reference spcObj = MoveIterator(iter, 'F');

if (spcObj && ExistObj(spcObj)) {

do {

//узнаем количество колонок у базового объекта спецификации

int count = ksGetSpcTableColumn(0, 0, 0);

// пройдем по всем колонкам

for (uint i = 1; i <= count; i) {

unsigned int columnType, typeNumb, block;

//для текущего номера определим тип колонки, номер исполнения и блок

if (ksGetSpcColumnType(spcObj, //объект спецификации

i, // номер колонки, начиная с 1

&columnType, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER

&typeNumb, //номер колонки данного типа

&block)) { //номер блока

char buf[250];

//возьмем текст

ksGetSpcObjectColumnText (spcObj, //объект спецификации

columnType, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER

typeNumb, //номер колонки данного типа

block,

buf, //указатель

250); //длина строки s

char buf1 [128];

sprintf (buf1, "\ntype = %d номер =%d block = %d", columnType,typeNumb,block);

strcat (buf, buf1);

Message(buf);

//по типу колонки, номеру исполнения и блоку определим номер колонки

int colNumb = ksGetSpcColumnNumb( spcObj, //объект спецификации

columnType, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER

typeNumb, //номер колонки данного типа начиная

block); //номер блока

sprintf (buf, "i = %d colNumb =%d", i, colNumb);

Message(buf);

}

}

//встаем на следующий объект спецификации

spcObj = MoveIterator(iter, 'N');

} while(spcObj && ExistObj(spcObj));

}

DeleteIterator(iter);

CloseDocument(pDoc);

}
