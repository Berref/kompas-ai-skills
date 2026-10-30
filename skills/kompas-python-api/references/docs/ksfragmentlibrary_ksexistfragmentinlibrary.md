# ksExistFragmentInLibrary - Проверить наличие указанного фрагмента или раздела в библиотеке фрагментов

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека фрагментов (Интерфейс ksFragmentLibrary) ](ksfragmentlibrary.html) > [ksFragmentLibrary - методы ](ksfragmentlibrary_methods.html) |  Scroll [ [ [ ](ksfragmentlibrary_ksfragmentlibraryoperation.html "К следующему разделу")](ksfragmentlibrary_methods.html "На уровень выше")](ksfragmentlibrary_kschoicefragmentfromlib.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragmentlibrary.html)

Аналог данного метода при использовании API экспортных функций - [ksExistFragmentInLibrary](ksexistfragmentinlibrary.html).

Синтаксис Automation:

long ksExistFragmentInLibrary (BSTR frwName);

Входной параметр:

name | \- имя файла библиотеки моделей.  
---|---  
  
Возвращаемое значение:

1 | \- указанный фрагмент или папка есть в библиотеке,  
---|---  
0 | \- указанного фрагмента или папки нет,  
-1 | \- нет указанной библиотеки.  
  
Примечание:

Допускается задание имени файла следующего вида: "c:\gr\lib1.lfr|детали|литье|фланец",

где

c:\gr\lib1.lfr - имя файла библиотеки фрагментов,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя фрагмента.

Подразделы:

(отсутствуют)
