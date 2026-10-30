# ksSpcObjectCreate - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
а)

#define SPC_NAME 5 //наименование

//-----------------------------------------------------------------------------------------------

// создадим объект спецификации для раздела "Детали"

//-----------------------------------------------------------------------------------------------

reference EditSpcObj(reference geom){

reference spcObj = 0;

//если редактируем макроэлемент, то войдем в режим редактирования объекта

if (::EditMacroMode()) {

//найдем объект спецификации по геометрии

spcObj = ::ksGetSpcObjForGeom("graphic.lyt" , //имя библиотеки типов

1, // номер типа спецификации

0, //для макроредактирования

1, 1);

//войдем в режим редактирования

if (!::ksSpcObjectEdit(spcObj))

spcObj = 0;

}

//если объекта нет, войдем в режим создания объекта спецификации

if(spcObj || ::ksSpcObjectCreate("graphic.lyt", //имя библиотеки типов

1, // номер типа спецификации

20, 0, //номер раздела и подраздела

0,0)) { //тип атрибута

//наименование

::ksSpcChangeValue(SPC_NAME/*номер колонки*/ , 1, "Втулка", STRING_ATTR_TYPE );

//подключим геометрию

if (geom)

::ksSpcIncludeReference(geom, 1);

spcObj = ::ksSpcObjectEnd();

//если объект спецификации создан, дадим возможность пользователю на него посмотреть и отредактировать. Функцию нужно запускать вне Cursor и Placement

if (spcObj)

if (::ksEditWindowSpcObject(spcObj))

return spcObj;

}

return 0;

}

б)

Для стандартных изделий в стиле спецификации (см. "graphic.lyt") колонка "Наименование" имеет тип значения "запись". Это значит, что наименование формируется по шаблону обозначения для данного стандартного изделия (например, болта). Шаблоны создаются на базе типов атрибутов и хранятся в библиотеке типов атрибутов, которая определена в стиле спецификации (например, "spc.lat").

При простановке болта из библиотеки из базы данных заполняется некоторая структура данных BOLT, которая несет информацию для построения геометрии болта и формирования обозначения.

struct BOLT {

float dr; /*диаметр резьбы*/

float p; /*шаг резьбы */

float s; /*размер под ключ*/

float h; /*высота головки */

float D; /* диаметр описанной окружности*/

float d3; /*диаметр отв. в стержне*/

float h2; /*высота подголовка*/

float L; /*длина стержня*/

float l1; /*расстояние до отверстия в стержне*/

float b; /*длина резьбовой части*/

float d2; /*диаметр под головкой*/

float z4; /*величина фаски конца*/

short k; // 1 - длина резьбы ниже ломаной (резьба только на b) ; 2 - выше ломаной (резьба до головки и на в)

unsigned short f; /*битовые маски*/

short klass; /*класс точности*/

unsigned short gost; /*номер госта*/

};

#define SPC_NAME 5 //наименование

//-----------------------------------------------------------------------------------------------

// создадим объект спецификации для раздела "Стандартные изделия"

//-----------------------------------------------------------------------------------------------

reference EditSpcObj (BOLT &tmp, reference geom) {

reference spcObj = 0;

//если редактируем макро объект , то войдем в режим редактирования объекта

if (::EditMacroMode()) {

//найдем объкт спецификации по геометрии

spcObj = ::ksGetSpcObjForGeom("graphic.lyt" , //имя библиотеки типов

1, // номер типа спецификации

0, //для макроредактирования

1, 1);

//войдем в режим редактирования

if (!::ksSpcObjectEdit(spcObj))

spcObj = 0;

}

if(spcObj || ksSpcObjectCreate("graphic.lyt" , //имя библиотеки типов

1, // номер типа спецификации

25, 0, //номер раздела и подраздела определены в стиле спецификации

308437807397.0 , 0)) //тип атрибута определен в библиотеке типов атрибутов spc.lat

uint uBuf;

//исполнение

if(!(tmp.f & ISPOLN)) //если исполнения нет

::ksSpcVisible(SPC_NAME, 2, 0); //выключим исполнение

else {

uBuf = (uint) 2;

::ksSpcVisible(SPC_NAME, 2, 1);

::ksSpcChangeValue(SPC_NAME , 2, &uBuf, UINT_ATTR_TYPE );

}

//изменим диаметр

uBuf = (uint) tmp.dr;

::ksSpcChangeValue(SPC_NAME , 4, &uBuf, UINT_ATTR_TYPE );

//отследим мелкий шаг

if(!(tmp.f & PITCH)){//выключить шаг и его разделитель

::ksSpcVisible(SPC_NAME, 5, 0);

::ksSpcVisible(SPC_NAME, 6, 0); //шаг

}

else {

::ksSpcVisible(SPC_NAME, 5, 1);

::ksSpcVisible(SPC_NAME, 6, 1); //шаг

::ksSpcChangeValue(SPC_NAME , 6, &tmp.p, FLOAT_ATTR_TYPE);

}

// выключим поле допуска

::ksSpcVisible(SPC_NAME, 7, 0);

//изменим длину

uBuf = (uint) tmp.L;

::ksSpcChangeValue(SPC_NAME , 9, &uBuf, UINT_ATTR_TYPE );

// выключим класс прочности

::ksSpcVisible(SPC_NAME, 10, 0);

// выключим материал

::ksSpcVisible(SPC_NAME, 11, 0);

// выключим покрытие

::ksSpcVisible(SPC_NAME, 12, 0);

//изменим ГОСТ

uBuf = (uint) tmp.gost;

::ksSpcChangeValue(SPC_NAME , 14, &uBuf, UINT_ATTR_TYPE );

//подключим геометрию

if (geom)

::ksSpcIncludeReference(geom, 1);

spcObj = ::ksSpcObjectEnd();

//если объект спецификации создан, дадим возможность пользователю на него посмотреть и отредактировать. Функцию нужно запускать вне Cursor и Placement

if (spcObj)

if (::ksEditWindowSpcObject(spcObj))

return spcObj;

}

