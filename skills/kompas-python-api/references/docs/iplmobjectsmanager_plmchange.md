# PLMChange - Отличие в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - свойства ](iplmobjectsmanager_propers.html) |  Scroll [ [ [ ](iplmobjectsmanager_plmcomposition.html "К следующему разделу")](iplmobjectsmanager_propers.html "На уровень выше")](iplmobjectsmanager_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Тип данных: из перечисления [ksPLMChangesEnum](ksplmchangesenum.html).

Синтаксис Automation:

PLMChange = Object.PLMChange( FileName ) | Получить свойство ([* ](1.html))  
---|---  
Object.PLMChange( FileName ) = PLMChange | Установить свойство ([* ](1.html))  
PLMChange = Object.GetPLMChange( FileName ) | Получить свойство ([**](2.html))  
Object.SetPLMChange( FileName, PLMChange ) | Установить свойство ([* ](1.html))  
  
Синтаксис COM:

Object.get_PLMChange( FileName, &PLMChange ) | Получить свойство  
---|---  
Object.put_PLMChange( FileName, PLMChange ) | Установить свойство  
  
Входные параметры:

BSTR | \- FileName - имя файла.  
---|---  
  
Примечание

Свойство позволяет получить/установить признак отличия объектов версионирования по имени файла.

Подразделы:

(отсутствуют)
