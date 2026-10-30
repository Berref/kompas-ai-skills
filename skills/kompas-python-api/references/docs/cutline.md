# CutLine - Создать линию разреза/сечения

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](diamdimension.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](closetechnicaldemand.html "К предыдущему разделу")  
---|---  
  
[Пример...](cutline_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCutLine](ksdocument2d_kscutline.html).

Синтаксис:

reference CutLine (CutLineParam *cutPar);

Выходной параметр:

cutPar | \- указатель на структуру параметров линии разреза/сечения [CutLineParam](structcutlineparam.html).  
---|---  
  
Возвращаемое значение:

указатель на линию разреза/сечения | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
