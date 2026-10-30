# DeleteArray - Удалить массив

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с динамическими массивами ](dyn_massive_fncts_common.html) |  Scroll [ [ [ ](excludearrayitem.html "К следующему разделу")](dyn_massive_fncts_common.html "На уровень выше")](createarray.html "К предыдущему разделу")  
---|---  
  
[Пример...](dynamic_massiv_func_example.html)

Аналог данной функции при использовании Automation - метод [ksDynamicArray::ksDeleteArray](ksdynamicarray_ksdeletearray.html).

Синтаксис:

int DeleteArray (reference p);

Входной параметр:

p | \- указатель на массив.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае ошибки.  
  
Примечание:

Может быть удален непустой массив, то есть перед вызовом функции DeleteArray вызывать [ClearArray](cleararray.html) необязательно.

Подразделы:

(отсутствуют)
