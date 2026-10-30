# TextUp - Текст сверху

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitNumber ](iunitnumber.html) > [IUnitNumber - свойства ](iunitnumber_props.html) |  Scroll [ [ [ ](iunitnumber_x.html "К следующему разделу")](iunitnumber_props.html "На уровень выше")](iunitnumber_textdown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitnumber.html)

Тип данных: указатель на интерфейс текста [IText](itext.html)

Синтаксис Automation:

TextUp = iObject.TextUp | Получить свойство([* ](1.html))  
---|---  
TextUp = iObject.TextUp() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextUp( &TextUp) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Текст можно использовать для поиска номера узла в коллекции [IUnitNumbers](iunitnumbers.html). Для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [IUnitNumbers::UnitNumber](iunitnumbers_unitnumber.html) нужно передать строковое значение текста.

Пример:

UnitNumber = iUnitNumbers.UnitNumber("TextUp"),

где "TextUp" - текст сверху номера узла.

Подразделы:

(отсутствуют)
