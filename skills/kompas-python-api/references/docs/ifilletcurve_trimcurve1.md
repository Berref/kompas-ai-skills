# TrimCurve1 - Усекать кривую 1

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IFilletCurve ](ifilletcurve.html) > [IFilletCurve - свойства ](ifilletcurve_props.html) |  Scroll [ [ [ ](ifilletcurve_trimcurve2.html "К следующему разделу")](ifilletcurve_props.html "На уровень выше")](ifilletcurve_radius.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifilletcurve.html)

Тип данных: BOOL

Синтаксис Automation:

TrimCurve1 = Object.TrimCurve1 | Получить свойство ([* ](1.html))  
---|---  
Object.TrimCurve1 = TrimCurve1 | Установить свойство ([* ](1.html))  
TrimCurve1 = Object.GetTrimCurve1() | Получить свойство ([**](2.html))  
Object.SetTrimCurve1( TrimCurve1 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TrimCurve1( &TrimCurve1 ) | Получить свойство  
---|---  
Object.put_TrimCurve1( TrimCurve1 ) | Установить свойство  
  
Свойство позволяет устанавливать и получать признак усечения первой кривой. Если усечение включено, для исходной кривой создается копия, усеченная в точке ее касания с кривой скругления; если отключено, то создается только кривая скругления.

Подразделы:

(отсутствуют)
