# ApplicationName - Имя приложения

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - свойства ](iapplication_props.html) |  Scroll [ [ [ ](iapplication_buildnumber.html "К следующему разделу")](iapplication_props.html "На уровень выше")](iapplication_activedocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Тип данных: BOOL.

Синтаксис Automation:

ApplicationName = Object.ApplicationName( FullName ) | Получить свойство([* ](1.html))  
---|---  
ApplicationName = Object.GetApplicationName( FullName ) | Получить свойство([**](2.html))  
  
Синтаксис COM:

Object.get_ApplicationName( FullName, &ApplicationName ) | Получить свойство  
---|---  
  
Входные параметры:

BOOL | \- FullName - полное имя,  
---|---  
TRUE | \- полное отображаемое имя приложения в заголовке окна Компас,  
FALSE | \- нелокализованное английское имя.  
  
Подразделы:

(отсутствуют)
