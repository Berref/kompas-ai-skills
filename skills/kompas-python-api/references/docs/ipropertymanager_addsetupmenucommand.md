# AddSetupMenuCommand - Добавить пункт в меню настроек процесса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - методы ](ipropertymanager_methods.html) |  Scroll [ [ [ ](ipropertymanager_addspectoolbarbutton.html "К следующему разделу")](ipropertymanager_methods.html "На уровень выше")](ipropertymanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Синтаксис Automation:

BOOL AddSetupMenuCommand( BSTR Title, long Command, BOOL Checable );

Синтаксис COM:

HRESULT AddSetupMenuCommand( BSTR Title, long Command, BOOL Checable, BOOL * Result );

Возвращаемое значение:

TRUE | \- успешное завершение,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Title | \- заголовок,  
---|---  
Command | \- идентификатор команды,  
Checable | \- FALSE - выполняемая команда, TRUE - флаг состояния.  
  
Подразделы:

(отсутствуют)
