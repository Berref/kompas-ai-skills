# ksIsLibraryEnabledW - Проверить защиту библиотеки фрагментов и моделей (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](cm1732355.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](ksislibraryenabled.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksIsLibraryEnabled](kompasobject_ksislibraryenabled.html).

Синтаксис:

int LIB_FUNC ksIsLibraryEnabledW (LPWSTR libName);

Входные параметры:

libName | \- имя библиотеки либо полное, либо относительно папки LIBS.  
---|---  
  
Возвращаемое значение:

1 | \- выполнять библиотеку можно,  
---|---  
0 | \- выполнять библиотеку нельзя.  
  
Примечание:

Функция применима для прикладных библиотек (*.rtw), библиотек фрагментов (*.lfr), библиотек моделей (*.l3d).

При использовании ANSI следует использовать функцию [ksIsLibraryEnabled](ksislibraryenabled.html).

Подразделы:

(отсутствуют)
