# SetPLMCompositionsAttrAvailability - Установить доступность в настройках дерева документа пункта меню 'ЛОЦМАН Состав'

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - методы ](iplmobjectsmanager_methods.html) |  Scroll [ [ [ ](iplmobjectsmanager_setplmpropertyavailability.html "К следующему разделу")](iplmobjectsmanager_methods.html "На уровень выше")](iplmobjectsmanager_setplmchangesattravailability.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Синтаксис Automation:

BOOL SetPLMCompositionsAttrAvailability( BOOL Available, BOOL Enabled );

Синтаксис COM:

HRESULT SetPLMCompositionsAttrAvailability( BOOL Available, BOOL Enabled, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

Available | \- доступность атрибута “ЛОЦМАН Состав” в контекстном меню настроек Дерева документа,  
---|---  
Enabled | \- видимость атрибутов “ЛОЦМАН Состав” в Дереве.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
