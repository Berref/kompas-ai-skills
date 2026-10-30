# CreateWindow - Управление созданием окна в процессе

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcessInfoWindow ](iprocessinfowindow.html) > [IProcessInfoWindow - свойства ](iprocessinfowindow_props.html) |  Scroll [ [ [ ](iprocessinfowindow_helpid.html "К следующему разделу")](iprocessinfowindow_props.html "На уровень выше")](iprocessinfowindow_closeprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocessinfowindow.html)

Тип данных:BOOL.

Значения свойства:

TRUE | \- создавать окно в процессе,  
---|---  
FALSE | \- не создавать окно.  
  
Синтаксис Automation:

CreateWindow = iObject.CreateWindow; | Получить свойство ([* ](1.html))  
---|---  
iObject.CreateWindow = CreateWindow; | Установить свойство ([* ](1.html))  
CreateWindow = iObject.GetCreateWindow(); | Получить свойство([**](2.html))  
iObject.SetCreateWindow( CreateWindow ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_CreateWindow( &CreateWindow ); | Получить свойство  
---|---  
iObject->put_CreateWindow( CreateWindow ); | Установить свойство  
  
Подразделы:

(отсутствуют)
