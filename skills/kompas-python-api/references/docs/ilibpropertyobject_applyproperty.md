# ApplyProperty - Установить новое значение для свойства

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Внешние воздействия на библиотечный элемент ](cm1819576.html) > [Интерфейс ILibPropertyObject ](ilibpropertyobject.html) > [ILibPropertyObject - методы ](ilibpropertyobject_methods.html) |  Scroll [ [ [ ](ilibpropertyobject_endeditproperty.html "К следующему разделу")](ilibpropertyobject_methods.html "На уровень выше")](ilibpropertyobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibpropertyobject.html)

Синтаксис COM:

int ApplyProperty( PropertyParam * param );

Входные и выходные параметры:

param | \- cтруктура параметров свойства [PropertyParam](propertyparam.html),  
---|---  
  
Возвращаемое значение:

1 | \- новое значение свойства установлено,  
---|---  
0 | \- новое значение не установлено.  
  
Примечание:

Идентификация свойства осуществляется по параметру propertyId в [PropertyParam](propertyparam.html).

Подразделы:

(отсутствуют)
