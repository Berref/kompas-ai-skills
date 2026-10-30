# DeleteFile - Удалить файл из хранилища

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_deletestorage.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_createstorage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL DeleteFile( BSTR ApplicationIID, BSTR StorageFileName );

Синтаксис COM:

HRESULT DeleteFile( BSTR ApplicationIID, BSTR StorageFileName, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ApplicationIID | \- GUID приложения,  
---|---  
StorageFileName | \- имя удаляемого файла.  
  
Подразделы:

(отсутствуют)
