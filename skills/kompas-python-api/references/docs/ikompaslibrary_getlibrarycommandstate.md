# GetLibraryCommandState - Получить текущее состояние команды

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_runlibrarycommand.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_getkompasconverter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT GetLibraryCommandState( long Command, VARIANT_BOOL * Enable, long * Checked, VARIANT_BOOL * Result );

Входные параметры:

Command | \- номер команды приложения.  
---|---  
  
Выходные параметры:

Enable | \- доступность команды,  
---|---  
Checked | \- состояние команды (нажата/отжата).  
  
Возвращаемое значение:

Не используется

Примечание:

Функция возвращает состояние команды приложения.

Функция управляет состоянием команды в меню и панелях команд приложения.

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Подразделы:

(отсутствуют)
