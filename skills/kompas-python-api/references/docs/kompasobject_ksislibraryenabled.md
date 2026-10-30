# ksIsLibraryEnabled - Проверить защиту библиотеки фрагментов и моделей

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksismodule3dactive.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksiskompascommandenable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksIsLibraryEnabled](ksislibraryenabled.html).

Синтаксис Automation:

long ksIsLibraryEnabled(BSTR libName);

Входные параметры:

libName | \- имя библиотеки либо полное, либо относительно папки LIBS.  
---|---  
  
Возвращаемое значение:

1 | \- выполнить библиотеку можно,  
---|---  
0 | \- выполнить библиотеку нельзя.  
  
Примечание:

Функция применима для библиотек rtw, библиотек фрагментов lfr, библиотек моделей l3d

Подразделы:

(отсутствуют)
