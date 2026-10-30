# Closed - Замкнутость

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_endlimiter.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_basecontour.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- мультилиния замкнута,  
---|---  
FALSE | \- мультилиния разомкнута.  
  
Синтаксис Automation:

Closed = iObject.Closed; | Получить свойство([* ](1.html))  
---|---  
iObject.Closed = Closed; | Установить свойство ([* ](1.html))  
Closed = iObject.GetClosed(); | Получить свойство ([**](2.html))  
iObject.SetClosed(Closed); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Closed( &Closed ) | Получить свойство  
---|---  
iObject->put_Closed( Closed ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать замкнутость.

2\. Если при создании замкнутой линии не совпадают точки начала и конца, будет создан дополнительный сегмент.

3\. Ограничители у замкнутой мультилинии не учитываются.

Подразделы:

(отсутствуют)
