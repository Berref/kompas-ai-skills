# SetArrayItem - Установить параметры элемента динамического массива

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с динамическими массивами ](dyn_massive_fncts_common.html) |  Scroll [ [ [ ](attribs_fncts_common.html "К следующему разделу")](dyn_massive_fncts_common.html "На уровень выше")](getuserarrayitem.html "К предыдущему разделу")  
---|---  
  
[Пример...](dynamic_massiv_func_example.html)

Аналог данной функции при использовании Automation - метод [ksDynamicArray::ksSetArrayItem](ksdynamicarray_kssetarrayitem.html).

Синтаксис:

int SetArrayItem (reference p, int numb, void * value, int size);

Входные параметры:

p | \- указатель на массив,  
---|---  
numb | \- номер элемента массива, нумерация начинается с 0,  
size | \- длина структуры-источника.  
  
Выходной параметр:

value | \- указатель на структуру параметров элемента массива.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
