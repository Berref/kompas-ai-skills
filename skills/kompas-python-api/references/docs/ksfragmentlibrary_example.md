# ksFragmentLibrary - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char libName[250];

int j1;

//выберем библиотеку фрагментов

if (ChoiceFile ("*.lfr","Библиотеки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|", libName, 128))

{

char buf[250];

do

{

//выбрать фрагмент в библиотеке фрагментов

if ((j1 = ksChoiceFragmentFromLib(libName, buf, 250))!=0)

{

//выделим имя вставки

char * insertName = strrchr (buf, '|');

if (insertName)

{

double x, y;

//подготовим структуры фантома и запросов для Placement

struct Phantom rub;

rub.type1.xBase = 0;

rub.type1.yBase = 0;

rub.type1.scale = 1;

rub.phType = 1;

reference pDefFrg;

// создадим описание вставки фрагментов

pDefFrg = FragmentDefinition (buf, //имя файла фрагмента

insertName1, //имя вставки

1); // внешней ссылкой

if (pDefFrg)

{

//во временную группу положим вставку фрагмента,

//взятую из библиотеки фрагментов

rub.type1.gr = NewGroup (1); // временная группа

PlacementParam par;

par.xBase = 0;

par.yBase = 0;

par.ang = 0;

par.scale = 1 ;

//создаем объект "вставка фрагмента"

reference p = InsertFragment (pDefFrg, // указатель определения

//фрагмента

0, //на свои слои

&par); //параметры привязки

EndGroup();

int j;

do

{

rub.type1.ang = 0;

//запрос точки и угла поворота фрагмента

if ((j = Placement(NULL, &x, &y, &rub.type1.ang, &rub))!=0)

{

CopyObj (p, // указатель на графический объект

0,0, // базовая точка объекта

x, y, //точка, куда копировать

1, // масштаб

rub.type1.ang);// угол поворота а градусах

}

}

while (j);

DeleteObj (rub.type1.gr);

}

else

Error ("Ошибка создания описания вставки фрагмента");

}

else

Error("Имя вставки не определено");

}

}

while (j1);

}
