# ResModule - Растровый рисунок на вкладке

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyTab ](ipropertytab.html) > [IPropertyTab - свойства ](ipropertytab_props.html) |  Scroll [ [ [ ](ipropertytab_visible.html "К следующему разделу")](ipropertytab_props.html "На уровень выше")](ipropertytab_propertycontrols.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertytab.html)

Тип данных: VARIANT (long или BSTR).

Значения свойства:

HINSTANCE (тип значения long) | \- полный путь к файлу (тип значения BSTR) dll модуля, в котором находятся все необходимые ресурсы.  
---|---  
  
Синтаксис Automation:

ResModule = iObject.ResModule | Получить свойство ([* ](1.html))  
---|---  
iObject.ResModule = ResModule | Установить свойство ([* ](1.html))  
ResModule = iObject.GetResModule() | Получить свойство([**](2.html))  
iObject.SetResModule(ResModule) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResModule(&ResModule) | Получить свойство  
---|---  
iObject->put_ResModule(ResModule) | Установить свойство  
  
Примечание:

Свойство позволяет получить или установить dll-модуль, в котором находится рисунок для кнопки.

Подразделы:

(отсутствуют)
