# Number - Номер марки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) |  Scroll [ [ [ ](imark_textafter.html "К следующему разделу")](imark_props.html "На уровень выше")](imark_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imark.html)

Тип данных: указатель на интерфейс [IText](itext.html)

Синтаксис Automation:

Number = iObject.Number | Получить свойство([* ](1.html))  
---|---  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number(&Number) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Имя марки [IMark::Name](imark_name.html) и номер марки можно использовать для поиска марки в коллекции марок [IMarks](imarks.html).

3\. Для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [IMarks::Mark](imarks_mark.html) нужно передать суммарную строку, включающую в себя имя марки + номер марки без дополнительных разделителей.

Пример:

mark = iMarks.Mark("A1");

где "А" - имя марки

"1" - номер марки

Подразделы:

(отсутствуют)
