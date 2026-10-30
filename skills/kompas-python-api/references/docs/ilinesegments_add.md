# Add - Создать отрезок и добавить его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ILineSegments ](ilinesegments.html) > [ILineSegments - методы ](ilinesegments_methods.html) |  Scroll [ [ [ ](imultilines.html "К следующему разделу")](ilinesegments_methods.html "На уровень выше")](ilinesegments_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegments.html)

Синтаксис Automation:

LPDISPATCH Add;

Синтаксис COM:

HRESULT Add( [out, retval] ILineSegment** Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ILineSegment](ilinesegment.html) отрезка.  
---|---  
  
Примечание:

Метод позволяет добавить отрезок в коллекцию. После получения нового интерфейса нужно задать параметры отрезка и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
