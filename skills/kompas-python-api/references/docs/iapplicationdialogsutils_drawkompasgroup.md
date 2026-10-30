# DrawKompasGroup - Отрисовать группу объектов

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawkompastext.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawkompasdocumentbypath.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawKompasGroup( OLE_HANDLE HWnd, IDrawingGroup * Group );

Синтаксис COM:

HRESULT DrawKompasGroup( OLE_HANDLE HWnd, IDrawingGroup * Group, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
Group | \- группа объектов [IDrawingGroup](idrawinggroup.html).  
  
Подразделы:

(отсутствуют)
