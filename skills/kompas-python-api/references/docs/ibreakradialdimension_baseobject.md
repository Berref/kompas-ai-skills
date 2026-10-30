# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IBreakRadialDimension ](ibreakradialdimension.html) > [IBreakRadialDimension - свойства ](ibreakradialdimension_props.html) |  Scroll [ [ [ ](ibreakradialdimension_breakangle.html "К следующему разделу")](ibreakradialdimension_props.html "На уровень выше")](ibreakradialdimension_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibreakradialdimension.html)

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

Если при создании размера задать опорный объект [IBreakRadialDimension::BaseObject](ibreakradialdimension_baseobject.html), то координаты центра [IBreakRadialDimension::Xc](ibreakradialdimension_xc.html)[IBreakRadialDimension::Yc](ibreakradialdimension_yc.html) и радиус [IBreakRadialDimension::Radius](ibreakradialdimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Чтобы разорвать связь с объектом, нужно установить значение свойства равным NULL.

Подразделы:

(отсутствуют)
