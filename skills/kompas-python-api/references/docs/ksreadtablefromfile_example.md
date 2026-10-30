# ksReadTableFromFile - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char tabName[250];

int j1;

do {

//выберем файл таблицы

if((j1 = ksChoiceFile("*.tbl","таблицы(*.tbl)|*.tbl|Все файлы (*.*)|*.*|", tabName, 250, 0)) != 0){

double x, y;

//подготовим структуры фантома и запросов для Placement

struct Phantom rub;

rub.type1.xBase = 0;

rub.type1.yBase = 0;

rub.type1.scale = 1;

rub.phType = 1;

//во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов

PlacementParam par;

par.xBase = 0;

par.yBase = 0;

par.ang = 0;

par.scale = 1 ;

//создаем временную группу

rub.type1.gr = NewGroup (1);

reference pTab = ksReadTableFromFile(tabName); //полное имя к файлу таблицы

EndGroup();

if (pTab && Cursor(NULL, &x, &y, &rub)) {

//сдвигаем группу

MoveObj(rub.type1.gr, x, y);

//ставим группу в модель

StoreTmpGroup(rub.type1.gr);

ClearGroup(rub.type1.gr);

DeleteObj(rub.type1.gr);

}

else {

if (pTab)

Error("Ошибка при считывании таблицы");

DeleteObj(rub.type1.gr);

}

}

} while(j1);
