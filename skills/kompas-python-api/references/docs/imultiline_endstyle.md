# EndStyle - Стиль линии кривой в ограничителе

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - свойства ](imultiline_props.html) |  Scroll [ [ [ ](imultiline_linecount.html "К следующему разделу")](imultiline_props.html "На уровень выше")](imultiline_endparameter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Тип данных: long (соответствует перечислению [ksCurveStyleEnum](kscurvestyleenum.html))

Синтаксис Automation:

EndStyle = iObject.EndStyle( First ); | Получить свойство([* ](1.html))  
---|---  
iObject.EndStyle( First ) = EndStyle; | Установить свойство ([* ](1.html))  
EndStyle = iObject.GetEndStyle( First ); | Получить свойство ([**](2.html))  
iObject.SetEndStyle( First, EndStyle ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_EndStyle( First, &EndStyle ) | Получить свойство  
---|---  
iObject->put_EndStyle( First, EndStyle ) | Установить свойство  
  
Входные параметры:

First | \- номер ограничителя (TRUE - первая, FALSE - вторая).  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать стиль линии в ограничителе.

Подразделы:

(отсутствуют)
