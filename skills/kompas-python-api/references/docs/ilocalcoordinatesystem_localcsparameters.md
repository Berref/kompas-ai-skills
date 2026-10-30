# LocalCSParameters - Интерфейс параметров ЛСК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - свойства ](ilocalcoordinatesystem_props.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_modelobjecttype.html "К следующему разделу")](ilocalcoordinatesystem_props.html "На уровень выше")](ilocalcoordinatesystem_hidden.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Тип данных: указатель на интерфейс объекта [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

LocalCSParameters = iObject.LocalCSParameters; | Получить свойство ([* ](1.html))  
---|---  
LocalCSParameters = iObject.GetLocalCSParameters(); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_LocalCSParameters( &LocalCSParameters ); | Получить свойство  
---|---  
  
Примечание:

В зависимости от типа [ILocalCoordinateSystem::OrientationType](ilocalcoordinatesystem_orientationtype.html) интерфейс параметров должен приводиться к следующим вариантам:

•ksAxisOrientation - [ILocalCSAxesDirectionParam](ilocalcsaxesdirectionparam.html) – Интерфейс параметров ЛСК для типа ориентации "Направление осей",

•ksEulerCorners - [ILocalCSEulerParam](ilocalcseulerparam.html) – Интерфейс параметров ЛСК для типа ориентации "Система углов Эйлера",

•ksOrientByObject - [ILocalCSOrientByObjectParam](ilocalcsorientbyobjectparam.html) – Интерфейс параметров ЛСК для типа ориентации "По объекту".

Подразделы:

(отсутствуют)
