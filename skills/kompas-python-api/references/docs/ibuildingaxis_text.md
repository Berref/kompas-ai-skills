# Text - Текст

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxis ](ibuildingaxis.html) > [IBuildingAxis - свойства ](ibuildingaxis_props.html) |  Scroll [ [ [ ](ibuildingaxis_textafter.html "К следующему разделу")](ibuildingaxis_props.html "На уровень выше")](ibuildingaxis_stroke.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxis.html)

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

2\. Значение свойства можно использовать для поиска марки в коллекции строительных осей [IBuildingAxes](ibuildingaxes.html), а также для поиска в функции [IDrawingObjects::Item](idrawingobjects_item.html) или [IBuildingAxes::BuildingAxis](ibuildingaxes_buildingaxis.html) строкового значения текста.

Пример:

axis = iBuildingAxes.Axis("A1");

Подразделы:

(отсутствуют)
