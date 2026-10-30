# ExistModelInLibrary - Проверить, существует ли в библиотеке указанная модель или папка

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с библиотеками ](ck1750127.html) > [Библиотека моделей (Интерфейсы ksModelLibrary и IModelLibrary ) ](ksmodellibrary.html) > [ksModelLibrary - методы ](ksmodellibrary_methods.html) |  Scroll [ [ [ ](ksmodellibrary_modellibraryoperation.html "К следующему разделу")](ksmodellibrary_methods.html "На уровень выше")](ksmodellibrary_choicemodelfromlib.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmodellibrary.html)

Синтаксис Automation:

long ExistModelInLibrary (BSTR name);

Синтаксис COM:

long ExistModelInLibrary (LPOLESTR name);

Входной параметр:

name | \- имя файла библиотеки моделей и модели (или папки) в нем.  
---|---  
  
Возвращаемое значение:

-1 | \- указанная библиотека не существует,  
---|---  
0 | \- указанная модель или папка не существует,  
1 | \- модель или папка существует.  
  
Примечание:

Допускается задание имени файла библиотеки следующего вида: "c:\gr\lib1.l3d|детали|литье|фланец",

где

c:\gr\lib1.l3d - имя файла библиотеки моделей,

|детали|литье| - разделы, подразделы внутри библиотеки фрагментов,

фланец - имя модели.

Подразделы:

(отсутствуют)
