# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IDiametralDimension ](idiametraldimension.html) > [IDiametralDimension - свойства ](idiametraldimension_props.html) |  Scroll [ [ [ ](idiametraldimension_dimensiontype.html "К следующему разделу")](idiametraldimension_props.html "На уровень выше")](idiametraldimension_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idiametraldimension.html)

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

Если при создании размера задать опорный объект [IDiametralDimension::BaseObject](idiametraldimension_baseobject.html), то координаты центра [IDiametralDimension::Xc,](idiametraldimension_xc.html)[IDiametralDimension::Yc](idiametraldimension_yc.html) и радиус [IDiametralDimension::Radius](idiametraldimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Чтобы разорвать связь с объектом, нужно установить значение свойства равным NULL.

Подразделы:

(отсутствуют)
