# EndLimiter - Типы ограничений на концах мультилинии

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_endparameter.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_closed.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: из перечисления [ksMlEndLimiterEnum](ksmlendlimiterenum.html)

Синтаксис Automation:

EndLimiter = iObject.EndLimiter( First ); | Получить свойство([* ](1.html))  
---|---  
iObject.EndLimiter( First ) = EndLimiter; | Установить свойство ([* ](1.html))  
EndLimiter = iObject.GetEndLimiter( First ); | Получить свойство ([**](2.html))  
iObject.SetEndLimiter( First, EndLimiter ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_EndLimiter( First, &EndLimiter ) | Получить свойство  
---|---  
iObject->put_EndLimiter( First, EndLimiter ) | Установить свойство  
  
Входные параметры:

First | \- номер ограничителя (TRUE - первая, FALSE - вторая).  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать типы ограничений на концах мультилинии.

Подразделы:

(отсутствуют)
