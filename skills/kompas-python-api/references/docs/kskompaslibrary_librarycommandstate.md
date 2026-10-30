# LibraryCommandState - Динамическая накачка меню

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibraryfunctionenum.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_libinterfacenotifydisconnect.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

VARIANT_BOOL LibraryCommandState( long Command, VARIANT_BOOL * Enable, long * Checked );

Входные параметры:

Command | \- номер команды приложения.  
---|---  
  
Выходные параметры:

Enable | \- доступность команды.  
---|---  
Checked | \- состояние команды (нажата/отжата).  
  
Возвращаемое значение:

Не используется

Примечание:

Функция возвращает состояние команды приложения.

Функция управляет состоянием команды в меню и панелях команд приложения.

Если библиотека в каких-то случаях делает команды недоступными, рекомендуется реализовать также метод [IKompasLibrary::GetDisableReason](ikompaslibrary_getdisablereason.html), где требуется возвращать строку-подсказку с причиной недоступности команды.

Подразделы:

(отсутствуют)
