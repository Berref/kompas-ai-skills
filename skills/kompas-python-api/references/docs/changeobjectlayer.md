# ChangeObjectLayer - Изменить слой объекта

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа со слоями ](cm1740643.html) > [Функции работы со слоями ](layers_fncts_common.html) |  Scroll [ [ [ ](getlayernumber.html "К следующему разделу")](layers_fncts_common.html "На уровень выше")](layers_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](changeobjectlayer_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksChangeObjectLayer](ksdocument2d_kschangeobjectlayer.html).

Синтаксис:

int ChangeObjectLayer (reference obj, int number);

Входные параметры:

obj | \- указатель на объект,  
---|---  
number | \- номер слоя, на который переносится объект.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Слой, на который переносится объект, должен существовать и быть доступным для редактирования (не фоновым и не выключенным).

Подразделы:

(отсутствуют)
