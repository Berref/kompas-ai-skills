# ksGetZoomScale - Получить масштаб и центр изменения масштаба окна графического документа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции управления масштабом ](zoom_fncts_common.html) |  Scroll [ [ [ ](kssetzoomscale.html "К следующему разделу")](zoom_fncts_common.html "На уровень выше")](zoom_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetzoomscale_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetZoomScale](ksdocument2d_ksgetzoomscale.html).

Синтаксис:

int ksGetZoomScale (double *x, double *y, double *scale);

Выходные параметры:

x, y | \- координаты (в СК вида) точки центра изменения масштаба,  
---|---  
scale | \- коэффициент изменения масштаба изображения.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
