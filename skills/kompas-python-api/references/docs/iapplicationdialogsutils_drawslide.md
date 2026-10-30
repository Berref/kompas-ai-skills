# DrawSlide - Отрисовать слайд по идентификатору в RCDATA

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawslidefromfile.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawtext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawSlide( OLE_HANDLE HWnd, long sldID, VARIANT Module );

Синтаксис COM:

HRESULT DrawSlide( OLE_HANDLE HWnd, long sldID, VARIANT Module, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
sldID | \- идентификатор слайда в ресурсах,  
Module | \- HINSTANCE приложения.  
  
Подразделы:

(отсутствуют)
