# IsOnApplication7 - Получить тип версии API, используемого библиотекой

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс ksKompasLibrary ](kskompaslibrary.html) > [ksKompasLibrary - методы ](kskompaslibrary_methods.html) |  Scroll [ [ [ ](kskompaslibrary_libinterfacenotifyentry.html "К следующему разделу")](kskompaslibrary_methods.html "На уровень выше")](kskompaslibrary_externalruncommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kskompaslibrary.html)

Синтаксис:

VARIANT_BOOL IsOnApplication7();

Примечание:

Если библиотека поддерживает данный метод и возвращает TRUE, в функцию [ksKompasLibrary::ExternalRunCommand](kskompaslibrary_externalruncommand.html) и [ksKompasLibrary::LibInterfaceNotifyEntry](kskompaslibrary_libinterfacenotifyentry.html) передается интерфейс [IApplication](iapplication.html) иначе передается интерфейс [KompasObject.](kompasobject.html)

Подразделы:

(отсутствуют)
