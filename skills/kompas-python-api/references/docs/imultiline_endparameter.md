# EndParameter - Параметр ограничителя в %(0-100)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_endstyle.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_endlimiter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: double

Синтаксис Automation:

EndParameter = iObject.EndParameter( First ); | Получить свойство([* ](1.html))  
---|---  
iObject.EndParameter( First ) = EndParameter; | Установить свойство ([* ](1.html))  
EndParameter = iObject.EndParameter( First ); | Получить свойство ([**](2.html))  
iObject.EndParameter( First, EndParameter ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_EndParameter( First, &EndParameter ) | Получить свойство  
---|---  
iObject->put_EndParameter( First, EndParameter ) | Установить свойство  
  
Входные параметры:

First | \- номер ограничителя (TRUE - первая, FALSE - вторая).  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать параметр ограничителя в процентах от ширины мультилинии.

Подразделы:

(отсутствуют)
