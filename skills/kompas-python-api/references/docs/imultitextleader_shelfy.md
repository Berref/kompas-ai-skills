# ShelfY - Координата начала полки по оси Y

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_shelfdirection.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_shelfx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: double

Синтаксис Automation:

ShelfY = iObject.ShelfY | Получить свойство ([* ](1.html))  
---|---  
iObject.ShelfY = ShelfY | Установить свойство ([* ](1.html))  
ShelfY = iObject.GetShelfY( ) | Получить свойство ([**](2.html))  
iObject.SetShelfY( ShelfY ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ShelfY( &ShelfY ) | Получить свойство  
---|---  
iObject->put_ShelfY( ShelfY ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет установить и получить координату начала полки по Y.

2\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
