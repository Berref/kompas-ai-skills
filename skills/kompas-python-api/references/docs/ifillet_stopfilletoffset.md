# StopFilletOffset - Величина смещения для точки останова скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_stopfilletoffsetmode.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_stopfilletdirection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: double

Синтаксис Automation:

StopFilletOffset = Object.StopFilletOffset( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopFilletOffset( First ) = StopFilletOffset | Установить свойство ([* ](1.html))  
StopFilletOffset = Object.GetStopFilletOffset( First ) | Получить свойство ([**](2.html))  
Object.SetStopFilletOffset( First, StopFilletOffset ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopFilletOffset( First, &StopFilletOffset ) | Получить свойство  
---|---  
Object.put_StopFilletOffset( First, StopFilletOffset ) | Установить свойство  
  
Входные параметры:

BOOL First - TRUE | \- начальная точка останова,  
---|---  
FALSE | \- конечная точка останова.  
  
Подразделы:

(отсутствуют)
