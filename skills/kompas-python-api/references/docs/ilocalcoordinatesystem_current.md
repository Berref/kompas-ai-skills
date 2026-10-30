# Current - Состояние ЛСК - текущая/нетекущая

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - свойства ](ilocalcoordinatesystem_props.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_defaultobject.html "К следующему разделу")](ilocalcoordinatesystem_props.html "На уровень выше")](ilocalcoordinatesystem_associationobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Тип данных: BOOL

Синтаксис Automation:

Current = iObject.Current; | Получить свойство ([* ](1.html))  
---|---  
iObject.Current = Current; | Установить свойство ([* ](1.html))  
Current = iObject.GetCurrent(); | Получить свойство ([**](2.html))  
iObject.SetCurrent( Current ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Current( &Current ); | Получить свойство  
---|---  
iObject->put_Current( Current ); | Установить свойство  
  
Примечание:

По умолчанию ЛСК создаётся текущей. Чтобы ЛСК создалась нетекущей, нужно установить свойство iObject.Current = FALSE.

См. также [ILocalCoordinateSystems::SetCurrent](ilocalcoordinatesystems_setcurrent.html).

Подразделы:

(отсутствуют)
