# ksGetDocVariableArray - Получить массив параметрических переменных графического документа или вставки фрагмента

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](ksgetobjconstraints.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](ksgetdimensionvariablename.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetdocvariablearray_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetDocVariableArray](ksdocument2d_ksgetdocvariablearray.html).

Синтаксис:

reference ksGetDocVariableArray (reference p);

Входной параметр:

p | \- указатель на документ или вставку фрагмента.  
---|---  
  
Возвращаемое значение:

указатель на динамический массив структур VariableParam | \- в случае успеха,  
---|---  
[0](structvariableparam.html) | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
