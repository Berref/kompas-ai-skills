# SetPLMPropertyAvailability - Управление отображением свойств Лоцман в окне “Параметры”

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IPLMObjectsManager ](iplmobjectsmanager.html) > [IPLMObjectsManager - методы ](iplmobjectsmanager_methods.html) |  Scroll [ [ [ ](iplmobjectsmanager_setplmstatusattravailability.html "К следующему разделу")](iplmobjectsmanager_methods.html "На уровень выше")](iplmobjectsmanager_setplmcompositionsattravailability.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplmobjectsmanager.html)

Синтаксис Automation:

BOOL SetPLMPropertyAvailability( ksPLMPropertyEnum Property, BOOL Available, BOOL Enabled, VARIANT ValueList );

Синтаксис COM:

HRESULT SetPLMPropertyAvailability( ksPLMPropertyEnum Property, BOOL Available, BOOL Enabled, VARIANT ValueList, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Property | \- тип свойства из перечисления [ksPLMPropertyEnum](ksplmpropertyenum.html),  
---|---  
Available | \- включить отображение свойства,  
Enabled | \- включить доступность изменения значения,  
ValueList | \- список значений.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
