# AngleType - Способ задания угла - угол сгиба/дополняющий угол

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBend ](isheetmetalbend.html) > [ISheetMetalBend - свойства ](isheetmetalbend_props.html) |  Scroll [ [ [ ](isheetmetalbend_bendcoefficient.html "К следующему разделу")](isheetmetalbend_props.html "На уровень выше")](isheetmetalbend_angle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbend.html)

Тип данных: BOOL

Синтаксис Automation:

AngleType = iObject.AngleType(); | Получить свойство ([* ](1.html))  
---|---  
iObject.AngleType() = AngleType; | Установить свойство ([* ](1.html))  
AngleType = iObject.GetAngleType(); | Получить свойство ([**](2.html))  
iObject.SetAngleType( AngleType ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AngleType( &AngleType ); | Получить свойство  
---|---  
iObject->put_AngleType( AngleType ); | Установить свойство  
  
Значения свойства:

TRUE | \- угол интерпретируется как угол сгиба,  
---|---  
FALSE | \- угол интерпретируется как дополняющий угол.  
  
Примечание.

Позволяет считывать и устанавливать способ задания угла.

Подразделы:

(отсутствуют)
