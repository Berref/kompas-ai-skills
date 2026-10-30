# ksAddArrayItem - Добавить элемент в массив

[API интерфейсов. Версия 5](ag57940.html) > [Динамический массив (Интерфейс ksDynamicArray) ](ksdynamicarray.html) > [ksDynamicArray - методы ](ksdynamicarray_methods.html) |  Scroll [ [ [ ](ksdynamicarray_kscleararray.html "К следующему разделу")](ksdynamicarray_methods.html "На уровень выше")](ksdynamicarray_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdynamicarray.html)

Аналог данного метода при использовании API экспортных функций - [AddArrayItem](addarrayitem.html).

Синтаксис Automation:

long ksAddArrayItem (long index, LPDISPATCH item);

Входные параметры:

index | \- индекс элемента, перед которым нужно вставить новый элемент, нумерация начинается с 0, при index=-1 элемент добавляется в конец массива,  
---|---  
item | \- указатель на интерфейс соответствующего типа.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Смотрите также:

[Типы динамических массивов...](ksdmtypes.html)

Подразделы:

(отсутствуют)
