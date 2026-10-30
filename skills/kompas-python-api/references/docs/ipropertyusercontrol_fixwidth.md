# FixWidth - Зафиксировать ширину элемента управления

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyUserControl ](ipropertyusercontrol.html) > [IPropertyUserControl - свойства ](ipropertyusercontrol_props.html) |  Scroll [ [ [ ](ipropertyusercontrol_height.html "К следующему разделу")](ipropertyusercontrol_props.html "На уровень выше")](ipropertyusercontrol_fixheight.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyusercontrol.html)

Тип данных: BOOL

Синтаксис Automation:

FixWidth = iObject.FixWidth | Получить свойство ([* ](1.html))  
---|---  
iObject.FixWidth = FixWidth | Установить свойство ([* ](1.html))  
FixWidth = iObject.GetFixWidth() | Получить свойство([**](2.html))  
iObject.SetFixWidth(FixWidth) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FixWidth(&FixWidth) | Получить свойство  
---|---  
iObject->put_FixWidth(FixWidth) | Установить свойство  
  
Значение свойства:

TRUE - размер элемента управления по ширине зафиксирован и равен значению, установленному в свойстве [Width](ipropertyusercontrol_width.html) \- Ширина элемента управления.

Примечание:

По умолчанию свойство имеет значение FALSE - размер элемента управления по ширине не зафиксирован. Свойство работает при горизонтальном размещении Панели свойств.

Подразделы:

(отсутствуют)
