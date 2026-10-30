# ksAddFragmentToLibrary - Добавить фрагмент в библиотеку фрагментов

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](ksaddfragmenttolibraryw.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](frag_libs_fncts.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Пример...](ksaddfragmenttolibrary_example.html)

Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksAddFragmentToLibrary](ksfragmentlibrary_ksaddfragmenttolibrary.html)

Синтаксис:

int ksAddFragmentToLibrary (char * libName, char * frwName);

Входные параметры:

libName | \- имя фрагмента в библиотеке,  
---|---  
frwName | \- имя файла фрагмента.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Допускается задание имени фрагмента следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец", где:

– c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

– |детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

– фланец - имя фрагмента.

2\. При использовании Unicode следует использовать функцию [ksAddFragmentToLibraryW](ksaddfragmenttolibraryw.html).

Подразделы:

(отсутствуют)
