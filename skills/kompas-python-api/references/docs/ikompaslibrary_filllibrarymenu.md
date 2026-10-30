# FillLibraryMenu - Динамическая накачка меню

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_getdisablereason.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_fillcontextpanel.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT FillLibraryMenu( IKompasLibraryMenu * Menu, VARIANT_BOOL * Result );

Входные параметры:

Menu | \- указатель на интерфейс меню приложения [IKompasLibraryMenu](ikompaslibrarymenu.html).  
---|---  
  
Возвращаемое значение:

Не используется.

Примечание:

Метод используется, если меню библиотеки не объявлено в манифесте библиотеки.

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Подразделы:

(отсутствуют)
