# Curves2 - Вторая цепочка кривых (вторая направляющая линейчатой поверхности) SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - свойства ](iruledsurface_props.html) |  Scroll [ [ [ ](iruledsurface_edgescount.html "К следующему разделу")](iruledsurface_props.html "На уровень выше")](iruledsurface_curves1.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedsurface.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Curves2 = Object.Curves2 | Получить свойство ([* ](1.html))  
---|---  
Object.Curves2 = Curves2 | Установить свойство ([* ](1.html))  
Curves2 = Object.GetCurves2() | Получить свойство ([**](2.html))  
Object.SetCurves2( Curves2 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Curves2( &Curves2 ) | Получить свойство  
---|---  
Object.put_Curves2( Curves2 ) | Установить свойство  
  
Свойство позволяет устанавливать и получать первую направляющую.

Примечание:

Направляющей может являться:

•пространственная кривая;

•цепочка последовательно соединяющихся пространственных кривых;

•точечный объект.

Подразделы:

(отсутствуют)
