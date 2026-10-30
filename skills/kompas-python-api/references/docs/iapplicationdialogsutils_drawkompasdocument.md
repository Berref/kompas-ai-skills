# DrawKompasDocument - Отрисовать документ

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawkompasdocumentbypath.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawbitmapfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawKompasDocument( OLE_HANDLE HWnd, IKompasDocument * KompasDocument );

Синтаксис COM:

HRESULT DrawKompasDocument( OLE_HANDLE HWnd, IKompasDocument * KompasDocument, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
KompasDocument | \- документ [IKompasDocument](ikompasdocument.html).  
  
Подразделы:

(отсутствуют)
