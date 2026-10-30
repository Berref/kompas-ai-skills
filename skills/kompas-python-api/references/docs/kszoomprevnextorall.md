# ksZoomPrevNextOrAll - Показать документ в предыдущем/последующем масштабе или документ целиком

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции управления масштабом ](zoom_fncts_common.html) |  Scroll [ [ [ ](kszoomscale.html "К следующему разделу")](zoom_fncts_common.html "На уровень выше")](kszoom.html "К предыдущему разделу")  
---|---  
  
[Пример...](kszoomprevnextorall_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksZoomPrevNextOrAll](ksdocument2d_kszoomprevnextorall.html).

Синтаксис:

int ksZoomPrevNextOrAll (unsigned char type);

Входной параметр:

type | тип масштабирования: 0 - следующий масштаб, 1 - предыдущий масштаб, 2 - весь документ.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
