# ExistStorage - Проверить наличие хранилища данных приложения

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_extractfile.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_deletestorage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL ExistStorage( BSTR ApplicationIID );

Синтаксис COM:

HRESULT ExistStorage( BSTR ApplicationIID, BOOL * Result );

Возвращаемое значение:

TRUE | \- хранилище существует,  
---|---  
FALSE | \- хранилище не существует.  
  
Входные параметры:

ApplicationIID | \- GUID приложения.  
---|---  
  
Подразделы:

(отсутствуют)
