# StorageInfo - Получить данные из StorageInfo

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Хранилища ](ba1953503.html) > [Интерфейс IUserMetadataManager ](iusermetadatamanager.html) > [IUserMetadataManager - свойства ](iusermetadatamanager_props.html) |  Scroll [ [ [ ](iusermetadatamanager_methods.html "К следующему разделу")](iusermetadatamanager_props.html "На уровень выше")](iusermetadatamanager_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iusermetadatamanager.html)

Тип данных: BSTR

Синтаксис Automation:

StorageInfo = Object.StorageInfo(ApplicationIID, ParameterName ) | Получить свойство ([* ](1.html))  
---|---  
Object.StorageInfo( ApplicationIID, ParameterName ) = Visible | Установить свойство ([* ](1.html))  
StorageInfo= Object.GetStorageInfo( ApplicationIID, ParameterName ) | Получить свойство ([**](2.html))  
Object.SetStorageInfo( ApplicationIID, ParameterName, StorageInfo ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_StorageInfo( ApplicationIID, ParameterName, &StorageInfo) | Получить свойство  
---|---  
Object.put_StorageInfo( ApplicationIID, ParameterName, StorageInfo ) | Установить свойство  
  
Входные параметры:

BSTR ApplicationIID | \- GUID приложения,  
---|---  
BSTR ParameterName | \- имя параметр.  
  
Примечание:

Свойство позволяет устанавливать и получать имя или версию хранилища:

•для получения имени ParameterName - "storageInfo.appName",

•для получения версии - "storageInfo.appVersion".

Подразделы:

(отсутствуют)
