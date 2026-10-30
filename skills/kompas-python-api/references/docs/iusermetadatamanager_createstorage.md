# CreateStorage - Создать хранилище файлов приложения

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_deletefile.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_addfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL CreateStorage( BSTR ApplicationIID, BSTR ApplicationDescription, BSTR Version );

Синтаксис COM:

HRESULT CreateStorage( BSTR ApplicationIID, BSTR ApplicationDescription, BSTR Version, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ApplicationIID | \- GUID приложения,  
---|---  
ApplicationDescription | \- имя приложения,  
DestFileName | \- версия хранилища.  
  
Подразделы:

(отсутствуют)
