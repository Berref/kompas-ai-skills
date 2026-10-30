# CreateSpcIterator, ksGetSpcObjectColumnText, ksSetSpcObjectColumnText - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference spcObj = 0;

double numbObj; //уникальный номер объекта

//создадим объект спецификации

if( ::ksSpcObjectCreate("graphic.lyt", //имя библиотеки типов

1, // номер типа спецификации

20, 0, //номер раздела и подраздела

0, //тип атрибута

0)) { //базовый объект

spcObj = ::ksSpcObjectEnd();

//запомним номер объекта

numbObj = ::ksGetSpcObjectNumber ( spcObj);

}

//создадим итератор для навигации по объектам спецификации

reference iter = ::CreateSpcIterator("graphic.lyt", 1, 0);

if (!iter)

::MessageBoxResult(); // неудачное завершение - выдадим результат работы нашей функции

else {

reference spcObj;

char buf[120];

// найдем первый объект

spcObj = ::MoveIterator(iter, 'F');

if (spcObj && ::ExistObj(spcObj)) {

//у всех объектов в обозначении добавим "-01"

//а у объекта с номером numbObj - "-02"

do {

//возьмем текст обозначения

::ksGetSpcObjectColumnText (spcObj

SPC_CLM_MARK, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER

1, //номер колонки данного типа начиная с 1

buf, 120); //указатель

double n = ::ksGetSpcObjectNumber (spcObj);

//добавим к обозначению нужную добавку

strcat(buf, n == numbObj ? "-02" : "-01");

//откроем объект на редактирование

::ksSpcObjectEdit(spcObj);

//в этом блоке можно редактировать все колонки спецификации,

//подключать или отключать ассоциированную геометрию

//в нашем случае заменим обозначение

::kSetSpcObjectColumnText (SPC_CLM_MARK, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER

1, //номер колонки данного типа начиная с 1

buf); //указатель

//закроем объет после редактирования

::ksSpcObjectEnd();

//найдем следующий объект

spcObj = ::MoveIterator(iter, 'N');

} while(spcObj && ::ExistObj(spcObj));

}

//удалим итератор

::DeleteIterator(iter);

}

}
