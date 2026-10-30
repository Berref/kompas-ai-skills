# SemiAxisLength - Длина полуоси

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ICircularCentres ](icircularcentres.html) > [ICircularCentres - cвойства ](icircularcentres_props.html) |  Scroll [ [ [ ](icircularcentres_x0.html "К следующему разделу")](icircularcentres_props.html "На уровень выше")](icircularcentres_semiaxisautolength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icircularcentres.html)

Тип данных: double

Синтаксис Automation:

SemiAxisLength = Object.SemiAxisLength( WithCenter, Index, AxisType ) | Получить свойство([* ](1.html))  
---|---  
Object.SemiAxisLength( WithCenter, Index, AxisType ) = SemiAxisLength | Установить свойство ([* ](1.html))  
SemiAxisLength = Object.GetSemiAxisLength( WithCenter, Index, AxisType ) | Получить свойство ([**](2.html))  
Object.SetSemiAxisLength( WithCenter, Index, AxisType, SemiAxisLength ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SemiAxisLength( WithCenter, Index, AxisType, &SemiAxisLength ) | Получить свойство  
---|---  
Object.put_SemiAxisLength( WithCenter, Index, AxisType, SemiAxisLength ) | Установить свойство  
  
Входные параметры:

BOOL | WithCenter - TRUE, устанавливать параметры центрального обозначения.  
---|---  
long | Index - индекс оси.  
[ksSemiAxisTypeEnum](kssemiaxistypeenum.html) | AxisType - индекс полуоси.  
  
Подразделы:

(отсутствуют)
