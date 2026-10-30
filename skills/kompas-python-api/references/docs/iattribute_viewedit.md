# ViewEdit - Открыть диалог для просмотра и редактирования атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - методы ](iattribute_methods.html) |  Scroll [ [ [ ](iattributetype.html "К следующему разделу")](iattribute_methods.html "На уровень выше")](iattribute_setvalues.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

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
ReadOnly | \- TRUE - открыть диалог для просмотра \- FALSE - открыть диалог для редактирования.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет открыть диалог для просмотра и редактирования атрибута.

Подразделы:

(отсутствуют)
