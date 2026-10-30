# ksSetObjConstraint - Установить параметрическую связь или ограничение

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](cn1712096.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](kssetdocvariablearray.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssetobjconstraint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetObjConstraint](ksdocument2d_kssetobjconstraint.html).

Синтаксис:

int ksSetObjConstraint (reference obj,

ConstraintParam *par);

Входные параметры:

obj | \- объект, на который накладывается связь или ограничение,  
---|---  
par | \- указатель на [структуру параметрической связи или ограничения ConstraintParam...](structconstraintparam.html).  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
