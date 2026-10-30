# ksChoiceFragmentFromLib - Выбрать имя фрагмента или папки в библиотеке фрагментов

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека фрагментов (Интерфейс ksFragmentLibrary) ](ksfragmentlibrary.html) > [ksFragmentLibrary - методы ](ksfragmentlibrary_methods.html) |  Scroll [ [ [ ](ksfragmentlibrary_ksexistfragmentinlibrary.html "К следующему разделу")](ksfragmentlibrary_methods.html "На уровень выше")](ksfragmentlibrary_kscheckfragmentlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfragmentlibrary.html)

Аналог данного метода при использовании API экспортных функций -[ ksChoiceFragmentFromLib](kschoicefragmentfromlib.html).

Синтаксис Automation:

BSTR ksChoiceFragmentFromLib (BSTR frwLibFile,

long* type);

Входные параметры:

frwLibFile | \- имя файла библиотеки фрагментов,  
---|---  
type | \- тип возвращаемого значения: 3 - имя фрагмента, 2 - имя папки, 1- корень библиотеки фрагментов, 0 - ошибка.  
  
Возвращаемое значение:

| имя фрагмента.  
---|---  
  
Примечание:

Библиотека фрагментов открывается в режиме диалога.

Ее редактирование запрещено.

Enter - выбор имени фрагмента. Esc - отказ.

Подразделы:

(отсутствуют)
