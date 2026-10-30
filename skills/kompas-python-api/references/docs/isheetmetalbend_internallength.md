# InternalLength - Определение длины по внутреннему контуру сгиба/по касанию к сгибу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBend ](isheetmetalbend.html) > [ISheetMetalBend - свойства ](isheetmetalbend_props.html) |  Scroll [ [ [ ](isheetmetalbend_internalradius.html "К следующему разделу")](isheetmetalbend_props.html "На уровень выше")](isheetmetalbend_distancerightside.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbend.html)

Тип данных: BOOL

Синтаксис Automation:

InternalLength = iObject.InternalLength(); | Получить свойство ([* ](1.html))  
---|---  
iObject.InternalLength() = InternalLength; | Установить свойство ([* ](1.html))  
InternalLength = iObject.GetInternalLength(); | Получить свойство ([**](2.html))  
iObject.SetInternalLength( InternalLength ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_InternalLength( &InternalLength ); | Получить свойство  
---|---  
iObject->put_InternalLength( InternalLength ); | Установить свойство  
  
Значения свойства:

TRUE | \- по внутреннему контуру сгиба,  
---|---  
FALSE | \- по касанию к сгибу.  
  
Примечание.

Позволяет считывать и устанавливать тип определения длины.

Подразделы:

(отсутствуют)
