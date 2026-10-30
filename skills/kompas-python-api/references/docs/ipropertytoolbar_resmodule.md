# ResModule - Модуль с ресурсами битмапов

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyToolBar ](ipropertytoolbar.html) > [IPropertyToolBar - свойства ](ipropertytoolbar_props.html) |  Scroll [ [ [ ](ipropertytoolbar_methods.html "К следующему разделу")](ipropertytoolbar_props.html "На уровень выше")](ipropertytoolbar_buttonvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertytoolbar.html)

Тип данных: VARIANT.

Синтаксис Automation:

VARIANT ResModule = iObject.ResModule | Получить свойство ([* ](1.html))  
---|---  
iObject.ResModule = ResModule | Установить свойство ([* ](1.html))  
VARIANT ResModule = iObject.GetResModule() | Получить свойство([**](2.html))  
iObject.SetResModule (ResModule) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ResModule (&ResModule) | Получить свойство  
---|---  
iObject->put_ResModule (ResModule) | Установить свойство  
  
Примечание:

1\. Значение свойства ResModule необходимо устанавливать до добавления кнопок.

2\. Модуль с ресурсами может быть задан строкой (имя файла ресурса) или значением типа long (идентификатор ресурса).

Подразделы:

(отсутствуют)
