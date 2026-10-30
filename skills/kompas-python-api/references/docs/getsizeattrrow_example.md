# GetSizeAttrRow - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void GetAttrvalue_Example (void) {

// если у объекта есть атрибут с ключом key1 = 100 и паролем "str",

// то заменим содержимое атрибута

double x, y;

reference pObj;

int j;

char buf[MAX_TEXT_LENGTH];

char s[MAX_TEXT_LENGTH];

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите объект";

j = Cursor(&info, &x, &y, 0, 0);

if (j) {

if (ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

LightObj(pObj, 1);

//создадим итератор для поиска по атрибутам объекта c ключами 1,10,100

reference iter = CreateAttrIterator(pObj, 0,0,0,0,0);

//встали на первый атрибут

reference attr = MoveAttrIterator(iter, 'F', 0);

if (attr) {

// получили данные для первой строки из таблицы атрибута

// если тип атрибута - STRING_ATTR_TYPE,то таблица атрибута будет состоять

// из 1 строки и 1 колонки, ячейка и строка в таблице атрибутов будет

// совпадать, поэтому в данном случае функции

// GetAttrRow и GetAttrValue будут работать одинаково

GetAttrRow (attr, 0, 0, &buf, sizeof(buf));

// GetSizeAttrRow и GetSizeAttrValue будут работать одинаково

int len1 = GetSizeAttrValue (attr, 0);

int count = 1; // количество колонок

int len2 = ksGetSizeAttrValue (attr, 0, &count );

int len3 = ksGetSizeAttrRow (attr, &count );

int rowsCount, columnsCount;

int GetAttrTabInfo ( pObj, &rowsCount, &columnsCount );

sprintf( s, "Количество колонок - %i", columnsCount );

Message( s );

sprintf( s, "Количество строк - %i", rowsCount );

Message( s );

sprintf(s, "содержимое атрибута - %s",buf);

Message(s);

strcpy(buf, "дуга");

// изменили содержимое строки в таблице атрибута

// функции SetAttrRow и SetAttrValue в данном случае будут работать одинаково

SetAttrRow(attr, 0, 0, &buf, sizeof(buf), "str");

}

else Message("атрибут не найден");

LightObj(pObj, 0);

}

}

}; /* GetAttrValue */
