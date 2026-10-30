# SaveFile - Выдать диалог и выбрать имя файла для записи

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_selectthread.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_readstring.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

BSTR SaveFile( OLE_HANDLE HWnd, BSTR DefaultExtension, BSTR Filters, BSTR OldFileName, BOOL Preview );

Синтаксис COM:

HRESULT SaveFile( OLE_HANDLE HWnd, BSTR DefaultExtension, BSTR Filters, BSTR OldFileName, BOOL Preview, BSTR * Result );

Возвращаемое значение:

| \- Путь для сохранения или перезаписи файла.  
---|---  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
DefaultExtension | \- расширение имени файла,  
Filters | \- фильтр поиска,  
OldFileName | \- старое имя файла,  
Preview | \- отображать просмотр.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
