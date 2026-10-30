# FlagVisible - Получить значения видимости колонок в виде массива SAFEARRAY VT_ARRAY | VT_BOOL

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - свойства ](iattribute_props.html) |  Scroll [ [ [ ](iattribute_objects.html "К следующему разделу")](iattribute_props.html "На уровень выше")](iattribute_columnkey.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Тип данных: VARIANT типа VT_ARRAY | VT_BOOL

Синтаксис Automation:

FlagVisible = Object.FlagVisible | Получить свойство ([* ](1.html))  
---|---  
FlagVisible = Object.GetFlagVisible() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_FlagVisible( &FlagVisible ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать значения видимости колонок атрибута.

2\. Для задания значений видимости колонок следует использовать метод [IAttribute::SetFlagVisible](iattribute_setflagvisible.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
