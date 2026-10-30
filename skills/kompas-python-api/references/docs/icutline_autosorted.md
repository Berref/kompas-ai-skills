# AutoSorted - Автосортировка

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ICutLine ](icutline.html) > [ICutLine - свойства ](icutline_props.html) |  Scroll [ [ [ ](icutline_autozone.html "К следующему разделу")](icutline_props.html "На уровень выше")](icutline_autosheet.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutline.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- автосортировка включена,  
---|---  
FALSE | \- автосортировка выключена.  
  
Синтаксис Automation:

AutoSorted = Object.AutoSorted | Получить свойство([* ](1.html))  
---|---  
Object.AutoSorted = AutoSorted | Установить свойство ([* ](1.html))  
AutoSorted = Object.GetAutoSorted() | Получить свойство ([**](2.html))  
Object.SetAutoSorted( AutoSorted ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_AutoSorted( &AutoSorted ) | Получить свойство  
---|---  
Object.put_AutoSorted( AutoSorted ) | Установить свойство  
  
Примечание:

1\. По умолчанию значение свойства равно TRUE.

2\. При отключенной опции доступно редактирование основного текста линии разреза/сечения с помощью свойства [ICutLine::Text](icutline_text.html).

Подразделы:

(отсутствуют)
