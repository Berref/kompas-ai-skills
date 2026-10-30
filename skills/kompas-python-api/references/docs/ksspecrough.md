# ksSpecRough - Проставить знак неуказанной шероховатости в чертеже

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksspecroughw.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](kssetmaterialparam.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspecrough_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSpecRough](ksdocument2d_ksspecrough.html).

Синтаксис:

reference LIB_FUNK ksSpecRough (SpecRoughParam * par);

Выходной параметр:

par | \- указатель на структуру параметров знака неуказанной шероховатости [SpecRoughParam](structspecroughparam.html).  
---|---  
  
Возвращаемое значение:

указатель на знак неуказанной шероховатости | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksSpecRoughW](ksspecroughw.html).

Подразделы:

(отсутствуют)
