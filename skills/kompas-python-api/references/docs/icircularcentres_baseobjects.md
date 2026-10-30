# BaseObjects - Объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ICircularCentres ](icircularcentres.html) > [ICircularCentres - cвойства ](icircularcentres_props.html) |  Scroll [ [ [ ](icircularcentres_centres.html "К следующему разделу")](icircularcentres_props.html "На уровень выше")](icircularcentres_axisescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icircularcentres.html)

Тип данных: VARIANT

Синтаксис Automation:

BaseObjects = Object.BaseObjects | Получить свойство([* ](1.html))  
---|---  
Object.BaseObjects = BaseObjects | Установить свойство ([* ](1.html))  
BaseObjects = Object.GetBaseObjects() | Получить свойство ([**](2.html))  
Object.SetBaseObjects( BaseObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseObjects( &BaseObjects ) | Получить свойство  
---|---  
Object.put_BaseObjects( BaseObjects ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать опорный объект или массив опорных объектов.

Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
