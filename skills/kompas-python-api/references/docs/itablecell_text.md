# Text - Текст

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITableCell ](itablecell.html) > [ITableCell - свойства ](itablecell_props.html) |  Scroll [ [ [ ](bb2377713.html "К следующему разделу")](itablecell_props.html "На уровень выше")](itablecell_row.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itablecell.html)

Тип данных: указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html)

Синтаксис Automation:

Text = Object.Text | Получить свойство([* ](1.html))  
---|---  
Text = Object.GetText() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Text( &Text ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Для ячейки таблицы 2D документа возвращается интерфейс [IText](itext.html).

3\. Для допуска формы возвращается интерфейс [ITextLine](itextline.html).

Подразделы:

(отсутствуют)
