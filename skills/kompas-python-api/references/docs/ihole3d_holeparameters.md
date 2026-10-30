# HoleParameters - Параметры отверстия

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IHole3D ](ihole3d.html) > [IHole3D - свойства ](ihole3d_propers.html) |  Scroll [ [ [ ](ihole3d_showthread.html "К следующему разделу")](ihole3d_propers.html "На уровень выше")](ihole3d_holetype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ihole3d.html)

Тип данных: Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

HoleParameters = Object.HoleParameters | Получить свойство ([* ](1.html))  
---|---  
THoleParameters = Object.GetHoleParameters() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_HoleParameters( &HoleParameters ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения.

В зависимости от типа отверстия возвращаются интерфейсы

•ksHTCounterbore - [ISpotfacingHoleParameters](ispotfacingholeparameters.html)

•ksHTCountersinking - [ICountersinkHoleParameters](icountersinkholeparameters.html)

•ksHTCounterdrill - [ICountersinkSpotfacingHoleParameters](icountersinkspotfacingholeparameters.html)

•ksHTConic - [IConicHoleParameters](iconicholeparameters.html)

•ksHTLfrLibrary - [ILibraryHoleParameters](ilibraryholeparameters.html)

Подразделы:

(отсутствуют)
