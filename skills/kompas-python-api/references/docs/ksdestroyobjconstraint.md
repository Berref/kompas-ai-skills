# ksDestroyObjConstraint - Удалить параметрическую связь или ограничение, наложенные на указанный объект

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](ksgetdimensionvariablename.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](parametrization_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetobjconstraints_ksdestroyobjconstraint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksDestroyObjConstraint](ksdocument2d_ksdestroyobjconstraint.html).

Синтаксис:

int ksDestroyObjConstraint (reference obj,

ConstraintParam *par);

Входные параметры:

obj | \- указатель на объект,  
---|---  
par | \- указатель на [структуру параметрической связи или ограничения ConstraintParam...](structconstraintparam.html)  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
