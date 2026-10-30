# ksGetLibraryTreeStructW - Получить структуру дерева библиотеки документов и библиотеки атрибутов (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Сервисные библиотечные функции ](serv_lib_func_common.html) |  Scroll [ [ [ ](ksgetsystemcontrolstartresult.html "К следующему разделу")](serv_lib_func_common.html "На уровень выше")](ksgetlibrarytreestruct.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetLibraryTreeStruct](kompasobject_ksgetlibrarytreestruct.html).

Синтаксис:

int LIB_FUNC ksGetLibraryTreeStructW (LPWSTR libName, TreeNodeParam * root);

Входные параметры:

libName | \- полное имя файла библиотеки моделей, фрагментов, атрибутов,  
---|---  
root | \- заполняется параметрами корня дерева.  
  
Возвращаемое значение:

0 | \- в случае неудачи.  
---|---  
  
Примечание.

При использовании ANSI следует использовать функцию [ksGetLibraryTreeStruct](ksgetlibrarytreestruct.html).

Подразделы:

(отсутствуют)
