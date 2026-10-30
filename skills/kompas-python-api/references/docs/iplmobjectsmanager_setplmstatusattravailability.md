# SetPLMStatusAttrAvailability - Установить доступность в настройках Дерева документа пункта меню “ЛОЦМАН Статус”

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - методы ](iplmobjectsmanager_methods.html) |  Scroll [ [ [ ](ap2013730.html "К следующему разделу")](iplmobjectsmanager_methods.html "На уровень выше")](iplmobjectsmanager_setplmpropertyavailability.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Синтаксис Automation:

BOOL SetPLMStatusAttrAvailability( BOOL Available, BOOL Enabled );

Синтаксис COM:

HRESULT SetPLMStatusAttrAvailability( BOOL Available, BOOL Enabled, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

Available | \- доступность атрибута “ЛОЦМАН Статус” в контекстном меню настроек Дерева документа,  
---|---  
Enabled | \- видимость атрибутов “ЛОЦМАН Статус” в Дереве.  
  
Подразделы:

(отсутствуют)