return 0;

}

в) пример создания шаблона обозначения для стандартного изделия "болт":

Шаблон обозначения можно создать визуальными средствами, предоставленными КОМПАС-ГРАФИК для создания типа атрибута. Этот способ не требует непосредственного программирования, но приводит к затратам времени на создание шаблона, а при потере данных в библиотеке требует повторного создания утраченного шаблона.

Можно создать шаблон обозначения средствами apptool из библиотеки.

Полное обозначение болта :

Болт 1 М12 х 1.25 -6g x 60.58.35X.16 ГОСТ 7808 - 70

Представим это обозначение в виде компонент :

Номер Имя компоненты Умолчательное значение Тип Очередность сортировки

1 Имя элем. Болт строка 1

2 Исполнение 1 uint 3

3 Резьба М строка 0 (не сортируется)

4 Диаметр 12 uint 4 или 3 (сортирует подряд)

5 Разделитель х строка 0 (не сортируется)

6 Шаг 1.25 float 5 или 3 (сортирует подряд)

7 Поле допуска -6g строка 6 или 3 (сортирует подряд)

8 Разделитель х строка 0 (не сортируется)

9 Длина 60 uint 7 или 3 (сортирует подряд)

10 Кл. прочности .58 строка 0 (не сортируется)

11 Материал .35Х строка 0 (не сортируется)

12 Покрытие .16 строка 0 (не сортируется)

13 ГОСТ ГОСТ строка 0 (не сортируется)

14 Номер 7808 uint 2

15 Разделитель - строка 0 (не сортируется)

16 Год 70 строка 0 (не сортируется)

//ключи определены в стиле спецификации

#define ST_KEY1 100 //ключи для стандапртных изделий

#define ST_KEY2_GOST 5 //для стандартных изделий

#define ST_KEY3 1

#define ATTR_TYPE_LIB_NAME_KEY3 "d:\\\gr\\\spc.lat" имя библиотеки типов атрибутов

//-------------------------------------------------------------------------

// создадим тип атрибута болта

//-------------------------------------------------------------------------

