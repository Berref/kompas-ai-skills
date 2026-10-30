# DrawKompasDocumentByPath - Отрисовать документ по имени файла

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogsUtils](iapplicationdialogsutils.html) > [IApplicationDialogsUtils - методы](iapplicationdialogsutils_propers.html) |  Scroll [ [ [ ](iapplicationdialogsutils_drawkompasgroup.html "К следующему разделу")](iapplicationdialogsutils_propers.html "На уровень выше")](iapplicationdialogsutils_drawkompasdocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogsutils.html)

Синтаксис Automation:

BOOL DrawKompasDocumentByPath( OLE_HANDLE HWnd, BSTR FilePath );

Синтаксис COM:

HRESULT DrawKompasDocumentByPath( OLE_HANDLE HWnd, BSTR FilePath, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

HWnd | \- дескриптор окна,  
---|---  
FilePath | \- путь к файлу.  
  
Подразделы:

(отсутствуют)
