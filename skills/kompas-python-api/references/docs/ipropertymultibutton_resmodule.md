# ResModule - Модуль с ресурсами значков

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - свойства ](ipropertymultibutton_props.html) |  Scroll [ [ [ ](ipropertymultibutton_methods.html "К следующему разделу")](ipropertymultibutton_props.html "На уровень выше")](ipropertymultibutton_buttonvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных: VARIANT (long или BSTR)

Синтаксис Automation:

ResModule = iObject.ResModule | Получить свойство ([* ](1.html))  
---|---  
iObject.ResModule = ResModule | Установить свойство ([* ](1.html))  
ResModule = iObject.GetResModule() | Получить свойство([**](2.html))  
iObject.SetResModule (ResModule) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResModule (&ResModule) | Получить свойство  
---|---  
iObject->put_ResModule (ResModule) | Установить свойство  
  
Значение свойства:

HINSTANCE (тип значения long) или полный путь к файлу (тип значения BSTR) dll модуля, в котором находятся все необходимые ресурсы. |   
---|---  
  
Примечание:

Данное свойство позволяет установить или получить dll-модуль, из которого будут извлекаться значки для кнопок.

Подразделы:

(отсутствуют)
