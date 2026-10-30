# PLMPropertyValue - Значение свойств в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObject ](iplmobject.html) > [IPLMObject - свойства ](iplmobject_propers.html) |  Scroll [ [ [ ](iplmobject_plmstatus.html "К следующему разделу")](iplmobject_propers.html "На уровень выше")](iplmobject_plmcomposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobject.html)

Тип данных: VARIANT

Синтаксис Automation:

PLMPropertyValue = Object.PLMPropertyValue( Property ) | Получить свойство ([* ](1.html))  
---|---  
Object.PLMPropertyValue( Property ) = PLMPropertyValue | Установить свойство ([* ](1.html))  
PLMPropertyValue = Object.GetPLMPropertyValue( Property ) | Получить свойство ([**](2.html))  
Object.SetPLMPropertyValue( Property, PLMPropertyValue ) | Установить свойство ([* ](1.html))  
  
Синтаксис COM:

Object.get_PLMPropertyValue( Property, &PLMPropertyValue ) | Получить свойство  
---|---  
Object.put_PLMPropertyValue( Property, PLMPropertyValue ) | Установить свойство  
  
Входные параметры:

Property | \- тип свойства из перечисления [ksPLMPropertyEnum](ksplmpropertyenum.html).  
---|---  
  
Версия Компас v21

Подразделы:

(отсутствуют)
