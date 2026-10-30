# GetLayerNumber - Получить номер слоя

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа со слоями ](cm1740643.html) > [Функции работы со слоями ](layers_fncts_common.html) |  Scroll [ [ [ ](getlayerreference.html "К следующему разделу")](layers_fncts_common.html "На уровень выше")](changeobjectlayer.html "К предыдущему разделу")  
---|---  
  
[Пример...](layer_getlayerreference_getlayernumber_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetLayerNumber](ksdocument2d_ksgetlayernumber.html).

Синтаксис:

int GetLayerNumber (reference p);

Входной параметр:

p | \- указатель на слой.  
---|---  
  
Возвращаемое значение:

номер слоя | \- в случае удачного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Примечания:

1\. Системный слой имеет номер 0.

2\. Если p - объект слоя, возвращается номер слоя этого объекта.

3\. Если p = 0, то возвращается номер текущего слоя.

Подразделы:

(отсутствуют)
