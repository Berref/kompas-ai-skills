# TextUp - Текст вверху

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IUnitMarking ](iunitmarking.html) > [IUnitMarking - свойства ](iunitmarking_props.html) |  Scroll [ [ [ ](iunitmarking_width.html "К следующему разделу")](iunitmarking_props.html "На уровень выше")](iunitmarking_textdown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunitmarking.html)

Тип данных: указатель на интерфейс [IText](itext.html)

Синтаксис Automation:

TextUp = iObject.TextUp | Получить свойство([* ](1.html))  
---|---  
TextUp = iObject.GetTextUp() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextUp(&TextUp) | Получить свойство  
---|---  
  
Описание.

Свойство Текст вверху можно использовать для поиска обозначения узла в коллекции [IUnitMarkings](iunitmarkings.html). Для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [IUnitMarkings::UnitMarking](iunitmarkings_unitmarking.html) нужно передать строковое значение текста.

Пример:

UnitMarking = IUnitMarkings.UnitMarking("A1");

где "A1" - Текст вверху

Примечание.

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
