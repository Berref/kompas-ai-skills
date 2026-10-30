# LIBRARYHELPFILE - Определить имя файла справочной системы, подключаемого к библиотеке

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа DLL ](cr92212.html) > [Пример простейшей программы в среде VC++, оформленной в виде библиотеки КОМПАС ](simple_sample.html) > [Функции ](cr71826.html) |  Scroll [ [ [ ](libraryhelpfilew.html "К следующему разделу")](cr71826.html "На уровень выше")](librarybmpsize.html "К предыдущему разделу")  
---|---  
  
[Пример...](libraryentry_example.html)

Синтаксис:

extern "C" char far * pascal LIBRARYHELPFILE()

Описание:

Разделы Справочной системы могут иметь как библиотечные функции, так и команды меню, создаваемые внутри них и передаваемые в функции [Placement](placement.html) и [Cursor](cursor.html).

Примечание:

При использовании Unicode следует использовать функцию [LIBRARYHELPFILEW](libraryhelpfilew.html).

Подразделы:

(отсутствуют)
