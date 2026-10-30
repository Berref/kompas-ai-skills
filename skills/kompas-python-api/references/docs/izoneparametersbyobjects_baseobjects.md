# BaseObjects - Объекты

[API интерфейсов. Версия 7](applicate.html) > [Сервисные функции ](service.html) > [Зоны ](cu1735335.html) > [Интерфейс IZoneParametersByObjects ](izoneparametersbyobjects.html) > [IZoneParametersByObjects - свойства ](izoneparametersbyobjects_props.html) |  Scroll [ [ [ ](izonedivisionparametersregular.html "К следующему разделу")](izoneparametersbyobjects_props.html "На уровень выше")](izoneparametersbyobjects_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](izoneparametersbyobjects.html)

Тип данных: VARIANT

Синтаксис Automation:

BaseObjects = Object.BaseObjects | Получить свойство ([* ](1.html))  
---|---  
Object.BaseObjects = BaseObjects | Установить свойство ([* ](1.html))  
BaseObjects = Object.GetBaseObjects() | Получить свойство ([**](2.html))  
Object.SetBaseObjects( BaseObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObjects( &BaseObjects ) | Получить свойство  
---|---  
Object.put_BaseObjects( BaseObjects ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать опорный объект или массив опорных объектов по которым определяется суммарный габарит зоны.

Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
