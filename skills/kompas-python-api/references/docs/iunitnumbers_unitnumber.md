# UnitNumber - Номер узла, заданный по индексу, или ссылке

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitNumbers ](iunitnumbers.html) > [IUnitNumbers - свойства ](iunitnumbers_props.html) |  Scroll [ [ [ ](iunitnumbers_methods.html "К следующему разделу")](iunitnumbers_props.html "На уровень выше")](iunitnumbers_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitnumbers.html)

Тип данных: указатель на интерфейс марки [IUnitNumber](iunitnumber.html)

Синтаксис Automation:

UnitNumber = iObject.UnitNumber( index ) | Получить свойство([* ](1.html))  
---|---  
UnitNumber = iObject.GetUnitNumber( index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UnitNumber( index, &UnitNumber ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса могут использоваться следующие типы:

•индекс объекта в коллекции,

•ссылка на объект (reference),

•строковое значение текста сверху [IUnitNumber::TextUp](iunitnumber_textup.html).

Пример:

UnitNumber = iUnitNumbers.UnitNumber("TextUp");

Где "TextUp" - верхний текст номера узла.

Подразделы:

(отсутствуют)
