# ksGetAttrType, ChoiceAttrTypes - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
static void ShowColumns (reference pCol, BOOL fl);

void ShowCol (ColumnInfo &par,int iCol, BOOL fl);

//--------------------------------------------------------------------------

// показать колонку

//--------------------------------------------------------------------------

void ShowCol (ColumnInfo &par,int iCol, BOOL fl)

{

char buf[128];

char s[10];

if (fl)

strcpy(s, "структура");

else

s[0]='\0';

//выдадим поля колонки не указатели

sprintf (buf,"%s i=%d header=%s type=%d def=%s flagEnum=%d",

s,iCol,par.header,

par.type, par.def, par.flagEnum);

Message(buf);

if (par.type == RECORD_ATTR_TYPE) //структура

ShowColumns(par.columns,TRUE);

else

{

if (par.flagEnum) //выдадим массив перечислений

{

int n1 = GetArrayCount (par.fieldEnum);

Message ("массив перечислений");

for (int i1=0; i1<n1; i1)

{

if (!GetArrayItem (par.fieldEnum, i1, &buf, sizeof(buf)))

MessageBoxResult(); // проверяем результат работы

// нашей функции

else

Message(buf);

}

}

}

}

//--------------------------------------------------------------------------

// показать колонки

//--------------------------------------------------------------------------

static void ShowColumns (reference pCol, BOOL fl)

{

ColumnInfo par;

par.columns = CreateArray (ATTR_COLUMN_ARR,0);

par.fieldEnum = CreateArray (CHAR_STR_ARR,0);

int n = GetArrayCount (pCol);

for (int i = 0; i < n; i)

{

if (!GetArrayItem(pCol, i, &par, sizeof(par)))

MessageBoxResult(); // проверяем результат работы нашей функции

else

ShowCol(par,i, fl);

}

DeleteArray (par.columns);

DeleteArray (par.fieldEnum);

}

//--------------------------------------------------------------------------

// получить тип атрибута

//--------------------------------------------------------------------------

void ShowTypeAttr ()

{

double numb;

char buf[128], nameFile[128];

ksAttributeType attrType;

attrType.columns = CreateArray (ATTR_COLUMN_ARR,0);

//запросить имя библиотеки

if (!ChoiceFile ("*.lat",NULL, nameFile,128))

nameFile[0]='\0'; //будем искать в документе

do

{

numb = ChoiceAttrTypes (nameFile);

if (numb)

{

if (!ksGetAttrType (numb, nameFile, &attrType))

MessageBoxResult(); // проверяем результат работы

// нашей функции

else

{

sprintf (buf,"key1 = %d key2 =%d key3 = %d key4 =&d",

attrType.key1,attrType.key2,attrType.key3,attrType.key4);

Message (buf);

sprintf (buf,"header=%s rowsCount=%d flagVisible=%d password=%s",

attrType.header,attrType.rowsCount,

attrType.flagVisible,attrType.password);

Message (buf);

ShowColumns (attrType.columns, FALSE); //пользовательская

// функция

}

}

}

while(numb);

//удалим массив колонок

DeleteArray(attrType.columns);

}
