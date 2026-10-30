# ksInsertRasterW - Вставить растровый объект (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Графические примитивы ](gr_primits_fncts_common.html) |  Scroll [ [ [ ](ksparellipsearc.html "К следующему разделу")](gr_primits_fncts_common.html "На уровень выше")](ksinsertraster.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksInsertRaster](ksdocument2d_ksinsertraster.html).

Синтаксис:

reference ksInsertRasterW (RasterParamW *par);

Входной параметр:

par | \- Структура параметров растрового объекта [RasterParamW](structrasterparamw.html).  
---|---  
  
Возвращаемое значение:

указатель на растровый объект | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksInsertRaster](ksinsertraster.html).

Подразделы:

(отсутствуют)
