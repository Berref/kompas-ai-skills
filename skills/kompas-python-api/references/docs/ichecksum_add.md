# Add - Добавить параметр к контрольной сумме

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ICheckSum ](ichecksum.html) > [ICheckSum - методы ](ichecksum_methods.html) |  Scroll [ [ [ ](ichecksum_addinterface.html "К следующему разделу")](ichecksum_methods.html "На уровень выше")](ichecksum_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichecksum.html)

Синтаксис Automation:

void Add (VARIANT value, BOOL order);

Синтаксис COM:

HRESULT Add (VARIANT value, VARIANT_BOOL order);

Входные параметры:

value | \- добавляемое значение,  
---|---  
order | \- формировать суммарную контрольную сумму значений: TRUE - с учетом порядка следования значений, FALSE - без учета порядка следования значений.  
  
Примечание:

Параметр value может принимать значения следующих типов:

•VT_INT,

•VT_I2,

•VT_I4,

•VT_R4,

•VT_R8,

•VT_UI1,

•VT_UINT,

•VT_BOOL,

•VT_BSTR,

•VT_ARRAY | VT_UI1.

Подразделы:

(отсутствуют)
