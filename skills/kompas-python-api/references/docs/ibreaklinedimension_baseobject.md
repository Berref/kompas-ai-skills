# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IBreakLineDimension ](ibreaklinedimension.html) > [IBreakLineDimension - свойства ](ibreaklinedimension_props.html) |  Scroll [ [ [ ](ibreaklinedimension_shelfx.html "К следующему разделу")](ibreaklinedimension_props.html "На уровень выше")](ibreaklinedimension_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreaklinedimension.html)

Тип данных: интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BaseObject = Object.BaseObject | Получить свойство([* ](1.html))  
---|---  
Object.BaseObject = BaseObject | Установить свойство ([* ](1.html))  
BaseObject = Object.GetBaseObject() | Получить свойство ([**](2.html))  
Object.SetBaseObject( BaseObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObject( &BaseObject ) | Получить свойство([* ](1.html))  
---|---  
Object.put_BaseObject( BaseObject ) | Установить свойство ([* ](1.html))  
  
Примечание:

1\. Если при создании размера задать опорный объект, то координаты центра [IBreakLineDimension::X1](ibreaklinedimension_o1.html), [IBreakLineDimension::Y1](ibreaklinedimension_y1.html), [IBreakLineDimension::X2](ibreaklinedimension_x2.html), [IBreakLineDimension::Y2](ibreaklinedimension_y2.html) задавать не нужно. Данные свойства будут получены с исходного объекта.

В качестве опорного объекта может использоваться отрезок.

2\. Чтобы разорвать связь с объектом, нужно установить значение свойства BaseObject, равное NULL.

Подразделы:

(отсутствуют)
