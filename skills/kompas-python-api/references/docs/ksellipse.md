# ksEllipse - Создать эллипс с заданными параметрами

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksellipsearc.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kscreateviewobject.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksellipse_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksEllipse](ksdocument2d_ksellipse.html).

Синтаксис:

reference ksEllipse (EllipseParam *par);

Выходной параметр:

par | \- указатель на [Структуру параметров эллипса](structellipseparam.html).  
---|---  
  
Возвращаемое значение:

указатель на эллипс | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Объект создается в текущем слое текущего вида.

Подразделы:

(отсутствуют)
