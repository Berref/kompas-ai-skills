# LibraryStatus - Получить текущий статус продукта по номеру

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Менеджер лицензий ](ap1981077.html) > [Интерфейс IApplicationLicenseManager ](iapplicationlicensemanager.html) > [IApplicationLicenseManager - свойства ](iapplicationlicensemanager_propers.html) |  Scroll [ [ [ ](iapplicationlicensemanager_librarytrialstatus.html "К следующему разделу")](iapplicationlicensemanager_propers.html "На уровень выше")](iapplicationlicensemanager_librarylocalstatus.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplicationlicensemanager.html)

Тип данных: из перечисления [ksProtectProductStatusEnum](ksprotectproductstatusenum.html).

Синтаксис Automation:

LibraryStatus = Object.LibraryStatus( ProductNumber ) | Получить свойство ([* ](1.html))  
---|---  
LibraryStatus = Object.GetLibraryStatus( ProductNumber ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_LibraryStatus( ProductNumber, &LibraryStatus ) | Получить свойство ([* ](1.html))  
---|---  
  
Входные параметры:

long ProductNumber | \- номер продукта.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
