# SaveInitialObjects - Признак того, что исходные объекты остаются (не удаляются)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) > [Интерфейс IMirrorPattern ](imirrorpattern.html) > [IMirrorPattern - свойства ](imirrorpattern_props.html) |  Scroll [ [ [ ](ipointdrivenpattern.html "К следующему разделу")](imirrorpattern_props.html "На уровень выше")](imirrorpattern_plane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imirrorpattern.html)

Тип данных: BOOL

Синтаксис Automation:

SaveInitialObjects = Object.SaveInitialObjects | Получить свойство ([* ](1.html))  
---|---  
Object.SaveInitialObjects = SaveInitialObjects | Установить свойство ([* ](1.html))  
SaveInitialObjects = Object.GetSaveInitialObjects() | Получить свойство ([**](2.html))  
Object.SetSaveInitialObjects( SaveInitialObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SaveInitialObjects( &SaveInitialObjects ) | Получить свойство  
---|---  
Object.put_SaveInitialObjects( SaveInitialObjects ) | Установить свойство  
  
Значение свойства:

TRUE | \- оставлять исходные объекты.  
---|---  
  
Примечание:

1\. Свойство работает только для o3d_mirrorAllOperation.

2\. У других операций зеркального копирования возможность скрыть экземпляры отсутствует.

Подразделы:

(отсутствуют)
