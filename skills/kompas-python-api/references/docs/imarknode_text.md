# Text - Текст

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNode ](imarknode.html) > [IMarkNode - свойства ](imarknode_props.html) |  Scroll [ [ [ ](imarknode_methods.html "К следующему разделу")](imarknode_props.html "На уровень выше")](imarknode_reflength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknode.html)

Тип данных: указатель на интерфейс [IText](itext.html)

Синтаксис Automation:

Text = iObject.Text | Получить свойство([* ](1.html))  
---|---  
Text = iObject.GetText() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Text(&Text) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Текст можно использовать для поиска узла марки в коллекции [IMarkNodes](imarknodes.html).

3\. Для поиска в функцию [IMarkNodes::Item](imarknodes_item.html) нужно передать строковое значение текста.

Пример:

node = iMarkNodes.Item("A1");

Подразделы:

(отсутствуют)
