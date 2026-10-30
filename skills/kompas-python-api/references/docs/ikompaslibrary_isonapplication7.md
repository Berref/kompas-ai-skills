# IsOnApplication7 - Получить тип версии API, используемого библиотекой

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - свойства ](ikompaslibrary_props.html) |  Scroll [ [ [ ](ikompaslibrary_libraryhelpfile.html "К следующему разделу")](ikompaslibrary_props.html "На уровень выше")](ikompaslibrary_isfunctionenable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Тип данных: BOOL

Синтаксис:

HRESULT IsOnApplication7( VARIANT_BOOL * Result );

Примечание:

Если библиотека поддерживает данный метод и возвращает TRUE, в функцию [IKompasLibrary::InitLibrary](ikompaslibrary_initlibrary.html) передается интерфейс [IApplication](iapplication.html) \- иначе будет передаваться интерфейс [KompasObject](kompasobject.html).

Подразделы:

(отсутствуют)
