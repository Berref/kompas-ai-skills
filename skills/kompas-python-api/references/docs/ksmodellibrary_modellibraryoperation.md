# ModelLibraryOperation - Действия с библиотекой моделей

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека моделей (Интерфейсы ksModelLibrary и IModelLibrary ) ](ksmodellibrary.html) > [ksModelLibrary - методы ](ksmodellibrary_methods.html) |  Scroll [ [ [ ](ksfragmentlibrary.html "К следующему разделу")](ksmodellibrary_methods.html "На уровень выше")](ksmodellibrary_existmodelinlibrary.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ksmodellibrary.html)

Синтаксис Automation:

long ModelLibraryOperation (BSTR libName,

long type);

Синтаксис COM:

long ModelLibraryOperation (LPOLESTR libName,

long type);

Входные параметры:

libName | \- имя файла библиотеки моделей,  
---|---  
type | \- тип действия.  
  
[Типы действий с библиотекой моделей...](endtype.html)

Возвращаемое значение:

1 | \- в случае успешного завершения.  
---|---  
  
Примечания:

1\. При выполнении операций -1, 0, 1, 4, 5 libName - полное имя файла библиотеки моделей.

2\. При выполнении операций 2, 3 libName - полное имя файла библиотеки моделей путь внутри библиотеки с именем редактируемой модели.

3\. Допускается задание имени файла библиотеки следующего вида: "c:\gr\lib1.l3d|детали|литье|фланец",

где

c:\gr\lib1.l3d - имя файла библиотеки моделей,

|детали|литье| - разделы, подразделы внутри библиотеки моделей,

фланец - имя модели.

Подразделы:

(отсутствуют)
