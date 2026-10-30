# StopFilletOffsetMode - Способ расчета смещения для точки останова скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_stopfilleton.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_stopfilletoffset.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: Значение из перечисления [ksFilletOffsetModeEnum](ksfilletoffsetmodeenum.html).

Синтаксис Automation:

StopFilletOffsetMode = Object.StopFilletOffsetMode( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopFilletOffsetMode( First ) = StopFilletOffsetMode | Установить свойство ([* ](1.html))  
StopFilletOffsetMode = Object.GetStopFilletOffsetMode( First ) | Получить свойство ([**](2.html))  
Object.SetStopFilletOffsetMode( First, StopFilletOffsetMode ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopFilletOffsetMode( First, &StopFilletOffsetMode ) | Получить свойство  
---|---  
Object.put_StopFilletOffsetMode( First, StopFilletOffsetMode ) | Установить свойство  
  
Входные параметры:

BOOL First - TRUE | \- начальная точка останова,  
---|---  
FALSE | \- конечная точка останова.  
  
Подразделы:

(отсутствуют)
