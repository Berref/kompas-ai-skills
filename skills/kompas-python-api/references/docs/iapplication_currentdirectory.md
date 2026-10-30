# CurrentDirectory - Текущий каталог

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Интерфейс IApplication ](iapplication.html) > [IApplication - свойства ](iapplication_props.html) |  Scroll [ [ [ ](iapplication_dictionary.html "К следующему разделу")](iapplication_props.html "На уровень выше")](iapplication_converter.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iapplication.html)

Тип данных: BSTR

Синтаксис Automation:

CurrentDirectory = Object.CurrentDirectory | Получить свойство ([* ](1.html))  
---|---  
Object.CurrentDirectory = CurrentDirectory | Установить свойство ([* ](1.html))  
CurrentDirectory = Object.GetCurrentDirectory() | Получить свойство([**](2.html))  
Object.SetCurrentDirectory( CurrentDirectory ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_CurrentDirectory( &CurrentDirectory ) | Получить свойство,  
---|---  
Object.put_CurrentDirectory( CurrentDirectory ) | Установить свойство.  
  
Примечание

При работе функций КОМПАС может изменяться текущий рабочий каталог приложения.

Свойство позволяет получить/установить текущий рабочий каталог.

Версия: Компас v20

Подразделы:

(отсутствуют)
