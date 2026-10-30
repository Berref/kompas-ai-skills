# ChoiceAttrTypes - Открыть диалог для просмотра в библиотеке атрибутов списка типов атрибутов и выбора нужного типа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttrTypeMng ](iattrtypemng.html) > [IAttrTypeMng - методы ](iattrtypemng_methods.html) |  Scroll [ [ [ ](iattrtypemng_createattrtype.html "К следующему разделу")](iattrtypemng_methods.html "На уровень выше")](iattrtypemng_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattrtypemng.html)

Синтаксис Automation:

LPDISPATCH ChoiceAttrTypes( OLE_HANDLE HWnd,

VARIANT Libname );

Синтаксис COM:

HRESULT ChoiceAttrTypes( OLE_HANDLE HWnd,

VARIANT Libname,

IAttributeType ** Result );

Входные параметры:

HWnd | \- дескриптор главного окна системы КОМПАС, который можно получить с помощью функции [GetHWindow](gethwindow.html),  
---|---  
Libname | \- имя библиотеки типов атрибутов.  
  
Возвращаемое значение:

| Указатель на интерфейс выбранного в диалоге типа атрибута [IAttributeType](iattributetype.html).  
---|---  
  
Примечание:

Метод позволяет открыть диалог просмотра типов атрибутов в библиотеке.

Подразделы:

(отсутствуют)
