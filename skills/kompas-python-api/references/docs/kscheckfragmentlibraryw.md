# ksCheckFragmentLibraryW - Проверить, открыта ли библиотека фрагментов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Библитеки фрагментов ](frag_libs_fncts.html) |  Scroll [ [ [ ](kschoicefragmentfromlib.html "К следующему разделу")](frag_libs_fncts.html "На уровень выше")](kscheckfragmentlibrary.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

Аналог данной функции при использовании Automation - метод [ksFragmentLibrary::ksCheckFragmentLibrary](ksfragmentlibrary_kscheckfragmentlibrary.html).

Синтаксис:

int LIB_FUNC ksCheckFragmentLibraryW (LPWSTR libName, unsigned char possibleMessage);

Входные параметры:

libName | \- имя файла библиотеки фрагментов,  
---|---  
possibleMessage | \- признак выдачи сообщения: \- 1 - сообщать, если библиотека уже открыта, \- 0 - не сообщать.  
  
Возвращаемое значение:

1 | \- если библиотека открыта,  
---|---  
0 | \- если библиотека не открыта.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksCheckFragmentLibrary](kscheckfragmentlibrary.html).

Подразделы:

(отсутствуют)
