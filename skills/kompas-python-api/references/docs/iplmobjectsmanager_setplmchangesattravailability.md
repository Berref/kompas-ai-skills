# SetPLMChangesAttrAvailability - Установить доступность в настройках Дерева документа пункта меню “ЛОЦМАН Отличия”

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - методы ](iplmobjectsmanager_methods.html) |  Scroll [ [ [ ](iplmobjectsmanager_setplmcompositionsattravailability.html "К следующему разделу")](iplmobjectsmanager_methods.html "На уровень выше")](iplmobjectsmanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Синтаксис Automation:

BOOL SetPLMChangesAttrAvailability( BOOL Available, BOOL Enabled );

Синтаксис COM :

HRESULT SetPLMChangesAttrAvailability( BOOL Available, BOOL Enabled, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

Available | \- доступность атрибута “ЛОЦМАН Отличия” в контекстном меню настроек Дерева документа,  
---|---  
Enabled | \- видимость в атрибутов “ЛОЦМАН Отличия” в Дереве.  
  
Подразделы:

(отсутствуют)
