# ksAddFragmentToLibrary - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
char libName[250];

char buf [250];

//выберем библиотеку фрагментов

if (ChoiceFile("*.lfr","Библиотеки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|", libName, 128))

{

RequestInfo info;

memset(&info, 0, sizeof(info));

info.commands = "!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент ";

int j;

int typeEdit;

string nameFrg;

do

{

j = CommandWindow(&info);

switch (j)

{

case 1: //!Новый_фрагмент

if (ReadString("Введите имя нового фрагмента", // строка приглашения

buf, //возвращаемая строка

250)) // допустимая длина

// строки

{

nameFrg = libName;

if (buf[0] != '|')

nameFrg = "|";

nameFrg = buf;

typeEdit = 2; //запустить на редактирование

}

else

typeEdit = 0;

break;

case 2: //Редактировать_фрагмент

case 3: //Удалить_фрагмент

//выберем имя файла фрагмента

if ((j == 2 || j == 3) && ksChoiceFragmentFromLib(libName, buf, 250)!=0)

{

nameFrg = buf;

typeEdit = j; // 2- запустить на редактирование, 3-удалить

}

else

typeEdit = 0;

break;

}

if (j > 0 && typeEdit)

{

if (::ksFragmentLibrary((char*)nameFrg.c_str(), typeEdit))

{

if (typeEdit == 2)

{

::ksFragmentLibrary ((char *)nameFrg.c_str(), 4);

//минимизировать окно библиотекаря

//редактируем фрагмент из библиотеки

Text (0, 100, //точка привязки текста

0, //угол наклона текста

5, //высота текста

1, //сужение текста

0, //свойства строки

"Редактируем фрагмент из библиотеки"); //строка символов

LineSeg (0, 100, 110, 100, 1);

//редактируем фрагмент в интерактивном режиме

//после выбора в меню "Сервис" команды

//"Закончить редактирование фрагмента",

//возвращаемся в библиотеку

::SystemControlStart("Закончить редактирование фрагмента");

::ksFragmentLibrary((char *)nameFrg.c_str(), 0); //закрыть

//c сохранением

}

}

else

MessageBoxResult();

}

}

while (j != -1);

}
