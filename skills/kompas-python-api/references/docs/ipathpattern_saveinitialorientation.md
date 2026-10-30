# SaveInitialOrientation - Ориентация экземпляров массива

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) > [Интерфейс IPathPattern ](ipathpattern.html) > [IPathPattern - свойства ](ipathpattern_props.html) |  Scroll [ [ [ ](ipathpattern_startingpoint.html "К следующему разделу")](ipathpattern_props.html "На уровень выше")](ipathpattern_reversedirection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipathpattern.html)

Тип данных: BOOL

Синтаксис Automation:

SaveInitialOrientation = Object.SaveInitialOrientation | Получить свойство ([* ](1.html))  
---|---  
Object.SaveInitialOrientation = SaveInitialOrientation | Установить свойство ([* ](1.html))  
SaveInitialOrientation = Object.GetSaveInitialOrientation() | Получить свойство ([**](2.html))  
Object.SetSaveInitialOrientation( SaveInitialOrientation ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SaveInitialOrientation( &SaveInitialOrientation ) | Получить свойство  
---|---  
Object.put_SaveInitialOrientation( SaveInitialOrientation ) | Установить свойство  
  
Значения свойства:

TRUE | \- сохранять исходную ориентацию,  
---|---  
FALSE | \- доворачивать до нормали к траектории.  
  
Подразделы:

(отсутствуют)
