# GetArrayItem - Получить элемент массива

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с динамическими массивами ](dyn_massive_fncts_common.html) |  Scroll [ [ [ ](getarraytype.html "К следующему разделу")](dyn_massive_fncts_common.html "На уровень выше")](getarraycount.html "К предыдущему разделу")  
---|---  
  
[Пример...](dynamic_massiv_func_example.html)

Аналог данной функции при использовании Automation - метод [ksDynamicArray::ksGetArrayItem](ksdynamicarray_ksgetarrayitem.html).

Синтаксис:

int GetArrayItem (reference p, int numb, void * value, int size);

Входные параметры:

p | \- указатель на массив,  
---|---  
numb | \- номер элемента массива, нумерация начинается с 0,  
size | \- длина области памяти.  
  
Входные параметры:

value | \- указатель на область памяти, куда будет помещено значение.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
