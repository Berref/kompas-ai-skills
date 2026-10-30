# IsExistFile - Проверить наличие файла в хранилище

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](bb2325661.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_getallfilenames.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL IsExistFile( BSTR ApplicationIID, BSTR StorageFileName );

Синтаксис COM:

HRESULT IsExistFile( BSTR ApplicationIID, BSTR StorageFileName, BOOL * Result );

Возвращаемое значение:

TRUE | \- файл существует,  
---|---  
FALSE | \- файл не существует.  
  
Входные параметры:

ApplicationIID | \- GUID приложения,  
---|---  
StorageFileName | \- имя удаляемого файла.  
  
Подразделы:

(отсутствуют)
