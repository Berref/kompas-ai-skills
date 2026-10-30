# CheckBoxVisibility - Видимость опции, управляющей отрисовкой изображения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySlideBox ](ipropertyslidebox.html) > [IPropertySlideBox - свойства ](ipropertyslidebox_props.html) |  Scroll [ [ [ ](ipropertyslidebox_drawingslide.html "К следующему разделу")](ipropertyslidebox_props.html "На уровень выше")](ipropertyslidebox_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyslidebox.html)

Тип данных: BOOL.

Синтаксис Automation:

CheckBoxVisibility = iObject.CheckBoxVisibility | Получить свойство ([* ](1.html))  
---|---  
iObject.CheckBoxVisibility = CheckBoxVisibility | Установить свойство ([* ](1.html))  
CheckBoxVisibility = iObject.GetCheckBoxVisibility() | Получить свойство([**](2.html))  
iObject.SetCheckBoxVisibility (CheckBoxVisibility) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CheckBoxVisibility (&CheckBoxVisibility) | Получить свойство  
---|---  
iObject->put_CheckBoxVisibility (CheckBoxVisibility) | Установить свойство  
  
Возвращаемое значение:

TRUE | \- опция отображается под слайдом,  
---|---  
FALSE | \- опция не отображается.  
  
Примечание:

Свойство позволяет определить тип отображаемого значения.

Подразделы:

(отсутствуют)
