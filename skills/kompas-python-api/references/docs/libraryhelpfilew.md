# LIBRARYHELPFILEW - Определить имя файла справочной системы, подключаемого к библиотеке (Unicode)

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа DLL ](cr92212.html) > [Пример простейшей программы в среде VC++, оформленной в виде библиотеки КОМПАС ](simple_sample.html) > [Функции ](cr71826.html) |  Scroll [ [ [ ](libtoolbarid.html "К следующему разделу")](cr71826.html "На уровень выше")](libraryhelpfile.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

extern "C" LPWSTR WINAPI __export LIBRARYHELPFILEW()

Описание:

Разделы Справочной системы могут иметь как библиотечные функции, так и команды меню, создаваемые внутри них и передаваемые в функции [Placement](placement.html) и [Cursor](cursor.html).

Примечание:

При использовании ANSI следует использовать функцию [LIBRARYHELPFILE](libraryhelpfile.html).

Подразделы:

(отсутствуют)
