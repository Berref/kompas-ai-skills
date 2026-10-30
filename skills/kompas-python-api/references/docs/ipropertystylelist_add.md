# Add - Добавить массив стилей в список

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyStyleList ](ipropertystylelist.html) > [IPropertyStyleList - методы ](ipropertystylelist_methods.html) |  Scroll [ [ [ ](ipropertystylelist_clearlist.html "К следующему разделу")](ipropertystylelist_methods.html "На уровень выше")](ipropertystylelist_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertystylelist.html)

Синтаксис Automation:

BOOL Add( VARIANT Styles );

Синтаксис COM:

HRESULT Add( VARIANT Styles, BOOL * Result );

Входные параметры:

Styles | \- список стилей.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Если добавляется один стиль, его можно передать как VT_I4.

Если требуется добавить несколько стилей, то нужно создать массив VT_ARRAY | VT_I4.

Подразделы:

(отсутствуют)
