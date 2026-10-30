# ViewEditAttr - Открыть диалог для просмотра атрибутов объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_writemetadatatofile.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_setchanged.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

BOOL ViewEditAttr( OLE_HANDLE HWnd,

VARIANT Objects );

Синтаксис COM:

HRESULT ViewEditAttr( OLE_HANDLE HWnd,

VARIANT Objects,

BOOL * Result );

Входные параметры:

HWnd | \- дескриптор главного окна КОМПАС (можно получить с помощью функции [GetHWindow](gethwindow.html),  
---|---  
Objects | \- объект или массив объектов, атрибуты которых нужно просмотреть ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет вывести диалог для просмотра атрибутов объекта.

Подразделы:

(отсутствуют)
