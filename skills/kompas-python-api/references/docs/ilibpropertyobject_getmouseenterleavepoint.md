# GetMouseEnterLeavePoint - Запрос параметров точек для визуального определения места применения параметра

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Работа с макроэлементами и библиотечными макроэлементами ](cm1919792.html) > [Внешние воздействия на библиотечный элемент ](cm1819576.html) > [Интерфейс ILibPropertyObject ](ilibpropertyobject.html) > [ILibPropertyObject - методы ](ilibpropertyobject_methods.html) |  Scroll [ [ [ ](ilibpropertyobject_getproperty.html "К следующему разделу")](ilibpropertyobject_methods.html "На уровень выше")](ilibpropertyobject_getgroupname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibpropertyobject.html)

Синтаксис:

BOOL GetMouseEnterLeavePoint( int propertyId, long pointIndex, LPUNKNOWN parameters );

Входные параметры:

propertyId | \- идентификатор свойства,  
---|---  
pointIndex | \- индекс точки,  
parameters | \- интерфейс параметров отображения точки [IMouseEnterLeaveParameters](imouseenterleaveparameters.html).  
  
Примечание:

Функция вызывается при наведении на редактор свойства, если установлен признак [PropertyParam](propertyparam.html) needMouseEnterLeaveMessage.

Функция позволяет подсветить в чертеже одну или несколько точек применения контрола.

Функция вызывается в цикле с увеличением индекса точки pointIndex пока библиотека не вернет FALSE, как признак завершения получения параметров точек.

Подразделы:

(отсутствуют)
