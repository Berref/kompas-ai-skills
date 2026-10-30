# ksFragmentLibraryOperation - Открыть библиотеку фрагментов

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека фрагментов (Интерфейс ksFragmentLibrary) ](ksfragmentlibrary.html) > [ksFragmentLibrary - методы ](ksfragmentlibrary_methods.html) |  Scroll [ [ [ ](kstreenodeparam.html "К следующему разделу")](ksfragmentlibrary_methods.html "На уровень выше")](ksfragmentlibrary_ksexistfragmentinlibrary.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ksfragmentlibrary.html)

Аналог данного метода при использовании API экспортных функций - [ksFragmentLibrary](ksfragmentlibrary_api.html).

Синтаксис Automation:

long ksFragmentLibraryOperation (LPCTSTR libName, long type);

Входные параметры:

libName | \- имя файла библиотеки фрагментов,  
---|---  
type | \- тип действия.  
  
[Типы действий с библиотекой фрагментов...](endtype.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

При выполнении операций типа -1, 0, 1, 4, 5 libName - полное имя файла библиотеки фрагментов.

При выполнении операций типа 2, 3 libName - полное имя файла библиотеки фрагментов + путь внутри библиотеки с именем редактируемого фрагмента.

Подразделы:

(отсутствуют)
