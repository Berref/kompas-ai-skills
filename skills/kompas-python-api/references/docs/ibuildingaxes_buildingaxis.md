# BuildingAxis - Ось, заданная по индексу, ссылке или имени

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxes ](ibuildingaxes.html) > [IBuildingAxes - свойства ](ibuildingaxes_props.html) |  Scroll [ [ [ ](ibuildingaxes_methods.html "К следующему разделу")](ibuildingaxes_props.html "На уровень выше")](ibuildingaxes_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxes.html)

Тип данных: указатель на интерфейс оси [IBuildingAxis](ibuildingaxis.html)

Синтаксис Automation:

Axis = iObject.BuildingAxis(index) | Получить свойство([* ](1.html))  
---|---  
Axis = iObject.GetBuildingAxis(index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BuildingAxis(index, &Axis) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | Индекс.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса могут использоваться следующие типы:

•Индекс объекта в коллекции,

•Ссылка на объект (reference),

•Строковое значение текста строительной оси [IBuildingAxis::Text](ibuildingaxis_text.html).

Пример:

axis = iBuildingAxes.BuildingAxis("A1")

где "А1" - текст оси

Подразделы:

(отсутствуют)
