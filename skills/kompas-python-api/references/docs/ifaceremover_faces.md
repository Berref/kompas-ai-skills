# Faces - Массив граней в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IFaceRemover ](ifaceremover.html) > [IFaceRemover - свойства ](ifaceremover_props.html) |  Scroll [ [ [ ](ifaceremover_savebody.html "К следующему разделу")](ifaceremover_props.html "На уровень выше")](ifaceremover_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifaceremover.html)

Тип данных: VARIANT

Синтаксис Automation:

Faces = Object.Faces | Получить свойство ([* ](1.html))  
---|---  
Object.Faces = Faces | Установить свойство ([* ](1.html))  
Faces = Object.GetFaces() | Получить свойство ([**](2.html))  
Object.SetFaces( Faces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Faces( &Faces ) | Получить свойство  
---|---  
Object.put_Faces( Faces ) | Установить свойство  
  
Примечание.

Свойство позволяет устанавливать и получать грани операции. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
