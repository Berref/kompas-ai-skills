# RegisterLibraryNumber - Зарегистрировать номер продукта на сервере лицензий Компас

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IApplicationLicenseManager ](iapplicationlicensemanager.html) > [IApplicationLicenseManager - методы ](iapplicationlicensemanager_methods.html) |  Scroll [ [ [ ](iapplicationlicensemanager_unregisterlibrarynumber.html "К следующему разделу")](iapplicationlicensemanager_methods.html "На уровень выше")](iapplicationlicensemanager_enablekompasinvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationlicensemanager.html)

Синтаксис Automation:

long RegisterLibraryNumber( long ProductNumber );

Синтаксис COM:

HRESULT RegisterLibraryNumber( long ProductNumber, long * ProductNumbUnicueId );

Возвращаемое значение:

| \- Уникальный идентификатор продукта.  
---|---  
  
Входные параметры:

long ProductNumber | \- номер продукта.  
---|---  
  
Примечание

Уникальный идентификатор продукта используется для разрегистрации продукта функцией [IApplicationLicenseManager::UnRegisterLibraryNumber](iapplicationlicensemanager_unregisterlibrarynumber.html).

Подразделы:

(отсутствуют)
