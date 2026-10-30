# DrawingContour - Контур, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IDrawingContours ](idrawingcontours.html) > [IDrawingContours - свойства ](idrawingcontours_props.html) |  Scroll [ [ [ ](idrawingcontours_methods.html "К следующему разделу")](idrawingcontours_props.html "На уровень выше")](idrawingcontours_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingcontours.html)

Тип данных: указатель на интерфейс контура [IDrawingContour](idrawingcontour.html)

Синтаксис Automation:

DrawingContour = iObject.DrawingContour( Index ); | Получить свойство([* ](1.html))  
---|---  
DrawingContour = iObject.GetDrawingContour( Index ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DrawingContour( Index, &DrawingContour ) | Получить свойство  
---|---  
  
Входные параметры:

Index (Variant) | \- Индекс узла в коллекции. Поддерживаются следующие типы: \- VT_I4 - индекс линии разреза/сечения.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

Подразделы:

(отсутствуют)
