# ksCreateAttrType - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//-------------------------------------------------------------------------

// создадим тип атрибута болта

//-------------------------------------------------------------------------

void TypeAttrBolt()

{

//Инициализация данных для создания шаблона

//заполним структуру типа атрибута

ksAttributeType attrType;

strcpy(attrType.header,"Болт"); // заголовoк-комментарий типа

attrType.rowsCount = 1; // кол-во строк в таблице

attrType.flagVisible = 1; // видимый, невидимый в таблице

strcpy (attrType.password,""); // пароль, если не пустая строка

//- защищает от несанкционированного изменения типа

attrType.columns = CreateArray (ATTR_COLUMN_ARR, 0); // динамический массив

//компонент записи

attrType.key1 = ST_KEY1;

attrType.key2 = ST_KEY2_GOST;

attrType.key3 = ST_KEY3;

attrType.key4 = 0;

ColumnInfo parStruct1;

//массив полей записи

// колонка 1 "Имя элем."

strcpy (parStruct1.header, "Имя элем."); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже

parStruct1.key = 1; // дополнительный признак, очередность сортировки

strcpy (parStruct1.def,"Болт"); // значение по умолчанию

parStruct1.flagEnum =0; // флаг, включающий режим,

// когда значение поля атрибута

// будет заполнятся из массива

// перечисленных значений 1 и 0 отключен

parStruct1.fieldEnum = 0; // массив неопределенной длины

//перечислений (строки)

parStruct1.columns = 0; // массив неопределенной длины

// информации о колонках для записи

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 2 "Исполнение"

strcpy(parStruct1.header, "Исполнение"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // дополнительный признак, очередность сортировки

strcpy (parStruct1.def,"1"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 3 "Резьба"

strcpy (parStruct1.header, "Резьба"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,"М"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 4 "Диаметр"

strcpy (parStruct1.header, "Диаметр"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy (parStruct1.def,"12"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 5 "разделитель"

strcpy (parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,"х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 6 "Шаг"

strcpy (parStruct1.header, "Шаг"); // заголовoк-комментарий столбца

parStruct1.type = FLOAT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"1.25"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 7 "Поле допуска"

strcpy (parStruct1.header, "Поле допуска"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy (parStruct1.def,"-6g"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 8 "разделитель"

strcpy (parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,"х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 9 "Длина"

strcpy (parStruct1.header, "Длина"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"60"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 10 "Кл. прочности"

strcpy (parStruct1.header, "Кл. прочности"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,".58"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 11 "Материал"

strcpy (parStruct1.header, "Материал"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,".35Х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 12 "Покрытие"

strcpy (parStruct1.header, "Покрытие"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,".16"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 13 "ГОСТ"

strcpy (parStruct1.header, "ГОСТ"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"ГОСТ"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 14 "Номер"

strcpy (parStruct1.header, "Номер"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 2; // очередность сортировки

strcpy (parStruct1.def,"7808"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 15 "разделитель"

strcpy (parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,"-"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof (parStruct1));

// колонка 16 "Год"

strcpy (parStruct1.header, "Год"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy (parStruct1.def,"70"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem (attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// создать шаблон обозначения

ksCreateAttrType (&attrType, // информация о типе атрибута

ATTR_TYPE_LIB_NAME_KEY3); // имя библиотеки типов атрибутов

MessageBoxResult(); // проверяем результат работы нашей функции

//удалим массив колонок

DeleteArray (attrType.columns);

}
