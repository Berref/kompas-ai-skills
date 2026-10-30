# AddD3DocumentToLibrary - Добавить модель с указанным именем файла в указанную библиотеку моделей

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека моделей (Интерфейсы ksModelLibrary и IModelLibrary ) ](ksmodellibrary.html) > [ksModelLibrary - методы ](ksmodellibrary_methods.html) |  Scroll [ [ [ ](ksmodellibrary_checkmodellibrary.html "К следующему разделу")](ksmodellibrary_methods.html "На уровень выше")](ksmodellibrary_methods.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ksmodellibrary.html)

Синтаксис Automation:

long AddD3DocumentToLibrary (BSTR libName,

BSTR libFile);

Синтаксис COM:

long AddD3DocumentToLibrary (LPOLESTR libName,

LPOLESTR fileName);

Входные параметры:

libName | \- имя файла библиотеки моделей,  
---|---  
libFile | \- имя файла модели.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения.  
---|---  
  
Примечание:

Имя файла библиотеки моделей должно содержать путь внутри библиотеки и имя модели, например: "c:\gr\lib1.l3d|детали|литье|фланец",

где

c:\gr\lib1.l3d - имя файла библиотеки моделей,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя модели.

Подразделы:

(отсутствуют)
