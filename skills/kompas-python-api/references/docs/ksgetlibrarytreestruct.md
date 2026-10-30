# ksGetLibraryTreeStruct - Получить структуру дерева библиотеки документов и библиотеки атрибутов

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksgetlibrarytreestructw.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksexecutelibrarycommandw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetLibraryTreeStruct](kompasobject_ksgetlibrarytreestruct.html).

Синтаксис:

int ksGetLibraryTreeStruct (char * libName, TreeNodeParam * root);

Входные параметры:

libName | \- полное имя файла библиотеки моделей, фрагментов, атрибутов,  
---|---  
root | \- заполняется параметрами корня дерева.  
  
[Структура параметров узла дерева объектов библиотеки TreeNodeParam...](structtreenodeparam.html)

Возвращаемое значение:

0 | \- в случае неудачи.  
---|---  
  
Примечание.

При использовании Unicode следует использовать функцию[ ksGetLibraryTreeStructW](ksgetlibrarytreestructw.html).

Подразделы:

(отсутствуют)
