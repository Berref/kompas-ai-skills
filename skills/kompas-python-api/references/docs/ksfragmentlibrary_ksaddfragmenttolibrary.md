# ksAddFragmentToLibrary - Добавить фрагмент в библиотеку

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека фрагментов (Интерфейс ksFragmentLibrary) ](ksfragmentlibrary.html) > [ksFragmentLibrary - методы ](ksfragmentlibrary_methods.html) |  Scroll [ [ [ ](ksfragmentlibrary_kscheckfragmentlibrary.html "К следующему разделу")](ksfragmentlibrary_methods.html "На уровень выше")](ksfragmentlibrary_methods.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ksfragmentlibrary.html)

Аналог данного метода при использовании API экспортных функций - [ksAddFragmentToLibrary](ksaddfragmenttolibrary.html).

Синтаксис Automation:

long ksAddFragmentToLibrary (BSTR libName,

BSTR frwName);

Входные параметры:

libName | \- имя фрагмента в библиотеке,  
---|---  
libFile | \- имя файла фрагмента.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Допускается задание имени фрагмента следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец",

где

c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя фрагмента.

Подразделы:

(отсутствуют)
