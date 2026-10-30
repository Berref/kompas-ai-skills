# StopChamferOffsetMode - Способ расчета смещения для точки останова фаски

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IChamfer ](ichamfer.html) > [IChamfer - свойства ](ichamfer_propers.html) |  Scroll [ [ [ ](ichamfer_stopchamferon.html "К следующему разделу")](ichamfer_propers.html "На уровень выше")](ichamfer_stopchamferoffset.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichamfer.html)

Тип данных: из перечисления [ksFilletOffsetModeEnum](ksfilletoffsetmodeenum.html)

Синтаксис Automation:

StopChamferOffsetMode = Object.StopChamferOffsetMode( First ) | Получить свойство ([* ](1.html))  
---|---  
Object.StopChamferOffsetMode( First ) = StopChamferOffsetMode | Установить свойство ([* ](1.html))  
StopChamferOffsetMode = Object.GetStopChamferOffsetMode( First ) | Получить свойство ([**](2.html))  
Object.SetStopChamferOffsetMode( First, StopChamferOffsetMode ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StopChamferOffsetMode( First, &StopChamferOffsetMode ) | Получить свойство  
---|---  
Object.put_StopChamferOffsetMode( First, StopChamferOffsetMode ) | Установить свойство  
  
Входные параметры

BOOL | First - TRUE - для первой стороны, FALSE - для второй стороны.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
