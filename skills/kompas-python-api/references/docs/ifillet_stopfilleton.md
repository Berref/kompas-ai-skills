# StopFilletOn - Использовать точку останова скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_tangent.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_stopfilletoffsetmode.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: BOOL

Синтаксис Automation:

StopFilletOn = Object.StopFilletOn( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopFilletOn( First ) = StopFilletOn | Установить свойство ([* ](1.html))  
StopFilletOn = Object.GetStopFilletOn( First ) | Получить свойство ([**](2.html))  
Object.SetStopFilletOn( First, StopFilletOn ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopFilletOn( First, &StopFilletOn ) | Получить свойство  
---|---  
Object.put_StopFilletOn( First, StopFilletOn ) | Установить свойство  
  
Входные параметры:

BOOL First - TRUE | \- начальная точка останова,  
---|---  
FALSE | \- конечная точка останова.  
  
Подразделы:

(отсутствуют)
