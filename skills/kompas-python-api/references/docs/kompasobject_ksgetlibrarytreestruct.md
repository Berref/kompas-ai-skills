# ksGetLibraryTreeStruct - Получить структуру дерева библиотеки документов и библиотеки атрибутов

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetobjectsfilter3d.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetlibrarystylesarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании экспортных функций [ksGetLibraryTreeStruct](ksgetlibrarytreestruct.html).

Синтаксис Automation:

BOOL ksGetLibraryTreeStruct (BSTR libName, LPDISPATCH root);

Входной параметр:

libName | \- полное имя файла библиотеки моделей, фрагментов, атрибутов,  
---|---  
root | \- указатель на интерфейс [ksTreeNodeParam](kstreenodeparam.html) параметров корневого узла дерева.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
