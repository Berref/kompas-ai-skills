# ListVal - Список значений

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Свойства ](ba1946975.html) > [Интерфейс IProperty ](iproperty.html) > [IProperty - свойства ](iproperty_props.html) |  Scroll [ [ [ ](iproperty_maxvalue.html "К следующему разделу")](iproperty_props.html "На уровень выше")](iproperty_isvariable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iproperty.html)

Тип данных: VARIANT

Синтаксис Automation:

ListVal = Object.ListVal | Получить свойство ([* ](1.html))  
---|---  
Object.ListVal = ListVal | Установить свойство ([* ](1.html))  
ListVal = Object.GetListVal() | Получить свойство ([**](2.html))  
Object.SetListVal( ListVal ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ListVal( &ListVal ) | Получить свойство  
---|---  
Object.put_ListVal( ListVal ) | Установить свойство  
  
Свойство позволяет задать и получить список значений свойства.

Примечание:

Для свойства с типом данных ksPropertyDataTypeDouble значение должно иметь тип VT_ARRAY|VT_R8.

Для свойства с типом данных ksPropertyDataTypeLong значение должно иметь тип VT_ARRAY|VT_I4.

Для свойства с типом данных ksPropertyDataTypeString значение должно иметь тип VT_ARRAY|VT_BSTR.

Подразделы:

(отсутствуют)
