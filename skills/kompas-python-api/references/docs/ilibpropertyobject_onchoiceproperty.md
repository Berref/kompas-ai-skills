# OnChoiceProperty - Событие запуска внешнего редактирования для пользовательского свойства

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Внешние воздействия на библиотечный элемент ](cm1819576.html) > [Интерфейс ILibPropertyObject ](ilibpropertyobject.html) > [ILibPropertyObject - методы ](ilibpropertyobject_methods.html) |  Scroll [ [ [ ](ilibpropertyobject_updateproperty.html "К следующему разделу")](ilibpropertyobject_methods.html "На уровень выше")](ilibpropertyobject_getproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibpropertyobject.html)

Синтаксис COM:

BOOL OnChoiceProperty( PropertyParam * param );

Входные и выходные параметры:

param | \- cтруктура параметров свойства [PropertyParam](propertyparam.html),  
---|---  
  
Возвращаемое значение:

TRUE | \- значение изменилось,  
---|---  
FALSE | \- значение не изменилось.  
  
Примечание:

1\. Идентификация свойства осуществляется по параметру propertyId в [PropertyParam](propertyparam.html).

2\. Событие вызывается для свойств с типом ksOPControlExternalEdit и ksOPControlExternalStringEdit из перечисления [ksObjectPropertyControlTypeEnum.](ksobjectpropertycontroltypeenum.html)

Подразделы:

(отсутствуют)
