# DrawBitmapFromFile - Отрисовать растр из файла

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawkompasdocument.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawbitmap.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawBitmapFromFile( OLE_HANDLE HWnd, BSTR FileName );

Синтаксис COM:

HRESULT DrawBitmapFromFile( OLE_HANDLE HWnd, BSTR FileName, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
FileName | \- путь к файлу битмапа.  
  
Подразделы:

(отсутствуют)
