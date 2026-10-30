# LibInterfaceNotifyEntry - Инициализация библиотеки, подписка на события

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibrary_libinterfacenotifydisconnect.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_isonapplication7.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

VARIANT_BOOL LibInterfaceNotifyEntry( LPDISPATCH ApplicationInterface );

Входные параметры:

ApplicationInterface | \- интерфейс приложения Компас 3D.  
---|---  
  
Возвращаемое значение:

Не используется.

Примечание:

Параметр ApplicationInterface может быть указателем на интерфейс [IApplication](iapplication.html), если в приложении реализован метод [ksKompasLibrary::IsOnApplication7](kskompaslibrary_isonapplication7.html), и этот метод вернул значение TRUE, т.е. библиотека работает на API версии 7. Во всех остальных случаях параметр ApplicationInterface будет указателем на интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
