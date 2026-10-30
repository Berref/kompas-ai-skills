# LibraryHelpFile - Файл справки

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - свойства ](ikompaslibrary_props.html) |  Scroll [ [ [ ](ikompaslibrary_libraryname.html "К следующему разделу")](ikompaslibrary_props.html "На уровень выше")](ikompaslibrary_isonapplication7.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Тип данных: BSTR

Синтаксис:

HRESULT LibraryHelpFile( BSTR * Result );

Примечание

Библиотека может определить файл справки, который требуется открывать при наведении на команды библиотеки и в библиотечных процессах.

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Если функция библиотекой не поддерживается, файл справки определяется по имени файла библиотеки с учетом текущей локализации.

Подразделы:

(отсутствуют)
