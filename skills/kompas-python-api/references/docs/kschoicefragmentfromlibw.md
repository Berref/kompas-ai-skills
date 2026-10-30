# ksChoiceFragmentFromLibW - Выбрать имя фрагмента, хранящегося в библиотеке фрагментов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](kscreateinsertionfragment.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](kschoicefragmentfromlib.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksChoiceFragmentFromLib](ksfragmentlibrary_kschoicefragmentfromlib.html)

Синтаксис:

int LIB_FUNC ksChoiceFragmentFromLib (LPWSTR fileLibFrw,

LPWSTR nameFrw,

unsigned int size);

Входные параметры:

fileLibFrw | \- полное имя библиотеки фрагментов,  
---|---  
size | \- размер буфера фрагмента.  
  
Выходные параметры:

nameFrw | \- имя фрагмента.  
---|---  
  
Возвращаемое значение:

3 | \- имя фрагмента,  
---|---  
2 | \- имя папки,  
1 | \- корень библиотеки фрагментов,  
0 | \- в случае неудачи.  
  
Примечание:

1\. Библиотека фрагментов открывается в режиме диалога. Ее редактирование запрещено. Нажатие <Enter> \- выбор имени фрагмента. <Esc> \- отказ.

2\. При использовании ANSI следует использовать функцию [ksChoiceFragmentFromLib](kschoicefragmentfromlib.html).

Подразделы:

(отсутствуют)
