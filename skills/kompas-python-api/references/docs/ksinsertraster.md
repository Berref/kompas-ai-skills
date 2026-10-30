# ksInsertRaster - Вставить растровый объект

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksinsertrasterw.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](kshatchex.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksinsertraster_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksInsertRaster](ksdocument2d_ksinsertraster.html).

Синтаксис:

reference ksInsertRaster (RasterParam *par);

Входной параметр:

par | \- Структура параметров растрового объекта [RasterParam](structrasterparam.html).  
---|---  
  
Возвращаемое значение:

указатель на растровый объект | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksInsertRasterW](ksinsertrasterw.html).

Подразделы:

(отсутствуют)
