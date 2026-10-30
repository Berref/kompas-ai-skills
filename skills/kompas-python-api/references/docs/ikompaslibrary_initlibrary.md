# InitLibrary - Инициализация библиотеки, подписка на события

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_fillcontextpanel.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_createmacrofromsample.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT InitLibrary( LPDISPATCH ApplicationInterface, VARIANT_BOOL * Result );

Входные параметры:

ApplicationInterface | \- интерфейс приложения Компас 3D.  
---|---  
  
Возвращаемое значение:

Не используется.

Примечание:

Параметр ApplicationInterface может быть указателем на интерфейс [IApplication](iapplication.html), если приложение поддерживает метод [IKompasLibrary::IsOnApplication7](ikompaslibrary_isonapplication7.html), и этот метод вернул значение TRUE, т.е. библиотека работает на API версии 7. Во всех остальных случаях параметр ApplicationInterface будет указателем на интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
