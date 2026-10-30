# BeginUnloadLibrary - Завершающие действия перед отключением библиотеки, отписка от событий

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_contextpanelstylecombochanged.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT BeginUnloadLibrary( VARIANT_BOOL * Result );

Возвращаемое значение:

Не используется

Примечание:

Приложение в данном методе должно отписаться от событий и освободить запомненные интерфейсы API Компас.

Подразделы:

(отсутствуют)
