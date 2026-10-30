# ksExistFragmentInLibraryW - Проверить наличие указанного фрагмента или раздела в библиотеке фрагментов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](ksfragmentlibrary_api.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](ksexistfragmentinlibrary.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksexistfragmentinlibrary_example.html)

Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksExistFragmentInLibrary](ksfragmentlibrary_ksexistfragmentinlibrary.html).

Синтаксис:

int LIB_FUNC ksExistFragmentInLibraryW (LPWSTR frwName);

Входной параметр:

frwName | \- имя фрагмента.  
---|---  
  
Возвращаемое значение:

1 | \- указанный фрагмент или папка есть в библиотеке,  
---|---  
0 | \- указанного фрагмента или папки нет,  
-1 | \- нет указанной библиотеки.  
  
Примечание:

Пример формирования имени фрагмента:

– "c:\\_f\gr\lib1.lfr|детали|литье|фланец", где

– c:\\_f\gr\lib1.lfr - имя файла библиотеки фрагментов,

– |детали|литье|- разделы, подразделы внутри библиотеки,

– фланец - имя фрагмента или имя подраздела).

Подразделы:

(отсутствуют)
