# ExtractFile - Извлечь файл из хранилища

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_getallfilenames.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_existstorage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

BOOL ExtractFile( BSTR ApplicationIID, BSTR SrcFileName, BSTR DestFileName, BOOL AllowReplacement );

Синтаксис COM:

HRESULT ExtractFile( BSTR ApplicationIID, BSTR SrcFileName, BSTR DestFileName, BOOL AllowReplacement, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ApplicationIID | \- GUID приложения,  
---|---  
SrcFileName | \- имя файла в хранилище,  
DestFileName | \- имя файла на диске,  
AllowReplacement | \- перезаписывать.  
  
Подразделы:

(отсутствуют)
