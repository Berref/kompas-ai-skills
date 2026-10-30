# ShelfX - Координата начала полки по оси X

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_shelfy.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_form.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: double

Синтаксис Automation:

ShelfX = iObject.ShelfX | Получить свойство ([* ](1.html))  
---|---  
iObject.ShelfX = ShelfX | Установить свойство ([* ](1.html))  
ShelfX = iObject.GetShelfX( ) | Получить свойство ([**](2.html))  
iObject.SetShelfX( ShelfX ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShelfX( &ShelfX ) | Получить свойство  
---|---  
iObject->put_ShelfX( ShelfX ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить координату начала полки по Х.

2\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
