# GetLayerReference - Получить указатель на слой по номеру слоя текущего вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа со слоями ](cm1740643.html) > [Функции работы со слоями ](layers_fncts_common.html) |  Scroll [ [ [ ](layer.html "К следующему разделу")](layers_fncts_common.html "На уровень выше")](getlayernumber.html "К предыдущему разделу")  
---|---  
  
[Пример...](layer_getlayerreference_getlayernumber_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetLayerReference](ksdocument2d_ksgetlayerreference.html).

Синтаксис:

reference GetLayerReference (int number);

Входной параметр:

number | \- номер слоя.  
---|---  
  
Возвращаемое значение:

указатель на слой | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Возврат нулевого значения означает, что слой с таким номером в документе отсутствует.

Подразделы:

(отсутствуют)
