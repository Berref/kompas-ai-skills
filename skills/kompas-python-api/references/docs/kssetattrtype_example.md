# ksSetAttrType - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double numb;

int j;

char nameFile[128];

char password[11];

ksAttributeType attrType;

attrType.columns = CreateArray (ATTR_COLUMN_ARR, 0);

//поменяем местами первую колонку и последнюю

ColumnInfo par1; //структура для первой колонки

par1.columns = CreateArray (ATTR_COLUMN_ARR,0);

par1.fieldEnum = CreateArray (CHAR_STR_ARR,0);

ColumnInfo parN; //структура для последней колонки

parN.columns = CreateArray (ATTR_COLUMN_ARR,0);

parN.fieldEnum = CreateArray (CHAR_STR_ARR,0);

//запросить имя библиотеки

if (!ChoiceFile("*.lat",NULL, nameFile,128))

nameFile[0]='\0'; //будем искать в документе

do

{

j = ReadDouble ("Ввести номер типа атрибута", 1000, 0, 1e12,&numb);

if (j)

{

j = ReadString ("Ввести пароль типа атрибута", password, 10);

if (j)

{

//считаем тип атрибута

if (!ksGetAttrType(numb, nameFile, &attrType))

MessageBoxResult(); // проверяем результат работы

//нашей функции

else

{

strcpy (attrType.password,password);

// число колонок

int n = GetArrayCount (attrType.columns);

//считаем первую колонку

GetArrayItem (attrType.columns, 0, &par1, sizeof (par1));

//считаем последнюю колонку

GetArrayItem(attrType.columns, n-1, &parN, sizeof (parN));

//заменим первую колонку

SetArrayItem (attrType.columns, 0, &parN, sizeof (parN));

//заменим последнюю колонку

SetArrayItem (attrType.columns, n-1, &par1, sizeof (par1));

//заменим тип атрибута на новый

double numbType = ksSetAttrType (numb, nameFile,

&attrType, password);

if (numbType > 1)

{

char buf[128];

sprintf (buf, "numbType=%f ",numbType);

Message (buf);

}

else

MessageBoxResult(); // неудачное завершение -

// выдадим результат работы нашей функции

}

}

}

}

while(j);

//удалим все созданные массивы

DeleteArray (par1.columns);

DeleteArray (par1.fieldEnum);

DeleteArray(parN.columns);

DeleteArray(parN.fieldEnum);

DeleteArray(attrType.columns);
