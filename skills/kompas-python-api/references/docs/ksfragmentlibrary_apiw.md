# ksFragmentLibraryW - Открыть библиотеку фрагментов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](ksislibraryenabled.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](ksfragmentlibrary_api.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksFragmentLibraryOperation](ksfragmentlibrary_ksfragmentlibraryoperation.html).

Синтаксис:

int LIB_FUNC ksFragmentLibraryW (LPWSTR libName, int type);

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

2\. При выполнении операций типа 2, 3 libName - полное имя файла библиотеки фрагментов путь внутри библиотеки с именем редактируемого фрагмента.

3\. При использовании ANSI следует использовать функцию [ksFragmentLibrary](ksfragmentlibrary_api.html).

Подразделы:

(отсутствуют)
