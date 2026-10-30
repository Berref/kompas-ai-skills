# Direction - Направление построения дуги

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IArcAxis ](iarcaxis.html) > [IArcAxis - свойства ](iarcaxis_props.html) |  Scroll [ [ [ ](iarcaxis_jut.html "К следующему разделу")](iarcaxis_props.html "На уровень выше")](iarcaxis_angle2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iarcaxis.html)

Тип данных: BOOL

Синтаксис Automation:

Direction = iObject.Direction; | Получить свойство([* ](1.html))  
---|---  
iObject.Direction = Direction; | Установить свойство ([* ](1.html))  
Direction = iObject.GetDirection(); | Получить свойство ([**](2.html))  
iObject.SetDirection( Direction ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Direction( &Direction ); | Получить свойство  
---|---  
iObject->put_Direction( Direction ); | Установить свойство  
  
Значения свойства:

TRUE | \- по часовой стрелке,  
---|---  
FALSE | \- против часовой стрелки.  
  
Примечание:

Свойство позволяет получить и установить направление построения дуги.

Подразделы:

(отсутствуют)
