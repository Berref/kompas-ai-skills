# ksSetDocVariableArray - Заменить значения параметрических переменных

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](kssetobjconstraint.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](ksparametrizeobjects.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetdocvariablearray_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetDocVariableArray](ksdocument2d_kssetdocvariablearray.html).

Синтаксис:

int ksSetDocVariableArray (reference obj,

reference arr,

unsigned char setNote);

Входные параметры:

obj | \- указатель на документ или вставку фрагмента,  
---|---  
arr | \- указатель на динамический массив VARIABLE_ARR,  
setNote | признак редактирования комментариев: 0 - комментарии не менять, 1 - комментарии менять.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
