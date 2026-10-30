# SemiAxisAutoLength - TRUE - ассоциативное задание длины полуоси

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ICircularCentres ](icircularcentres.html) > [ICircularCentres - cвойства ](icircularcentres_props.html) |  Scroll [ [ [ ](icircularcentres_semiaxislength.html "К следующему разделу")](icircularcentres_props.html "На уровень выше")](icircularcentres_radiuses.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icircularcentres.html)

Тип данных: BOOL

Синтаксис Automation:

SemiAxisAutoLength = Object.SemiAxisAutoLength( WithCenter, Index, AxisType ) | Получить свойство([* ](1.html))  
---|---  
Object.SemiAxisAutoLength( WithCenter, Index, AxisType ) = SemiAxisAutoLength | Установить свойство ([* ](1.html))  
SemiAxisAutoLength = Object.GetSemiAxisAutoLength( WithCenter, Index, AxisType ) | Получить свойство ([**](2.html))  
Object.SetSemiAxisAutoLength( WithCenter, Index, AxisType, SemiAxisAutoLength ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SemiAxisAutoLength( WithCenter, Index, AxisType, &SemiAxisAutoLength ) | Получить свойство  
---|---  
Object.put_SemiAxisAutoLength( WithCenter, Index, AxisType, SemiAxisAutoLength ) | Установить свойство  
  
Входные параметры:

BOOL | WithCenter - TRUE, устанавливать параметры центрального обозначения.  
---|---  
long | Index - индекс оси.  
[ksSemiAxisTypeEnum](kssemiaxistypeenum.html) | AxisType - индекс полуоси.  
  
Подразделы:

(отсутствуют)
