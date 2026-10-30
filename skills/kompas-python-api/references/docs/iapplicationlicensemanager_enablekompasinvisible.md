# EnableKompasInvisible - Установить ключ для КОМПАС- Invisible

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IApplicationLicenseManager ](iapplicationlicensemanager.html) > [IApplicationLicenseManager - методы ](iapplicationlicensemanager_methods.html) |  Scroll [ [ [ ](iapplicationlicensemanager_registerlibrarynumber.html "К следующему разделу")](iapplicationlicensemanager_methods.html "На уровень выше")](iapplicationlicensemanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationlicensemanager.html)

Синтаксис Automation:

BOOL EnableKompasInvisible( BSTR Key, BSTR Signature );

Синтаксис COM:

HRESULT EnableKompasInvisible( BSTR Key, BSTR Signature, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

Key | \- имя (передается из внешнего приложения),  
---|---  
Signature | \- лицензия для проверки подлинности (передается из внешнего приложения).  
  
Подразделы:

(отсутствуют)
