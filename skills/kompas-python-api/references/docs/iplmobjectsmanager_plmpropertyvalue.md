# PLMPropertyValue - Значение свойств в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - свойства ](iplmobjectsmanager_propers.html) |  Scroll [ [ [ ](iplmobjectsmanager_plmstatus.html "К следующему разделу")](iplmobjectsmanager_propers.html "На уровень выше")](iplmobjectsmanager_plmcomposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Тип данных: VARIANT

Синтаксис Automation:

PLMPropertyValue = Object.PLMPropertyValue( Property, FileName ) | Получить свойство ([* ](1.html))  
---|---  
Object.PLMPropertyValue( Property, FileName ) = PLMPropertyValue | Установить свойство ([* ](1.html))  
PLMPropertyValue = Object.GetPLMPropertyValue( Property, FileName ) | Получить свойство ([**](2.html))  
Object.SetPLMPropertyValue( Property, FileName, PLMPropertyValue ) | Установить свойство ([* ](1.html))  
  
Синтаксис COM:

Object.get_PLMPropertyValue( Property, FileName, &PLMPropertyValue ) | Получить свойство  
---|---  
Object.put_PLMPropertyValue( Property, FileName, PLMPropertyValue ) | Установить свойство  
  
Входные параметры:

Property | \- тип свойства из перечисления [ksPLMPropertyEnum](ksplmpropertyenum.html),  
---|---  
FileName | \- путь к файлу.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
