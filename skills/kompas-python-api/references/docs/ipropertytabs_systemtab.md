# SystemTab - Интерфейс системной вкладки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyToolBar ](ipropertytoolbar.html) > [Интерфейс IPropertyTabs ](ipropertytabs.html) > [IPropertyTabs - свойства ](ipropertytabs_props.html) |  Scroll [ [ [ ](ipropertytabs_methods.html "К следующему разделу")](ipropertytabs_props.html "На уровень выше")](ipropertytabs_item.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertytabs.html)

Интерфейс системной вкладки.

Тип данных: указатель на интерфейс [IPropertyTab](ipropertytab.html).

Синтаксис Automation:

SystemTab = iObject.SystemTab | Получить свойство ([* ](1.html))  
---|---  
SystemTab = iObject.GetSystemTab() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_SystemTab(&SystemTab) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Системную вкладку можно получить для процессных параметров. Для системной вкладки можно установить свойства:

•Visible - видимость закладки Панели свойств, т.е. сделать закладку невидимой. Caption - изменить заголовок вкладки Панели свойств.

•Caption - заголовок вкладки Панели свойств.

•Image - установить битмап на вкладке.

•ResModule - модуль с ресурсом битмапа, если битмап задан в виде идентификатора ресурса библиотеки.

Подразделы:

(отсутствуют)
