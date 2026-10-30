# DeleteAttr - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
{

// создадим атрибут для типа атрибута с колонками

// DOUBLE_ATTR_TYPE, STRING_ATTR_TYPE, LINT_ATTR_TYPE

// Предполагается, что данный тип уже существует

Attribute attrPar;

//структура данных для оформления атрибута

struct {

double a;

char c[MAX_TEXT_LENGTH];

long b;

} bufS;

// заполним поля атрибута

bufS.a = 987654321.0;

bufS.b = 99999l;

strcpy(bufS.c,"Исполнение 1");

//заполним параметры структуры атрибута

strcpy(attrPar.comment,"элемент"); //комментарий атрибута

attrPar.key1 = 1; // рекоменд. как код разработчика

attrPar.key2 = 10; // рекоменд. как код атрибута

attrPar.key3 = 100; // рекоменд. как код разработчика

attrPar.key4 = 0; // системный код атрибута

// значения от 0 до 1000 зарезервированы АСКОН

attrPar.flagVisible = 0; //массив, определяющий для каждой колонки

// атрибут видимость-невидимость

// 0 -видимое поле 1- невидимое поле

attrPar.values = &bufS; // массив значений ячеек таблицы атрибутов

// сначала все значения для 1-ой строки,

// затем все значения для 2-ой строки и т.д.

attrPar.valSize = sizeof(bufS);

strcpy(attrPar.password,"111"); //пароль

double x, y;

reference pObj;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.promt = " Укажите объект ";

int j = Cursor(&info, &x, &y, 0, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

LightObj(pObj, 1);

//запросить имя библиотеки

char nameFile[128];

if(!ChoiceFile("*.tip",NULL, nameFile))

nameFile[0]='\0'; //будем искать в документе

double numb;

j = ReadDouble("Ввести номер типа атрибута", 1000.,0, 1e12,&numb);

if(j) {

reference attr= CreateAttr(pObj, &attrPar, numb, nameFile);

if (!attr) MessageBoxResult(); // неудачное завершение

}

LightObj(pObj, 0);

}

}

DeleteAttr (pObj, attr, «111»);

};
