# Интерфейс IProcessInfoWindow

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) |  Scroll [ [ [ ](iprocessinfowindow_props.html "К следующему разделу")](ap1803662.html "На уровень выше")](iprogressbarindicator_stop.html "К предыдущему разделу")  
---|---  
  
Интерфейс информационного окна процесса.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IProcessInfoWindow](iprocessinfowindow.html)

Примечание:

Интерфейс является дополнительным к интерфейсу [IProcessParam](iprocessparam.html) и позволяет создавать информационное окно, принадлежащее процессу с возможностью чтения/записи текста и управления видимостью окна, а также дополнительными свойствами.

Данный интерфейс можно получить у интерфейса IProcessParam процесса, в котором необходимо показать окно, посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html);

Подразделы:

[IProcessInfoWindow - свойства ](iprocessinfowindow_props.html)
