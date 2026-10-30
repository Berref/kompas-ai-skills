# LibHotPnt_GetEx - Получить текущее описание характерной точки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Работа с характерными точками ](cm1878328.html) > [Интерфейс ILibHPObject1 ](ilibhpobject1.html) > [ILibHPObject1 - методы ](ilibhpobject1_methods.html) |  Scroll [ [ [ ](ilibhpobject1_libhotpnt_getcursortextex.html "К следующему разделу")](ilibhpobject1_methods.html "На уровень выше")](ilibhpobject1_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibhpobject1.html)

Синтаксис COM:

BOOL LibHotPnt_GetEx(HotPointDescription1* point, int index);

Входной параметр:

index | \- номер характерной точки.  
---|---  
  
Выходной параметр:

point | \- структура параметров характерной точки [HotPointDescription1](structhotpointdescription1.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод вызывается в цикле для каждой точки (увеличивая номер точки), пока не вернет FALSE.

2\. Значения координат характерной точки необходимо устанавливать в собственной системе координат объекта.

Подразделы:

(отсутствуют)
