# ksFragmentLibrary - Открыть библиотеку фрагментов

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](ksfragmentlibrary_apiw.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](ksexistfragmentinlibraryw.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Пример...](ksfragmentlibrary_example.html)

Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksFragmentLibraryOperation](ksfragmentlibrary_ksfragmentlibraryoperation.html).

Синтаксис:

int ksFragmentLibrary (char * libName, int type);

Входные параметры:

libName | \- имя файла библиотеки фрагментов,  
---|---  
type | \- [тип действия с библиотекой фрагментов](endtype.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. При выполнении операций типа -1, 0, 1, 4, 5 libName - полное имя файла библиотеки фрагментов.

При выполнении операций типа 2, 3 libName - полное имя файла библиотеки фрагментов путь внутри библиотеки с именем редактируемого фрагмента.

2\. При использовании Unicode следует использовать функцию [ksFragmentLibraryW](ksfragmentlibrary_apiw.html).

Подразделы:

(отсутствуют)
