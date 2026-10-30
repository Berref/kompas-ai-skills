# AutoHideMode - Свернутость Панели свойств

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyManager ](ipropertymanager.html) > [IPropertyManager - свойства ](ipropertymanager_props.html) |  Scroll [ [ [ ](ipropertymanager_caption.html "К следующему разделу")](ipropertymanager_props.html "На уровень выше")](ipropertymanager_activateoncreate.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertymanager.html)

Тип данных: BOOL.

Синтаксис Automation:

AutoHideMode = iObject.AutoHideMode; | Получить свойство ([* ](1.html))  
---|---  
iObject.AutoHideMode = AutoHideMode; | Установить свойство ([* ](1.html))  
AutoHideMode = iObject.GetAutoHideMode(); | Получить свойство([**](2.html))  
iObject.SetAutoHideMode( AutoHideMode ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_AutoHideMode( &AutoHideMode ); | Получить свойство  
---|---  
iObject->put_AutoHideMode( AutoHideMode ); | Установить свойство  
  
Значения свойства:

TRUE | \- панель свернута,  
---|---  
FALSE | \- панель развернута.  
  
Примечание:

Позволяет получать и устанавливать свойство, определяющее, свернута панель или нет.

Подразделы:

(отсутствуют)
