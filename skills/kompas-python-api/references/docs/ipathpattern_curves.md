# Curves - Массив кривых - траектория копирования

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) > [Интерфейс IPathPattern ](ipathpattern.html) > [IPathPattern - свойства ](ipathpattern_props.html) |  Scroll [ [ [ ](ipathpattern_reversedirection.html "К следующему разделу")](ipathpattern_props.html "На уровень выше")](ipathpattern_count.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipathpattern.html)

Тип данных: VARIANT

Синтаксис Automation:

Curves = Object.Curves | Получить свойство ([* ](1.html))  
---|---  
Object.Curves = Curves | Установить свойство ([* ](1.html))  
Curves = Object.GetCurves() | Получить свойство ([**](2.html))  
Object.SetCurves( Curves ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Curves( &Curves ) | Получить свойство  
---|---  
Object.get_Curves( &Curves ) | Установить свойство  
  
Примечание:

Если используется одна кривая, то тип VARIANT-а VT_DISPATCH.

Если используется несколько кривых, то тип VARIANT-а VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
