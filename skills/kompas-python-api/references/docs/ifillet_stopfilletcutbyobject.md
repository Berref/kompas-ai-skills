# StopFilletCutByObject - Усекать по объекту (При секущей) для точки останова скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_stopfilletcutobject.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_smoothcorner.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: BOOL

Синтаксис Automation:

StopFilletCutByObject = Object.StopFilletCutByObject( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopFilletCutByObject( First ) = StopFilletCutByObject | Установить свойство ([* ](1.html))  
StopFilletCutByObject = Object.GetStopFilletCutByObject( First ) | Получить свойство ([**](2.html))  
Object.SetStopFilletCutByObject( First, StopFilletCutByObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopFilletCutByObject( First, &StopFilletCutByObject ) | Получить свойство  
---|---  
Object.put_StopFilletCutByObject( First, StopFilletCutByObject ) | Установить свойство  
  
Входные параметры:

BOOL First - TRUE | \- начальная точка останова,  
---|---  
FALSE | \- конечная точка останова.  
  
Подразделы:

(отсутствуют)
