# LocalCS - Локальная система координат

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вектор ](bc2295802.html) > [Интерфейс IVector3DBy2AnglesParameters ](ivector3dby2anglesparameters.html) > [IVector3DBy2AnglesParameters - свойства ](ivector3dby2anglesparameters_props.html) |  Scroll [ [ [ ](ivector3dby2vertexesparameters.html "К следующему разделу")](ivector3dby2anglesparameters_props.html "На уровень выше")](ivector3dby2anglesparameters_angleb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ivector3dby2anglesparameters.html)

Тип данных: указатель на интерфейс [ILocalCoordinateSystem](ilocalcoordinatesystem.html)

Синтаксис Automation:

LocalCS = Object.LocalCS | Получить свойство ([* ](1.html))  
---|---  
Object.LocalCS = LocalCS | Установить свойство ([* ](1.html))  
LocalCS = Object.GetLocalCS() | Получить свойство ([**](2.html))  
Object.SetLocalCS( LocalCS ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LocalCS( &LocalCS ) | Получить свойство  
---|---  
Object.put_LocalCS( LocalCS ) | Установить свойство  
  
Свойство позволяет устанавливать и получать локальную систему координат.

Примечание:

Чтобы установить глобальную СК, нужно передать NULL.

Подразделы:

(отсутствуют)
