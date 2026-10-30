# Интерфейс IKompasError

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Информация об ошибках ](ap1713366.html) |  Scroll [ [ [ ](ikompaserror_props.html "К следующему разделу")](ap1713366.html "На уровень выше")](ap1713366.html "К предыдущему разделу")  
---|---  
  
Интерфейс информации об ошибке системы КОМПАС.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasError](ikompaserror.html)

Описание:

1\. Позволяет получить информацию об ошибке, возникшей при работе API системы КОМПАС.

2\. Системные ошибки описаны двумя перечислениями: [Ошибки API ErrorType](errortype.html) и [Ошибки 3D API ErrorType3d](errortype3d.html)

В случае возникновения фатальных ошибок большинство методов интерфейсов и экспортных функций API КОМПАС выполняться не будут.

Если в результате работы библиотеки возникает ошибка, то ее можно снять вызовом одного из следующих свойств и методов: [Description](ikompaserror_description.html), [Report](ikompaserror_report.html) или[ Clear](ikompaserror_clear.html). Если указанные свойства и методы не вызывались, сообщение об ошибке будет автоматически выведено после завершения выполнения команды библиотеки.

Примечание:

Данный интерфейс может быть получен от интерфейса приложения [IApplication](iapplication.html) с помощью свойства [IApplication::KompasError](iapplication_kompaserror.html).

Подразделы:

[IKompasError - свойства ](ikompaserror_props.html)

[IKompasError - методы ](ikompaserror_methods.html)
