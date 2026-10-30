# ResModule - Модуль с ресурсами

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertySlideBox ](ipropertyslidebox.html) > [IPropertySlideBox - свойства ](ipropertyslidebox_props.html) |  Scroll [ [ [ ](ipropertyslidebox_slidetype.html "К следующему разделу")](ipropertyslidebox_props.html "На уровень выше")](ipropertyslidebox_height.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyslidebox.html)

Тип данных: VARIANT (long или BSTR).

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

HINSTANCE (тип значения long) или полный путь к файлу (тип значения BSTR) dll модуля, в котором находятся все необходимые ресурсы.  
---  
  
Примечание:

Данное свойство позволяет установить или получить dll-модуль, с которого будут доставаться значки или слайды для отображения в окне.

Подразделы:

(отсутствуют)
