# BaseObject - Опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IArcDimension ](iarcdimension.html) > [IArcDimension - свойства ](iarcdimension_props.html) |  Scroll [ [ [ ](iarcdimension_dimensiontype.html "К следующему разделу")](iarcdimension_props.html "На уровень выше")](iarcdimension_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcdimension.html)

Тип данных: указатель на интерфейс [IDrawingObject](idrawingobject.html)

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

Если при создании размера задать опорный объект [IArcDimension::BaseObject](iarcdimension_baseobject.html), то значения свойств [IArcDimension::Xc](iarcdimension_xc.html), [IArcDimension::Yc](iarcdimension_yc.html), [IArcDimension::X1](iarcdimension_x1.html), [IArcDimension::Y1](iarcdimension_y1.html), [IArcDimension::X2](iarcdimension_x2.html), [IArcDimension::Y2](iarcdimension_y2.html), [IArcDimension::Direction](iarcdimension_direction.html) задавать не нужно. Данные свойства будут получены с исходных объектов. В качестве базового объекта может использоваться дуга окружности.

Чтобы разорвать связь с объектом, нужно установить значение свойства, равное NULL.

Подразделы:

(отсутствуют)
