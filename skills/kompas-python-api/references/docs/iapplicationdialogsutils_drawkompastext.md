# DrawKompasText - Отрисовать текст Компас

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawtext.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawkompasgroup.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawKompasText( OLE_HANDLE HWnd, IKompasAPIObject * Text );

Синтаксис COM:

HRESULT DrawKompasText( OLE_HANDLE HWnd, IKompasAPIObject * Text, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
Text | \- текст [IText](itext.html).  
  
Подразделы:

(отсутствуют)
