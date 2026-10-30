# BodyFaces - Грани инструмента для вырубки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalPunch ](isheetmetalpunch.html) > [ISheetMetalPunch - свойства ](isheetmetalpunch_props.html) |  Scroll [ [ [ ](isheetmetalpunch_buildingtype.html "К следующему разделу")](isheetmetalpunch_props.html "На уровень выше")](isheetmetalpunch_body.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalpunch.html)

Тип данных: VARIANT

Синтаксис Automation:

BodyFaces = Object.BodyFaces | Получить свойство ([* ](1.html))  
---|---  
Object.BodyFaces = BodyFaces | Установить свойство ([* ](1.html))  
BodyFaces = Object.GetBodyFaces() | Получить свойство ([**](2.html))  
Object.SetBodyFaces( BodyFaces ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BodyFaces( &BodyFaces ) | Получить свойство  
---|---  
Object.put_BodyFaces( BodyFaces ) | Установить свойство  
  
Примечание

Возвращается:

•массив SafeArray VT_ARRAY | VT_DISPATCH граней [IFace](iface.html), если грани для вырубки заданы,

•VT_EMPTY, если грани не выбраны.

Подразделы:

(отсутствуют)
