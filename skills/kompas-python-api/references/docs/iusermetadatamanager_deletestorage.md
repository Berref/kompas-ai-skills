# DeleteStorage - Удалить хранилище файлов приложения

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_existstorage.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_deletefile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL DeleteStorage( BSTR ApplicationIID );

Синтаксис COM:

HRESULT DeleteStorage( BSTR ApplicationIID, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ApplicationIID | \- GUID приложения.  
---|---  
  
Подразделы:

(отсутствуют)
