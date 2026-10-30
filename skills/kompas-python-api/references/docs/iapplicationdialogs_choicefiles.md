# ChoiceFiles - Выдать диалог и выбрать группу файлов для чтения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IApplicationDialogs ](iapplicationdialogs.html) > [IApplicationDialogs - методы ](iapplicationdialogs_methods.html) |  Scroll [ [ [ ](iapplicationdialogs_choicematerial.html "К следующему разделу")](iapplicationdialogs_methods.html "На уровень выше")](iapplicationdialogs_choicefile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationdialogs.html)

Синтаксис Automation:

VARIANT ChoiceFiles( OLE_HANDLE HWnd, BSTR DefaultExtension, BSTR Filters, BSTR StartDirectory, ksSystemPathTypeEnum DirectoryType, BOOL Preview );

Синтаксис COM:

HRESULT ChoiceFiles( OLE_HANDLE HWnd, BSTR DefaultExtension, BSTR Filters, BSTR StartDirectory, ksSystemPathTypeEnum DirectoryType, BOOL Preview, VARIANT * Result );

Возвращаемое значение:

| \- Список выбранных файлов.  
---|---  
  
Входные параметры:

HWnd | \- дескриптор окна владельца,  
---|---  
DefaultExtension | \- расширение имени файла,  
Filters | \- фильтр поиска,  
StartDirectory | \- стартовая директория,  
DirectoryType | \- тип системной директории,  
Preview | \- отображать просмотр.  
  
Версия Компас v23

Подразделы:

(отсутствуют)
