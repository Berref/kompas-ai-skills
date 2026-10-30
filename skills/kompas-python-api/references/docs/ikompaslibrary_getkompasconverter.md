# GetKompasConverter - Получить интерфейс конвертора

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_getlibrarycommandstate.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_getdisablereason.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT GetKompasConverter( LPDISPATCH * Result );

Возвращаемое значение:

| \- указатель на интерфейс конвертера [IKompasConverter](ikompasconverter.html).  
---|---  
  
Примечание:

Реализуется в библиотеках типа [Converter](new_lib_method.html).

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Подразделы:

(отсутствуют)
