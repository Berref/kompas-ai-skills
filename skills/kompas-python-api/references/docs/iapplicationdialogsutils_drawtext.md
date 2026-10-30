# DrawText - Отрисовать текст

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawslide.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawkompastext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawText( OLE_HANDLE HWnd, BSTR Text );

Синтаксис COM:

HRESULT DrawText( OLE_HANDLE HWnd, BSTR Text, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
Text | \- текст.
