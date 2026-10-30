# InitialObjects - Исходные объекты массива

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Массивы ](bc3321786.html) > [Интерфейс IFeaturePattern ](ifeaturepattern.html) > [IFeaturePattern - свойства ](ifeaturepattern_props.html) |  Scroll [ [ [ ](ifeaturepattern_instancedeletedindexes.html "К следующему разделу")](ifeaturepattern_props.html "На уровень выше")](ifeaturepattern_geometrypattern.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeaturepattern.html)

Тип данных: VARIANT

Синтаксис Automation:

InitialObjects = Object.InitialObjects | Получить свойство ([* ](1.html))  
---|---  
Object.InitialObjects = InitialObjects | Установить свойство ([* ](1.html))  
InitialObjects = Object.GetInitialObjects() | Получить свойство ([**](2.html))  
Object.SetInitialObjects( InitialObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InitialObjects( &InitialObjects ) | Получить свойство  
---|---  
Object.put_InitialObjects( InitialObjects ) | Установить свойство  
  
Примечание:

Если копируется один объект, то возвращается VARIANT с типом VT_DISPATCH.

Если копируется более одного объекта, то возвращается VARIANT с типом VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
