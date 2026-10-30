# PLMComposition - Состояние состава в системе версионирования

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - свойства ](iplmobjectsmanager_propers.html) |  Scroll [ [ [ ](iplmobjectsmanager_plmpropertyvalue.html "К следующему разделу")](iplmobjectsmanager_propers.html "На уровень выше")](iplmobjectsmanager_plmchange.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Тип данных: из перечисления [ksPLMCompositionEnum](ksplmcompositionenum.html)

Синтаксис Automation:

PLMComposition = Object.PLMComposition( FileName ) | Получить свойство ([* ](1.html))  
---|---  
Object.PLMComposition( FileName ) = PLMComposition | Установить свойство ([* ](1.html))  
PLMComposition = Object.GetPLMComposition( FileName ) | Получить свойство ([**](2.html))  
Object.SetPLMComposition( FileName, PLMComposition ) | Установить свойство ([* ](1.html))  
  
Синтаксис COM:

Object.get_PLMComposition( FileName, &PLMComposition ) | Получить свойство  
---|---  
Object.put_PLMComposition( FileName, PLMComposition ) | Установить свойство  
  
Входные параметры:

BSTR FileName | \- имя файла.  
---|---  
  
Примечание:

Свойство позволяет получить/установить состояние состава объектов в системе версионирования по имени файла.

Версия Компас v23

Подразделы:

(отсутствуют)
