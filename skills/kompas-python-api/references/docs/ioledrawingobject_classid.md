# ClassId - Идентификатор объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IOleDrawingObject ](ioledrawingobject.html) > [IOleDrawingObject - свойства ](ioledrawingobject_props.html) |  Scroll [ [ [ ](ioledrawingobject_filename.html "К следующему разделу")](ioledrawingobject_props.html "На уровень выше")](ioledrawingobject_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ioledrawingobject.html)

Тип данных: BSTR

Синтаксис Automation:

ClassId = Object.ClassId | Получить свойство ([* ](1.html))  
---|---  
Object.ClassId = ClassId | Установить свойство ([* ](1.html))  
ClassId = Object.GetClassId() | Получить свойство ([**](2.html))  
Object.SetClassId( ClassId ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ClassId( &ClassId ) | Получить свойство  
---|---  
Object.put_ClassId( ClassId ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать идентификатор OLE-объекта.

2\. Значение свойства нельзя изменить после создания OLE-объекта.

3\. Если задано ClassId, объект вставляется телом, тип объекта определяется по ClassId.

Подразделы:

(отсутствуют)
