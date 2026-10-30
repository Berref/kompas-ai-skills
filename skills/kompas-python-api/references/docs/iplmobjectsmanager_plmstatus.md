# PLMStatus - Статус в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - свойства ](iplmobjectsmanager_propers.html) |  Scroll [ [ [ ](iplmobjectsmanager_methods.html "К следующему разделу")](iplmobjectsmanager_propers.html "На уровень выше")](iplmobjectsmanager_plmpropertyvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Тип данных: из перечисления [ksPLMStatusEnum.](ksplmstatusenum.html)

Синтаксис Automation:

PLMStatus = Object.PLMStatus( FileName ) | Получить свойство ([* ](1.html))  
---|---  
Object.PLMStatus( FileName ) = PLMStatus | Установить свойство ([* ](1.html))  
PLMStatus = Object.GetPLMStatus( FileName ) | Получить свойство ([**](2.html))  
Object.SetPLMStatus( FileName, PLMStatus ) | Установить свойство ([* ](1.html))  
  
Синтаксис COM:

Object.get_PLMStatus( FileName, &PLMStatus ) | Получить свойство  
---|---  
Object.put_PLMStatus( FileName, PLMStatus ) | Установить свойство  
  
Входные параметры:

BSTR | \- FileName - имя файла.  
---|---  
  
Примечание:

Свойство позволяет получить/установить статус объектов версионирования по имени файла.

Подразделы:

(отсутствуют)
