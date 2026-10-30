# RefObject - Ссылка на объект "Стрелка вида", "Линия разреза" или "Выносной элемент"

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IViewDesignation ](iviewdesignation.html) > [IViewDesignation - свойства ](iviewdesignation_props.html) |  Scroll [ [ [ ](iviewdesignation_showangle.html "К следующему разделу")](iviewdesignation_props.html "На уровень выше")](iviewdesignation_drawingtext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviewdesignation.html)

Тип данных: VARIANT

Синтаксис Automation:

RefObject = iObject.RefObject | Получить свойство ([* ](1.html))  
---|---  
iObject.RefObject = RefObject | Установить свойство ([* ](1.html))  
RefObject = iObject.GetRefObject() | Получить свойство ([**](2.html))  
iObject.SetRefObject (RefObject) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_RefObject (&RefObject) | Получить свойство  
---|---  
iObject->put_RefObject (RefObject) | Установить свойство  
  
Примечание:

Свойство позволяет получить или установить ссылку на объект "Стрелка вида", "Линия разреза", "Выносной элемент".

Наименование из этого объекта используется в формировании обозначения вида. Если вид ассоциативный, свойство работает как readOnly (только для чтения). В настоящее время свойство реализовано через reference на объект.

VARIANT pVal;

pVal.lVal = p; // reference объекта

pVal.vt = VT_I4; // тип long

Подразделы:

(отсутствуют)
