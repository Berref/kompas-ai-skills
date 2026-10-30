# GetContextMenuType - CLLBACK для получения типа контекстного меню

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_fillcontextpanel.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_doubleclickitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL GetContextMenuType( long LX, long LY, long * ContextMenuType );

Синтаксис COM:

HRESULT GetContextMenuType( long LX, long LY, long * ContextMenuType, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

LX | \- координаты курсора,  
---|---  
LY | \- координаты курсора.  
ContextMenuType | \- тип контекстного меню.  
  
Подразделы:

(отсутствуют)
