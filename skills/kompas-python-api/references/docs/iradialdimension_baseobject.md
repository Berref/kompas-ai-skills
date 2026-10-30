# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IRadialDimension ](iradialdimension.html) > [IRadialDimension - свойства ](iradialdimension_props.html) |  Scroll [ [ [ ](iradialdimension_branchbegin.html "К следующему разделу")](iradialdimension_props.html "На уровень выше")](iradialdimension_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iradialdimension.html)

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

Если при создании размера задать опорный объект [IRadialDimension::BaseObject](iradialdimension_baseobject.html), то координаты центра [IRadialDimension::Xc](iradialdimension_xc.html)[IRadialDimension::Yc](iradialdimension_yc.html) и радиус [IRadialDimension::Radius](iradialdimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Чтобы разорвать связь с объектом, нужно установить значение свойства равным NULL.

Подразделы:

(отсутствуют)
