# GetAttrType - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

//создадим тип атрибута - строка

AttributeType attrType, NewAttrType; //структура типа атрибута

char nameFile[128];

reference pCol; //указатель на массив колонок

ColumnInfo parStruct; //структура для колонки

//создали массив колонок типа атрибута

pCol = CreateArray(ATTR_COLUMN_ARR,0);

//опишем единственную колонку типа STRING_ATTR_TYPE

strcpy(parStruct.header, "строка"); // заголовoк-комментарий столбца

parStruct.type = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже

// дополнительный признак, который позволит отличить две переменные с одинаковым типом

parStruct.key = 0;

strcpy(parStruct.def,"линия"); // значение по умолчанию

parStruct.flagEnum =0; // режим заполнения

parStruct.fieldEnum = 0; // массив неопределенной длины перечислений (строки)

parStruct.columns = 0; / массив неопределенной длины информации о колонках для записи

AddArrayItem(pCol, -1, &parStruct, sizeof(parStruct)); //добавили колонку

//заполним структуру типа атрибута

strcpy(attrType.header,"тип строка"); // заголовoк-комментарий типа

attrType.rowsCount = 1; // кол-во строк в таблице

attrType.flagVisible = 1; // видимый/невидимый

strcpy(attrType.password,""); // пароль

attrType.columns = pCol; // массив неопределенной длины информации о колонках

//запросить имя библиотеки

if(!ChoiceFile("lta", NULL, nameFile, 128))

nameFile[0]='\0'; //будем создавать в документе

//создать тип атрибута

double numbType = CreateAttrType(&attrType, // информация о типе атрибута

nameFile); // имя библиотеки типов атрибутов

if (numbType > 1) {

char buf[128];

sprintf(buf, "numbType=%f ",numbType);

Message(buf);

}

else MessageBoxResult(); // ошибка

GetAttrType(numbType, nameFile, &NewAttrType);

//удалим массив колонок

DeleteArray(pCol);

}