void TypeAttrBolt() {

//Инициализация данных для создания шаблона

//заполним структуру типа атрибута

ksAttributeType attrType;

strcpy(attrType.header,"Болт"); // заголовoк-комментарий типа

attrType.rowsCount = 1; // кол-во строк в таблице

attrType.flagVisible = 1; // видимый, невидимый в таблице

strcpy(attrType.password,""); // пароль, если не пустая строка - защищает от несанкционированного изменения типа

attrType.columns = CreateArray(ATTR_COLUMN_ARR,0); // динамический массив компонент записи

attrType.key1 = ST_KEY1;

attrType.key2 = ST_KEY2_GOST;

attrType.key3 = ST_KEY3;

attrType.key4 = 0;

ColumnInfo parStruct1;

//массив полей записи

// колонка 1 "Имя элем."

strcpy(parStruct1.header, "Имя элем.");// заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже

parStruct1.key = 1; // дополнительный признак, очередность сортировки

strcpy(parStruct1.def,"Болт"); // значение по умолчанию

parStruct1.flagEnum =0; // флаг, включающий режим, когда значение поля атрибута будет заполняться из массива перечисленных значений (1-режим включен, 0-отключен

parStruct1.fieldEnum = 0; // массив неопределенной длины перечислений (строки)

parStruct1.columns = 0; // массив неопределенной длины информации о колонках для записи

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 2 "Исполнение"

strcpy(parStruct1.header, "Исполнение"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // дополнительный признак, очередность сортировки

strcpy(parStruct1.def,"1"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 3 "Резьба"

strcpy(parStruct1.header, "Резьба"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"М"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 4 "Диаметр"

strcpy(parStruct1.header, "Диаметр"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"12"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 5 "разделитель"

strcpy(parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 6 "Шаг"

strcpy(parStruct1.header, "Шаг"); // заголовoк-комментарий столбца

parStruct1.type = FLOAT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"1.25"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 7 "Поле допуска"

strcpy(parStruct1.header, "Поле допуска"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"-6g"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 8 "разделитель" strcpy(parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 9 "Длина"

strcpy(parStruct1.header, "Длина"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 3; // очередность сортировки

strcpy(parStruct1.def,"60"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 10 "Кл. прочности"

strcpy(parStruct1.header, "Кл. прочности"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,".58"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 11 "Материал"

strcpy(parStruct1.header, "Материал"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,".35Х"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 12 "Покрытие"

strcpy(parStruct1.header, "Покрытие"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,".16"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 13 "ГОСТ"

strcpy(parStruct1.header, "ГОСТ"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"ГОСТ"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 14 "Номер"

strcpy(parStruct1.header, "Номер"); // заголовoк-комментарий столбца

parStruct1.type = UINT_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 2; // очередность сортировки

strcpy(parStruct1.def,"7808"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 15 "разделитель"

strcpy(parStruct1.header, ""); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"-"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// колонка 16 "Год"

strcpy(parStruct1.header, "Год"); // заголовoк-комментарий столбца

parStruct1.type = STRING_ATTR_TYPE; // тип данных в столбце - см. "ltdefine.h"

parStruct1.key = 0; // очередность сортировки

strcpy(parStruct1.def,"70"); // значение по умолчанию

//добавим компоненту в массив компонент

AddArrayItem(attrType.columns, -1, &parStruct1, sizeof(parStruct1));

// создать шаблон обозначения

/*double numbType =*/ ksCreateAttrType(&attrType, // информация о типе атрибута

ATTR_TYPE_LIB_NAME_KEY3); // имя библиотеки типов атрибутов

MessageBoxResult(); // проверяем результат работы нашей функции

//удалим массив колонок

DeleteArray(attrType.columns);

}

г) пример простановки линии-выноски к объекту спецификации :

//фрагмент ресурса

STRINGTABLE {

STR225 "Линию-выноску проставлять?"

STR226 "Укажите позиционную линию-выноску"

STR227 "!Создать новую линию-выноску !Подключить существующую"

STR228 "Ошибка! Объект - не позиционная линия-выноска!"

}

MENU_POS_LEADER MENU

{

MENUITEM "Подключить существующую", 2

MENUITEM "Создать новую линию-выноску ", 1

}

extern TModule *module;

//----------------------------------------------------------------------------------------------

// Отрисовать позиционную линию-выноску

// Уже проверено , что объект спецификации есть

// Функцию нужно запускать вне Cursor и Placement

//----------------------------------------------------------------------------------------------

void DrawPosLeader(reference _spcObj) {

RequestInfo info;

bool flag = false;

reference posLeater = 0;

double x1, y1;

char buf[128];

do {

memset(&info, 0, sizeof(info));

info.commands = (char*)MENU_POS_LEADER;

module->LoadString(STR226, buf, 128); //"Укажите позиционную линию-выноску"

info.prompt = buf;

int j1 = Cursor(&info, &x1, &y1, 0);

switch (j1) {

case 1: //Создать новую линию-выноску

posLeater = ::ksCreateViewObject(POSLEADER_OBJ);

flag = false;

break;

case 2: //Подключить существующую

module->LoadString(STR226, buf, 128); //"Укажите линию-выноску."

memset(&info, 0, sizeof(info));

info.commands = buf;

if(Cursor(&info, &x1, &y1, 0)) {

posLeater = ::FindObj(x1, y1, 100); // величина стороны окошка-ловушки с центром x,y

if (!(posLeater && ::GetObjParam(posLeater, 0, 0, 0) == POSLEADER_OBJ)) {

module->LoadString(STR228, buf, 128); //"Ошибка! Объект-не позиционная линия-выноска!"

Error(buf);

posLeater = 0;

flag = true;

}

else

flag = false;

break;

}

else

flag = false;

break;

case -1:

posLeater = ::FindObj(x1, y1, 100); // величина стороны окошка-ловушки с центром x,y

if (!(posLeater && ::GetObjParam(posLeater, 0, 0, 0) == POSLEADER_OBJ)) {

module->LoadString(STR228, buf, 128); //"Ошибка! Объект-не позиционная линия-выноска!"

Error(buf);

posLeater = 0;

flag = true;

}

else

flag = false;

break;

}

} while(flag);

//линия-выноска есть, подключим ее к объекту спецификации

if (posLeater ) {

//войдем в режим редактирования объекта спецификации

if (::ksSpcObjectEdit(_spcObj)) {

//подключим линию-выноску

::ksSpcIncludeReference(posLeater, true);

//закроем объект спецификации

::ksSpcObjectEnd();

}

}

}
