# ksPrintPreviewWindow - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char buf[128];

//создать динамический массив строк

reference docsArr = CreateArray(CHAR_STR_ARR,0);

//наполним массив

strcpy(buf,"d:\\\0\\\\_222.cdw");

AddArrayItem(docsArr, -1, buf, sizeof(buf));

strcpy(buf,"d:\\\0\\\\_2.cdw");

AddArrayItem(docsArr, -1, buf, sizeof(buf));

//в просмотровом окне должно появиться два документа, которые нужно распечатать

if (! ksPrintPreviewWindow(docsArr, // динамический массив указателей CHAR_STR_ARR

1)) { // 1 - если docsArr = 0 или массив пуст,

// запросить документы у пользователя

// 0 - без запроса

// если неудачное завершение - выдадим результат работы нашей функции

MessageBoxResult();
