# ProjectionPoints - Признак проецирования управляющих точек эскиза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - методы ](ifeaturepattern_methods.html) > [Интерфейс IPointDrivenPattern ](ipointdrivenpattern.html) > [IPointDrivenPattern - свойства ](ipointdrivenpattern_props.html) |  Scroll [ [ [ ](ipointdrivenpattern_saveinitialorientation.html "К следующему разделу")](ipointdrivenpattern_props.html "На уровень выше")](ipointdrivenpattern_orientationtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipointdrivenpattern.html)

Тип данных: BOOL

Синтаксис Automation:

ProjectionPoints = Object.ProjectionPoints | Получить свойство ([* ](1.html))  
---|---  
Object.ProjectionPoints = ProjectionPoints | Установить свойство ([* ](1.html))  
ProjectionPoints = Object.GetProjectionPoints() | Получить свойство ([**](2.html))  
Object.SetProjectionPoints( ProjectionPoints ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ProjectionPoints( &ProjectionPoints ) | Получить признак проецирования  
---|---  
Object.put_ProjectionPoints( ProjectionPoints ) | Установить признак проецирования  
  
Значения свойства:

TRUE | \- проецировать точки,  
---|---  
FALSE | \- не проецировать точки.  
  
Позволяет получать признак проецирования управляющих точек эскиза на плоскость, параллельную плоскости эскиза и проходящую через базовую точку.

Подразделы:

(отсутствуют)
