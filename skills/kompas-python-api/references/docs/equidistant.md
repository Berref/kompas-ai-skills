# Equidistant - Построить эквидистанту

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](hatch.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](circle.html "К предыдущему разделу")  
---|---  
  
[Пример...](equidistant_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksEquidistant](ksdocument2d_ksequidistant.html).

Синтаксис:

reference Equidistant (EquidistantParam *par);

Выходной параметр:

par | \- указатель на [структуру параметров эквидистанты](structequidistantparam.html).  
---|---  
  
Возвращаемое значение:

указатель на эквидистанту | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объект создается в текущем слое текущего вида.

Подразделы:

(отсутствуют)
