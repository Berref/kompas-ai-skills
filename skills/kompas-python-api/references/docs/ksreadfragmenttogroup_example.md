# ksReadFragmentToGroup, ksChoiceFile - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char frwName[250];

int j1;

do

{

//выберем фрагмент

if ((j1 = ksChoiceFile ("*.frw","фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|",

frwName,128,1))!=0)

{

double x, y;

//подготовим структуры фантома и запросов для Placement

struct Phantom rub;

rub.type1.xBase = 0;

rub.type1.yBase = 0;

rub.type1.scale = 1;

rub.phType = 1;

//во временную группу положим вставку фрагмента,

//взятую из библиотеки фрагментов

PlacementParam par;

par.xBase = 0;

par.yBase = 0;

par.ang = 0;

par.scale = 1 ;

int j;

do

{

//если нужно вставить несколько фрагментов,

//группу лучше порождать новую,

//так как вместе с геометрией могут прийти атрибуты,

//объекты спецификации, стили, которые связаны с геометрией.

//При простом копировании группы эта связь будет потеряна.

rub.type1.gr = ksReadFragmentToGroup (frwName, // имя фрагмента

0, // на свои слои,

&par); //параметры привязки

if (rub.type1.gr && (j = Placement(NULL, &x, &y, &rub.type1.ang, &rub))!=0)

{

//сдвигаем группу

MoveObj(rub.type1.gr, x, y);

//поворачиваем группу

if (fabs(rub.type1.ang) > 0.001)

RotateObj (rub.type1.gr, x, y, rub.type1.ang);

//ставим группу в модель

StoreTmpGroup (rub.type1.gr);

ClearGroup (rub.type1.gr);

DeleteObj (rub.type1.gr);

}

else

{

if (rub.type1.gr)

DeleteObj(rub.type1.gr);

j = 0;

}

}

while (j);

}

}

while(j1);
