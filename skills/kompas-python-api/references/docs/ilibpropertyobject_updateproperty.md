# UpdateProperty - Обновить параметры свойства

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Внешние воздействия на библиотечный элемент ](cm1819576.html) > [Интерфейс ILibPropertyObject ](ilibpropertyobject.html) > [ILibPropertyObject - методы ](ilibpropertyobject_methods.html) |  Scroll [ [ [ ](cm1878328.html "К следующему разделу")](ilibpropertyobject_methods.html "На уровень выше")](ilibpropertyobject_onchoiceproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibpropertyobject.html)

Синтаксис COM:

BOOL UpdateProperty( PropertyParam * param );

Входные и выходные параметры:

param | \- cтруктура параметров свойства [PropertyParam](propertyparam.html),  
---|---  
  
Возвращаемое значение:

TRUE | \- если параметры свойства обновились,  
---|---  
FALSE | \- если параметры свойства не изменились.  
  
Примечание:

1\. Идентификация свойства осуществляется по параметру propertyId в [PropertyParam](propertyparam.html).

2\. При выделении нескольких макроэлементов отображаемый в окне "Свойства" список значений будет сформирован с учетом значения флага PropertyParam:

summList - // TRUE - объединять списки, FALSE - пересекать списки.

Подразделы:

(отсутствуют)
