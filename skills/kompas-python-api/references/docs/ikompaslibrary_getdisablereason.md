# GetDisableReason - Получить описание причины недоступности команды

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_getkompasconverter.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_filllibrarymenu.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT GetDisableReason( long Command, BSTR * Result );

Входные параметры:

Command | \- номер команды приложения.  
---|---  
  
Возвращаемое значение:

| \- строка-пояснение с причиной недоступности команды.  
---|---  
  
Примечание:

Строка-пояснение удаляется функцией SysFreeString.

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода [IKompasLibrary::GetLibraryCommandState](ikompaslibrary_getlibrarycommandstate.html) (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)) и в функции IKompasLibrary::GetLibraryCommandState сделала команду недоступной.

Подразделы:

(отсутствуют)
