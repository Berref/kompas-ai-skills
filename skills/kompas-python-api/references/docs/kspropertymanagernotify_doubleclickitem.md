# DoubleClickItem - Двойной клик по элементу в списке

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksPropertyManagerNotify/IPropertyManagerNotify ](kspropertymanagernotify.html) > [ksPropertyManagerNotify, IPropertyManagerNotify - события ](propertymanagernotify.html) |  Scroll [ [ [ ](kspropertymanagernotify_getcontextmenutype.html "К следующему разделу")](propertymanagernotify.html "На уровень выше")](kspropertymanagernotify_controlcommand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](propertymanagernotify.html)

Синтаксис Automation:

BOOL DoubleClickItem( IPropertyControl * Control, long Index );

Синтаксис COM:

HRESULT DoubleClickItem( IPropertyControl * Control, long Index, BOOL * Result );

Возвращаемое значение:

TRUE | \- есть локальный результат,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Control | \- указатель на интерфейс элемента панели свойств [IPropertyControl](ipropertycontrol.html),  
---|---  
Index | \- индекс элемента в списке.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
