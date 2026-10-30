# Пример использования функций оформления библиотеки

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Пример:

#define LIB_ID 1000

// Определить имя библиотеки /* LIBRARYNAME */

char* WINAPI LIBRARYNAME()

return "Простая библиотека";

}

// Задать идентификатор ресурсов

/* LibraryID */

int WINAPI LIBRARYID()

{

return LIB_ID; /*Идентификатор библиотеки равен 1000*/

}

// Задать размер окна вывода BITMAP-слайда

/* LibraryBmpSize */

long WINAPI LIBRARYBMPSIZE()

{

return MAKELONG( 170, 160 );

}

// Определить имя файла справочной системы

/* LibraryHelpFile */

char WINAPI LIBRARYHELPFILE()

{

return "Konstr.hlp";

}

// Головная функция библиотеки

void WINAPI LIBRARYENTRY( UINT Comm )

{

switch ( Comm )

{

case 1:

DrawBolt7798;

break;

case 2:

DrawShayba18123;

break;

case 3:

DrawGayka6393;

break;

case 4:

DrawGayka5915;

break;

case 5:

DrawGayka15521;

break;

case 6:

DrawShtift10774;

break;

}

};

/* LibraryEntry*/

// Получить идентификаторы панелей

int WINAPI LibToolBarId (int barType, int index)

{

// Компактные панели

if(!barType)

{

return !index ? COMPACT_BAR1 : -1;

}

// Инструментальные панели

else

{

switch (index)

{

case 0 : return BAR_1;

case 1 : return BAR_2;

case 2 : return BAR_3;

}

}

return -1;

}

/*LibToolBarId*/

/*

// Пример файла ресурсов (rc):

// С каждой строкой меню будет выводиться соответствующий по номеру команды BITMAP - слайд, иллюстрирующий выбранную операцию.

//Размер слайда может быть произвольным. Он определяется функцией [LIBRARYBMPSIZE](librarybmpsize.html).

//битмапы для отображения в менеджере библиотек (идентификатор равен номеру команды)

// Определение BITMAP-слайдов для библиотечных функций:

1 BITMAP "B7798.bmp"

2 BITMAP "Sh18123.bmp"

3 BITMAP "G6393.bmp"

4 BITMAP "G5915.bmp"

5 BITMAP "G15521.bmp"

6 BITMAP "Sh10774.bmp"

// Определение в файле ресурсов меню операций.

// Примечание: Идентификаторы команд меню должны быть в интервале от 1 до 900.

// Команда выбранной строчки меню будет передана в функцию LibraryEntry.

KONSTR_1 MENU

{

MENUITEM "Болт ГОСТ 7798-70", 1

MENUITEM "Шайба ГОСТ 18123-72", 2

POPUP "ГАЙКИ"

{

MENUITEM "Гайка ГОСТ 6393-73", 3

POPUP "ГАЙКИ ШЕСТИГРАННЫЕ"

{

MENUITEM "Гайка ГОСТ 5915-70", 4

MENUITEM "Гайка ГОСТ 15521-50", 5

}

}

MENUITEM "Штифт ГОСТ 10774-80", 6

}

// Определение размеров окна вывода BITMAP-слайда.

// Примечание: Идентично вызову ф-ии LIBRARYBMPSIZE, но приоритет вызова функции выше.

KONSTR_1 RCDATA

{

170 // Размер по горизонтали

160 // Размер по вертикали

}

// Определение имени библиотеки:

// Примечание: Идентично вызову ф-ии LIBRARYNAME, но приоритет вызова функции выше.

STRINGTABLE

{

KONSTR_1 "Конструкторская библиотека"

}

// Определение имени иконки для минимизированного окна библиотеки:

KONSTR_1 ICON "konstr.ico"

// При подключении библиотеки будет создана компактная панель "Конструкторская библиотека", в которую входят

// инструментальные панели "Болты" и "Шайбы". Также отдельно будет создана инструментальная панель "Гайки".

// Команда "Штифт ГОСТ 10774-80" не входит ни в одну из панелей.

// Определение имени панелей:

STRINGTABLE {

BAR_1 "Болты"

BAR_2 "Шайбы"

BAR_3 "Гайки"

COMPACT_BAR1 "Конструкторская библиотека"

}

#define END_OF_RESOURCE_TABLE 0xffff

// Определение состава панелей:

COMPACT_BAR1 RCDATA

{

BAR_1

BAR_2

END_OF_RESOURCE_TABLE

}

BAR_1 RCDATA

{

1 // Болт ГОСТ 7798-70

END_OF_RESOURCE_TABLE

}

BAR_2 RCDATA

{

2 // Шайба ГОСТ 18123-72

END_OF_RESOURCE_TABLE

}

BAR_3 RCDATA

{

3 // Гайка ГОСТ 6393-73

4 // Гайка ГОСТ 5915-70

5 // Гайка ГОСТ 15521-50

END_OF_RESOURCE_TABLE

}

// Определение иконок инструментальных панелей:

BAR_1 ICON DISCARDABLE "bar1.ico"

BAR_2 ICON DISCARDABLE "bar2.ico"

BAR_3 ICON DISCARDABLE "bar3.ico"

*/

//битмапы для отображения в панелях и в настройках интерфейса ( идентификатор равен номеру команды + 1000 ) размер битмапа должен быть 22х22 пиксела

1001 BITMAP "B7798.bmp"

1002 BITMAP "Sh18123.bmp"

1003 BITMAP "G6393.bmp"

1004 BITMAP "G5915.bmp"

1005 BITMAP "G15521.bmp"

1006 BITMAP "Sh10774.bmp"
