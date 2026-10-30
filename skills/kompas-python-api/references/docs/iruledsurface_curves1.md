# Curves1 - Первая цепочка кривых (первая направляющая линейчатой поверхности) в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - свойства ](iruledsurface_props.html) |  Scroll [ [ [ ](iruledsurface_curves2.html "К следующему разделу")](iruledsurface_props.html "На уровень выше")](iruledsurface_considercompliancevertices.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedsurface.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

Curves1 = Object.Curves1 | Получить свойство ([* ](1.html))  
---|---  
Object.Curves1 = Curves1 | Установить свойство ([* ](1.html))  
Curves1 = Object.GetCurves1() | Получить свойство ([**](2.html))  
Object.SetCurves1( Curves1 ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Curves1( &Curves1 ) | Получить свойство  
---|---  
Object.put_Curves1( Curves1 ) | Установить свойство  
  
Свойство позволяет устанавливать и получать первую направляющую.

Примечание:

Направляющей может являться:

•пространственная кривая;

•цепочка последовательно соединяющихся пространственных кривых;

•точечный объект.

Подразделы:

(отсутствуют)
