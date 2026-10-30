# SetSetupMenuCommandState - Установить состояние команды меню настроек процесса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessParam ](iprocessparam.html) > [IProcessParam - методы ](iprocessparam_methods.html) |  Scroll [ [ [ ](iprocess.html "К следующему разделу")](iprocessparam_methods.html "На уровень выше")](iprocessparam_pushprocessname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessparam.html)

Синтаксис Automation:

BOOL SetSetupMenuCommandState( long Command, BOOL Visible, BOOL Enable, BOOL Checked );

Синтаксис COM:

HRESULT SetSetupMenuCommandState( long Command, BOOL Visible, BOOL Enable, BOOL Checked, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
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
