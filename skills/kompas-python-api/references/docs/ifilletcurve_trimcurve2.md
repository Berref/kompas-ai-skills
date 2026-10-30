# TrimCurve2 - Усекать кривую 2

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IFilletCurve ](ifilletcurve.html) > [IFilletCurve - свойства ](ifilletcurve_props.html) |  Scroll [ [ [ ](ifilletcurve_methods.html "К следующему разделу")](ifilletcurve_props.html "На уровень выше")](ifilletcurve_trimcurve1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifilletcurve.html)

Тип данных: BOOL

Синтаксис Automation:

TrimCurve2 = Object.TrimCurve2 | Получить свойство ([* ](1.html))  
---|---  
Object.TrimCurve2 = TrimCurve2 | Установить свойство ([* ](1.html))  
TrimCurve2 = Object.GetTrimCurve2() | Получить свойство ([**](2.html))  
Object.SetTrimCurve2( TrimCurve2 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_TrimCurve2( &TrimCurve2 ) | Получить свойство  
---|---  
Object.put_TrimCurve2( TrimCurve2 ) | Установить свойство  
  
Свойство позволяет устанавливать и получать признак усечения второй кривой. Если усечение включено, для исходной кривой создается копия, усеченная в точке ее касания с кривой скругления; если отключено, то создается только кривая скругления.

Подразделы:

(отсутствуют)
