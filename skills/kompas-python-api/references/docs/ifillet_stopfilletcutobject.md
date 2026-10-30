# StopFilletCutObject - Секущий объект для точки останова скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_stopfilletcutpointindex.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_stopfilletcutbyobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: Указатель на интерфейс [IModelObject](imodelobject.html).

Синтаксис Automation:

StopFilletCutObject = Object.StopFilletCutObject( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopFilletCutObject( First ) = StopFilletCutObject | Установить свойство ([* ](1.html))  
StopFilletCutObject = Object.GetStopFilletCutObject( First ) | Получить свойство ([**](2.html))  
Object.SetStopFilletCutObject( First, StopFilletCutObject ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopFilletCutObject( First, &StopFilletCutObject ) | Получить свойство  
---|---  
Object.put_StopFilletCutObject( First, StopFilletCutObject ) | Установить свойство  
  
Входные параметры:

BOOL First - TRUE | \- начальная точка останова,  
---|---  
FALSE | \- конечная точка останова.  
  
Подразделы:

(отсутствуют)
