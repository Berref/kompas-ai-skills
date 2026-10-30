# GetProperty - Получить свойство

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyMng ](ipropertymng.html) > [IPropertyMng - методы ](ipropertymng_methods.html) |  Scroll [ [ [ ](ipropertymng_getproperties.html "К следующему разделу")](ipropertymng_methods.html "На уровень выше")](ipropertymng_addproperty.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymng.html)

Синтаксис Automation:

LPDISPATCH GetProperty ( VARIANT libname, VARIANT index );

Синтаксис COM:

HRESULT GetProperty( VARIANT Libname, VARIANT Index, IProperty ** Res );

Входные параметры:

Libname (VARIANT) | \- полный путь к библиотеке на диске VT_BSTR, либо указатель на документ VT_DISPATCH. Текущий документ - VT_EMPTY,  
---|---  
index(VARIANT) | \- индекс в хранилище VT_I4, либо по идентификатору самого свойства - VT_R8.  
  
Возвращаемое значение:

| \- Указатель на интерфейс свойства [IProperty](iproperty.html).  
---|---  
  
[Номера системных свойств...](systempropertytype.html)

Подразделы:

(отсутствуют)
