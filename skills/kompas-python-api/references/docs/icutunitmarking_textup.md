# TextUp - Текст вверху

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс ICutUnitMarking ](icutunitmarking.html) > [ICutUnitMarking - свойства ](icutunitmarking_props.html) |  Scroll [ [ [ ](icutunitmarking_methods.html "К следующему разделу")](icutunitmarking_props.html "На уровень выше")](icutunitmarking_textdown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutunitmarking.html)

Тип данных: указатель на интерфейс [IText](itext.html)

Синтаксис Automation:

TextUp = iObject.TextUp | Получить свойство([* ](1.html))  
---|---  
TextUp = iObject.GetTextUp() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_TextUp(&TextUp) | Получить свойство  
---|---  
  
Описание.

Свойство Текст вверху можно использовать для поиска обозначения узла в сечении в коллекции [ICutUnitMarkings](icutunitmarkings.html). Для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [ICutUnitMarkings::CutUnitMarking](icutunitmarkings_cutunitmarking.html) нужно передать строковое значение текста.

Пример:

сutUnitMarking = iCutUnitMarkings.CutUnitMarking("A1");

где "A1" - Текст вверху

Примечание.

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
