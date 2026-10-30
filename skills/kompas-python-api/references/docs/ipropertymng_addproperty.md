# AddProperty - Добавить свойство

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IPropertyMng ](ipropertymng.html) > [IPropertyMng - методы ](ipropertymng_methods.html) |  Scroll [ [ [ ](ipropertymng_getproperty.html "К следующему разделу")](ipropertymng_methods.html "На уровень выше")](ipropertymng_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymng.html)

Синтаксис Automation:

LPDISPATCH AddProperty( VARIANT libname, VARIANT val );

Синтаксис COM:

HRESULT AddProperty( VARIANT Libname, VARIANT Val, IProperty ** ColVal );

Входные параметры:

Libname ( VARIANT) | \- полный путь к библиотеке на диске VT_BSTR, либо указатель на документ VT_DISPATCH. Текущий документ - VT_EMPTY,  
---|---  
val( VARIANT) | \- новое свойство VT_EMPY, создать по прототипу другого свойства - VT_DISPATCH.  
  
Возвращаемое значение:

| \- Указатель на интерфейс свойства [IProperty](iproperty.html).  
---|---  
  
Подразделы:

(отсутствуют)
