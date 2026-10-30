# CloseProcess - Закрытие процесса при закрытии окна

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessInfoWindow ](iprocessinfowindow.html) > [IProcessInfoWindow - свойства ](iprocessinfowindow_props.html) |  Scroll [ [ [ ](iprocessinfowindow_createwindow.html "К следующему разделу")](iprocessinfowindow_props.html "На уровень выше")](iprocessinfowindow_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessinfowindow.html)

Тип данных: BOOL.

Значения свойства:

TRUE | \- закрывать процесс, которому принадлежит окно,  
---|---  
FALSE | \- не закрывать.  
  
Синтаксис Automation:

CloseProcess = iObject.CloseProcess; | Получить свойство ([* ](1.html))  
---|---  
iObject.CloseProcess = CloseProcess; | Установить свойство ([* ](1.html))  
CloseProcess = iObject.GetCloseProcess(); | Получить свойство([**](2.html))  
iObject.SetCloseProcess( CloseProcess ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CloseProcess( &CloseProcess ); | Получить свойство  
---|---  
iObject->put_CloseProcess( CloseProcess ); | Установить свойство  
  
Подразделы:

(отсутствуют)
