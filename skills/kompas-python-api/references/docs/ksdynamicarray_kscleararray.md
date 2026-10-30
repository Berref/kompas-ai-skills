# ksClearArray - Очистить массив

[API интерфейсов. Версия 5](ag57940.html) > [Динамический массив (Интерфейс ksDynamicArray) ](ksdynamicarray.html) > [ksDynamicArray - методы ](ksdynamicarray_methods.html) |  Scroll [ [ [ ](ksdynamicarray_ksdeletearray.html "К следующему разделу")](ksdynamicarray_methods.html "На уровень выше")](ksdynamicarray_ksaddarrayitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdynamicarray.html)

Аналог данного метода при использовании API экспортных функций - [ClearArray](cleararray.html).

Синтаксис Automation:

long ksClearArray();

Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Из массива удаляются все элементы, но сам массив не удаляется.

2\. При удалении пользовательского элемента, автоматические вызывается пользовательская функция удаления элемента, заданная пользователем при создании массива.

Подразделы:

(отсутствуют)
