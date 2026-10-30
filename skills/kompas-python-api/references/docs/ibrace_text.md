# Text - Текст фигурной скобки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBrace ](ibrace.html) > [IBrace - свойства ](ibrace_props.html) |  Scroll [ [ [ ](ibrace_x1.html "К следующему разделу")](ibrace_props.html "На уровень выше")](ibrace_style.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibrace.html)

Тип данных: указатель на интерфейс текста [IText](itext.html)

Синтаксис Automation:

Text = iObject.Text | Получить свойство([* ](1.html))  
---|---  
Text = iObject.GetText() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Text( &Text ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Текст можно использовать для поиска фигурной скобки в коллекции [IBraces](ibraces.html). Для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [IBraces::Brace](ibraces_brace.html) нужно передать строковое значение текста.

Пример:

Brace = iBraces.Brace("Text");

где "Text" - текст на фигурной скобке;

Подразделы:

(отсутствуют)
