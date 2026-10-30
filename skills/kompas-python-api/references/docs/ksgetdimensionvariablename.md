# ksGetDimensionVariableName - Получить имя параметрической переменной, связанной с размером

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](ksgetdocvariablearray.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](ksdestroyobjconstraint.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetdimensionvariablename_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetDimensionVariableName](ksdocument2d_ksgetdimensionvariablename.html).

Синтаксис:

int ksGetDimensionVariableName (reference dimObj,

char * varName,

int size);

Входной параметр:

dimObj | \- указатель на размер.  
---|---  
  
Выходной параметр:

varName | \- имя переменной, если размеру поставлена в соответствие переменная,  
---|---  
size | \- размер буфера, выделенного под имя переменной,  
пустая строка | \- если размеру не поставлена в соответствие переменная или в случае неудачи.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
