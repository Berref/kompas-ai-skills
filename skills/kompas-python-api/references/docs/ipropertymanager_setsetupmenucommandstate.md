# SetSetupMenuCommandState - Установить состояние команды меню настроек процесса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - методы ](ipropertymanager_methods.html) |  Scroll [ [ [ ](ipropertymanager_showtabs.html "К следующему разделу")](ipropertymanager_methods.html "На уровень выше")](ipropertymanager_seticon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymanager.html)

Синтаксис Automation:

BOOL SetSetupMenuCommandState( long Command, BOOL Visible, BOOL Enable, BOOL Checked );

Синтаксис COM:

HRESULT SetSetupMenuCommandState( long Command, BOOL Visible, BOOL Enable, BOOL Checked, BOOL * Result );

Возвращаемое значение:

TRUE | \- успешное завершение,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Command | \- идентификатор команды,  
---|---  
Visible | \- видимость,  
Enable | \- доступность,  
Checked | \- признак выбора.  
  
Подразделы:

(отсутствуют)
