# ExtrusionType - Тип выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBody ](isheetmetalbody.html) > [ISheetMetalBody - свойства ](isheetmetalbody_props.html) |  Scroll [ [ [ ](isheetmetalbody_operationresult.html "К следующему разделу")](isheetmetalbody_props.html "На уровень выше")](isheetmetalbody_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbody.html)

Тип данных: из перечисления [ksEndTypeEnum](ksendtypeenum.html)

Синтаксис Automation:

ExtrusionType = iObject.ExtrusionType( normal ); | Получить свойство ([* ](1.html))  
---|---  
iObject.ExtrusionType( normal ) = ExtrusionType; | Установить свойство ([* ](1.html))  
ExtrusionType = iObject.GetExtrusionType( normal ); | Получить свойство ([**](2.html))  
iObject.SetExtrusionType( normal, ExtrusionType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ExtrusionType( &ExtrusionType ); | Получить свойство  
---|---  
iObject->put_ExtrusionType( ExtrusionType ); | Установить свойство  
  
Входные параметры:

BOOL normal | \- TRUE - тип выдавливания в прямом направлении, \- FALSE - тип выдавливания в обратном направлении.  
---|---  
  
Примечание.

Позволяет считывать и устанавливать тип выдавливания.

Подразделы:

(отсутствуют)
