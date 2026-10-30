# InsertionType - Способ вставки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IOleDrawingObject ](ioledrawingobject.html) > [IOleDrawingObject - свойства ](ioledrawingobject_props.html) |  Scroll [ [ [ ](ioledrawingobject_link.html "К следующему разделу")](ioledrawingobject_props.html "На уровень выше")](ioledrawingobject_filename.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ioledrawingobject.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- в виде значка,  
---|---  
FALSE | \- в виде содержимого.  
  
Синтаксис Automation:

InsertionType = Object.InsertionType | Получить свойство ([* ](1.html))  
---|---  
Object.InsertionType = InsertionType | Установить свойство ([* ](1.html))  
InsertionType = Object.GetInsertionType() | Получить свойство ([**](2.html))  
Object.SetInsertionType( InsertionType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_InsertionType( &InsertionType ) | Получить свойство  
---|---  
Object.put_InsertionType( InsertionType ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать способ вставки OLE-объекта.

Подразделы:

(отсутствуют)
