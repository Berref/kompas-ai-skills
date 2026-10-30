# BaseObject1 - Первый опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IAngleDimension ](iangledimension.html) > [IAngleDimension - свойства ](iangledimension_props.html) |  Scroll [ [ [ ](iangledimension_baseobject2.html "К следующему разделу")](iangledimension_props.html "На уровень выше")](iangledimension_angle2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimension.html)

Тип данных: интерфейс [IDrawingObject](idrawingobject.html)

Синтаксис Automation:

BaseObject1 = Object.BaseObject1 | Получить свойство([* ](1.html))  
---|---  
Object.BaseObject1 = BaseObject1 | Установить свойство ([* ](1.html))  
BaseObject1 = Object.GetBaseObject1() | Получить свойство ([**](2.html))  
Object.SetBaseObject1( BaseObject1 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObject1( &BaseObject1 ) | Получить свойство([* ](1.html))  
---|---  
Object.put_BaseObject1( BaseObject1 ) | Установить свойство ([* ](1.html))  
  
Примечание:

Если при создании размера задать опорные объекты [IAngleDimension::BaseObject1](iangledimension_baseobject1.html), [IAngleDimension::BaseObject2](iangledimension_baseobject2.html), то координаты центра [IAngleDimension::Xc](iangledimension_xc.html), [IAngleDimension::Yc](iangledimension_yc.html), радиус [IAngleDimension::Radius](iangledimension_radius.html), [IAngleDimension::X1](iangledimension_x1.html), [IAngleDimension::Y1](iangledimension_y1.html), [IAngleDimension::X2](iangledimension_x2.html), [IAngleDimension::Y2](iangledimension_y2.html), задавать не нужно. Данные свойства будут получены с опорного объекта.

В качестве базовых объектов могут использоваться отрезки.

Чтобы разорвать связь с объектом, нужно установить значение свойства равным NULL.

Подразделы:

(отсутствуют)
