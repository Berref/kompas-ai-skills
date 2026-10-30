# FillContextPanel - Накачка всплывающей панели для библиотечных элементов

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - методы ](ikompaslibrary_methods.html) |  Scroll [ [ [ ](ikompaslibrary_filllibrarymenu.html "К следующему разделу")](ikompaslibrary_methods.html "На уровень выше")](ikompaslibrary_initlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Синтаксис:

HRESULT FillContextPanel( LPDISPATCH ContextPanel, VARIANT_BOOL * Result );

Входные параметры:

ContextPanel | \- указатель на интерфейс всплывающей панели I[ContextPanel](icontextpanel.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- если были изменения контекстной панели,  
---|---  
FALSE | \- использовать стандартную накачку панелей для данного библиотечного элемента.  
  
Примечание

Функция вызывается, если приложение подтвердило, что поддерживает работу данного метода (см. [IKompasLibrary::IsFunctionEnable](ikompaslibrary_isfunctionenable.html)).

Подразделы:

(отсутствуют)
