# IsFunctionEnable - Признак поддержки приложением функций

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Интерфейс IKompasLibrary ](ikompaslibrary.html) > [IKompasLibrary - свойства ](ikompaslibrary_props.html) |  Scroll [ [ [ ](ikompaslibrary_isonapplication7.html "К следующему разделу")](ikompaslibrary_props.html "На уровень выше")](ikompaslibrary_displaylibraryname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaslibrary.html)

Тип данных: BOOL

Синтаксис:

HRESULT IsFunctionEnable( ksKompasLibraryFunctionEnum FunctionID, VARIANT_BOOL * Result );

Входные параметры:

FunctionID | \- Идентификатор функции из перечисления [ksKompasLibraryFunctionEnum](kskompaslibraryfunctionenum.html).  
---|---  
  
Примечание:

Приложение должно подтвердить, что оно поддерживает нужные ему функции.

Если приложение для какой то функции вернет FALSE. то данная функция вызываться не будет.

Подразделы:

(отсутствуют)
