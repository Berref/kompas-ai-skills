# Layer - Сделать слой текущим

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа со слоями ](cm1740643.html) > [Функции работы со слоями ](layers_fncts_common.html) |  Scroll [ [ [ ](cm1826821.html "К следующему разделу")](layers_fncts_common.html "На уровень выше")](getlayerreference.html "К предыдущему разделу")  
---|---  
  
[Пример...](layer_getlayerreference_getlayernumber_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksLayer](ksdocument2d_kslayer.html).

Синтаксис:

reference Layer (int n);

Входной параметр:

n | \- номер слоя.  
---|---  
  
Возвращаемое значение:

указатель на слой | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если слоя с заданным номером нет, он создается.

Подразделы:

(отсутствуют)
