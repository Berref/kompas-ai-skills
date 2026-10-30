# MarkSize - Размер марки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxis ](ibuildingaxis.html) > [IBuildingAxis - свойства ](ibuildingaxis_props.html) |  Scroll [ [ [ ](ibuildingaxis_stroke.html "К следующему разделу")](ibuildingaxis_props.html "На уровень выше")](ibuildingaxis_interval.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxis.html)

Тип данных: double

Синтаксис Automation:

MarkSize = iObject.MarkSize | Получить свойство([* ](1.html))  
---|---  
iObject.MarkSize = MarkSize | Установить свойство ([* ](1.html))  
MarkSize = iObject.GetMarkSize() | Получить свойство ([**](2.html))  
iObject.SetMarkSize(MarkSize) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_MarkSize(&MarkSize) | Получить свойство  
---|---  
iObject->put_MarkSize( MarkSize) | Установить свойство  
  
Примечание:

Значения параметра пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
