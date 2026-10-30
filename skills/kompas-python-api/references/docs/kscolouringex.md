# ksColouringEx - Создать фоновую заливку цветом

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksconicarc.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kscolouring.html "К предыдущему разделу")  
---|---  
  
[Пример...](kscolouringex_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksColouringEx](ksdocument2d_kscolouringex.html).

Синтаксис:

reference ksColouringEx (unsigned long color, reference group);

Входные параметры:

color | \- цвет заливки,  
---|---  
group | \- группа, образующая границу заливки.  
  
Возвращаемое значение:

указатель на заливку | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если color = -1 или 0xFFFFFFFF, то создается заливка цветом фона документа.

Подразделы:

(отсутствуют)
