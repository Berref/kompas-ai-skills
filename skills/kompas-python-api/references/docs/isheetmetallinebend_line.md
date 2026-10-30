# Line - Прямолинейный объект (отрезок эскиза или ломаной, ребро или ось)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLineBend ](isheetmetallinebend.html) > [ISheetMetalLineBend - свойства ](isheetmetallinebend_props.html) |  Scroll [ [ [ ](isheetmetallinebend_radius.html "К следующему разделу")](isheetmetallinebend_props.html "На уровень выше")](isheetmetallinebend_internalradius.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinebend.html)

Тип данных: указатель на интерфейс объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

Line = iObject.Line; | Получить свойство ([* ](1.html))  
---|---  
iObject.Line = Line; | Установить свойство ([* ](1.html))  
Line = iObject.GetLine; | Получить свойство ([**](2.html))  
iObject.SetLine( Line ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Line( &Line ); | Получить свойство  
---|---  
iObject->put_Line( Line ); | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать прямолинейный объект (отрезок эскиза или ломанной, ребро или ось), относительно которого сгибается листовое тело. Прямолинейный объект и грань (массив граней), участвующие в операции "сгиб по линии", должны располагаться в одной плоскости.

Подразделы:

(отсутствуют)
