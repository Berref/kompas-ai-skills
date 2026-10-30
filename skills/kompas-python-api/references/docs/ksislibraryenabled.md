# ksIsLibraryEnabled - Проверить защиту библиотеки фрагментов и моделей

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](ksislibraryenabledw.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](ksfragmentlibrary_apiw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksIsLibraryEnabled](kompasobject_ksislibraryenabled.html).

Синтаксис:

int ksIsLibraryEnabled (char * libName);

Входные параметры:

libName | \- имя библиотеки либо полное, либо относительно папки LIBS.  
---|---  
  
Возвращаемое значение:

1 | \- выполнять библиотеку можно,  
---|---  
0 | \- выполнять библиотеку нельзя.  
  
Примечание:

1\. Функция применима для прикладных библиотек (*.rtw), библиотек фрагментов (*.lfr), библиотек моделей (*.l3d).

2\. При использовании Unicode следует использовать функцию [ksIsLibraryEnabledW](ksislibraryenabledw.html).

Подразделы:

(отсутствуют)
