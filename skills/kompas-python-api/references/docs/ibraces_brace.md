# Brace - Фигурная скобка, заданная по индексу, ссылке или имени и номеру

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBraces ](ibraces.html) > [IBraces - свойства ](ibraces_props.html) |  Scroll [ [ [ ](ibraces_methods.html "К следующему разделу")](ibraces_props.html "На уровень выше")](ibraces_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibraces.html)

Тип данных: указатель на интерфейс фигурной скобки [IBrace](ibrace.html)

Синтаксис Automation:

Brace = iObject.Brace( index ) | Получить свойство([* ](1.html))  
---|---  
Brace = iObject.GetBrace( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Brace( index, &Brace ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | Индекс.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса могут использоваться следующие типы:

•индекс объекта в коллекции,

•ссылка на объект (reference),

•строковое значение текста [IBrace::Text](ibrace_text.html).

Пример:

Brace = iBraces.Brace("Text");

где "Brace" - текст на фигурной скобке.

Подразделы:

(отсутствуют)
