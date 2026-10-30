# ksGetObjConstraints - Получить параметрические связи и ограничения, наложенные на указанный объект

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](ksparametrizeobjects.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](ksgetdocvariablearray.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetobjconstraints_ksdestroyobjconstraint_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetObjConstraints](ksdocument2d_ksgetobjconstraints.html).

Синтаксис:

reference ksGetObjConstraints (reference obj);

Входной параметр:

obj | \- указатель на объект,  
---|---  
  
Возвращаемое значение:

указатель на структуру параметров связей и ограничений [ConstraintParam](structconstraintparam.html) типа CONSTRAINT_ARR. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
