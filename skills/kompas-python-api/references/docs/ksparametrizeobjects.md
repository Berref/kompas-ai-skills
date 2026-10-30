# ksParametrizeObjects - Параметризовать группу объектов

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с параметрическими переменными и связями ](cm1746868.html) > [Функции параметризации и ограничений ](parametrization_fncts_common.html) |  Scroll [ [ [ ](kssetdocvariablearray.html "К следующему разделу")](parametrization_fncts_common.html "На уровень выше")](ksgetobjconstraints.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksParametrizeObjects](ksdocument2d_ksparametrizeobjects.html).

Синтаксис:

int ksParametrizeObjects (reference group, IParametrizeParam* param);

Входные параметры:

group | \- указатель на группу объектов,  
---|---  
param | \- параметры параметризации объектов.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если group = 0, параметризуется группа выделенных объектов.

2\. Допуск на совпадение точек должен лежать в диапазоне [0...10] мм.

3\. Угловой допуск должен лежать в диапазоне [0...10] градусов.

4\. Получить интерфейс параметров параметризации можно при помощи функции [ksGetParametrizationParam](ksgetparametrizationparam.html).

Подразделы:

(отсутствуют)
