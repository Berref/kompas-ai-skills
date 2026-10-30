# DrawBitmap - Отрисовать растр по идентификатору в ресурсах

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawbitmapfromfile.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_propers.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawBitmap( OLE_HANDLE HWnd, long sldID, VARIANT Module );

Синтаксис COM:

HRESULT DrawBitmap( OLE_HANDLE HWnd, long sldID, VARIANT Module, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
sldID | \- идентификатор слайда,  
Module | \- HINSTANCE приложения.  
  
Подразделы:

(отсутствуют)
