# AddFile - Добавить файл в хранилище

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_createstorage.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL AddFile( BSTR ApplicationIID, BSTR SrcFileName, BSTR DestFileName, BOOL AllowReplacement, BOOL Compress );

Синтаксис COM:

HRESULT AddFile( BSTR ApplicationIID, BSTR SrcFileName, BSTR DestFileName, BOOL AllowReplacement, BOOL Compress, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ApplicationIID | \- GUID приложения,  
---|---  
SrcFileName | \- имя файла в хранилище,  
DestFileName | \- имя файла на диске,  
AllowReplacement | \- перезаписывать,  
Compress | \- добавить со сжатием.  
  
Подразделы:

(отсутствуют)
