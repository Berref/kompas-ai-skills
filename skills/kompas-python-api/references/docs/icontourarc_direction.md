# Direction - Направление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContourSegment ](icontoursegment.html) > [IContourSegment - свойства ](icontoursegment_props.html) > [Интерфейс IContourArc ](icontourarc.html) > [IContourArc - свойства ](icontourarc_props.html) |  Scroll [ [ [ ](icontourarc_radius.html "К следующему разделу")](icontourarc_props.html "На уровень выше")](icontourarc_angle2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontourarc.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- по часовой стрелке,  
---|---  
FALSE | \- против часовой стрелки.  
  
Синтаксис Automation:

Direction = iObject.Direction(); | Получить свойство([* ](1.html))  
---|---  
iObject.Direction() = Direction; | Установить свойство ([* ](1.html))  
Direction = iObject.GetDirection(); | Получить свойство ([**](2.html))  
iObject.SetDirection( Direction ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Direction( &Direction ) | Получить свойство  
---|---  
iObject->put_Direction( Direction ) | Установить свойство  
  
Примечание.

Свойство позволяет устанавливать и получать направление дуги.

Подразделы:

(отсутствуют)
