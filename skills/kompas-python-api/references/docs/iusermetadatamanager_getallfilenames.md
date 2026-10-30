# GetAllFilenames - Получить список файлов приложения

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - методы ](iusermetadatamanager_methods.html) |  Scroll [ [ [ ](iusermetadatamanager_isexistfile.html "К следующему разделу")](iusermetadatamanager_methods.html "На уровень выше")](iusermetadatamanager_extractfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Синтаксис Automation:

VARIANT GetAllFilenames( BSTR ApplicationIID );

Синтаксис COM:

HRESULT GetAllFilenames( BSTR ApplicationIID, VARIANT * Result );

Возвращаемое значение:

| \- массив VT_ARRAY | VT_BSTR имен файлов в хранилище.  
---|---  
  
Входные параметры:

ApplicationIID | \- GUID приложения.  
---|---  
  
Подразделы:

(отсутствуют)
