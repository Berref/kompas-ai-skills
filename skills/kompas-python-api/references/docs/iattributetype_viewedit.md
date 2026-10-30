# ViewEdit - Открыть диалог для просмотра и редактирования типа атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttributeType ](iattributetype.html) > [IAttributeType - методы ](iattributetype_methods.html) |  Scroll [ [ [ ](icolumninfo.html "К следующему разделу")](iattributetype_methods.html "На уровень выше")](iattributetype_update.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattributetype.html)

Синтаксис Automation:

BOOL ViewEdit( OLE_HANDLE Parent,

BSTR Password,

BOOL ReadOnly );

Синтаксис COM:

HRESULT ViewEdit( OLE_HANDLE Parent,

BSTR Password,

BOOL ReadOnly,

BOOL *Result );

Выходные параметры:

Parent | \- дескриптор главного окна системы КОМПАС, который можно получить с помощью функции [GetHWindow](gethwindow.html),  
---|---  
Password | \- пароль,  
ReadOnly | \- TRUE - открыть диалог для просмотра, \- FALSE - открыть диалог для редактирования.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет открыть диалог для просмотра и редактирования типа атрибута.

Подразделы:

(отсутствуют)
