# ksSetCurrentLibrary - Установить текущую библиотеку

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](kssetcurrentlibraryw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksopenhelpfilew.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssetcurrentlibrary_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksConvertLangMenu](kompasobject_ksconvertlangmenu.html).

Синтаксис:

int ksSetCurrentLibrary (char * libname, long hModule);

Входные параметры:

libname | \- имя библиотеки,  
---|---  
hModule | \- идентификатор модуля Dll библиотеки.  
  
Возвращаемое значение:

1 | \- библиотека стала текущей,  
---|---  
0 | \- в случае ошибки.  
  
Примечание:

1\. Назначить библиотеку текущей можно либо по идентификатору модуля Dll библиотеки, либо по имени библиотеки.

2\. Данный метод следует использовать осторожно, иначе можно нарушить последовательность выполнения библиотек.

3\. Метод может быть применен к подключенной библиотеке.

4\. Метод позволяет остановить режим SystemControlStart, запущенный не из выполняемой (текущей) библиотеки.

5\. При использовании Unicode следует использовать функцию [ksSetCurrentLibraryW](kssetcurrentlibraryw.html).

Подразделы:

(отсутствуют)
