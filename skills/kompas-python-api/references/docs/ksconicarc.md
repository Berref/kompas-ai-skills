# ksConicArc - Построить коническое сечение

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](kscreateviewobject.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kscolouringex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksconicarc_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksConicArc](ksdocument2d_ksconicarc.html).

Синтаксис:

reference ksConicArc (ConicArcParam * par);

Входной параметр:

par | \- указатель на структуру параметров конического сечения [ConicArcParam](structconicarcparam.html)  
---|---  
  
Возвращаемое значение:

указатель на коническое сечение | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Коническим сечением может быть дуга окружности, дуга эллипса или кривая NURBS.

Подразделы:

(отсутствуют)
