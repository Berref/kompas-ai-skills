# OpenTechnicalDemand - Открыть технические требования

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](positionleader.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](markerleader.html "К предыдущему разделу")  
---|---  
  
[Пример...](open_close_technicaldemand_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksOpenTechnicalDemand](ksdocument2d_ksopentechnicaldemand.html)

Синтаксис:

int OpenTechnicalDemand (reference pGab);

Входные параметры:

pGab | \- указатель на динамический массив параметров листов технических требований типа RECT_ARR.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Следующие далее функции до вызова [CloseTechnicalDemand](closetechnicaldemand.html) определяют текст технических требований. Параметр pGab определяет массив габаритных прямоугольников страниц технических требований неопределенной длины. Если pGab = 0, то технические требования размещаются на одной странице автоматически.

Подразделы:

(отсутствуют)
