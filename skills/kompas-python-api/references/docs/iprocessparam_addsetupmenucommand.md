# AddSetupMenuCommand - Добавить пункт в меню настроек процесса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - методы ](iprocessparam_methods.html) |  Scroll [ [ [ ](iprocessparam_addspectoolbarbutton.html "К следующему разделу")](iprocessparam_methods.html "На уровень выше")](iprocessparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessparam.html)

Синтаксис Automation:

BOOL AddSetupMenuCommand( BSTR Title, long Command, BOOL Checable );

Синтаксис COM:

HRESULT AddSetupMenuCommand( BSTR Title, long Command, BOOL Checable, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Title | \- заголовок,  
---|---  
Command | \- идентификатор команды,  
Checable | \- FALSE - выполняемая команда, TRUE - флаг состояния.  
  
Подразделы:

(отсутствуют)
