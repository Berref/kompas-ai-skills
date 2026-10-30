# CreateObject - Создание объекта

[API интерфейсов. Версия 7](applicate.html) > [Интерфейсы событий ](sobutiy.html) > [Интерфейс ksDrawingObjectNotify/IDrawingObjectNotify ](ksdrawingobjectnotify.html) > [ksDrawingObjectNotify - события ](bo1866135.html) |  Scroll [ [ [ ](ksdrawingobjectnotify_delete.html "К следующему разделу")](bo1866135.html "На уровень выше")](ksdrawingobjectnotify_copy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksdrawingobjectnotify.html).

Синтаксис Automation:

BOOL CreateObject ( VARIANT Obj );

iObj | \- VARIANT с типом VT_DISPATCH, если событие генерируется для одного объекта, \- массив SafeArray объектов, если событие генерируется для более чем одного объекта.  
---|---  
  
Возвращаемое значение:

| \- Не используется.  
---|---  
  
Примечание:

1\. Индекс метода задан в перечислении событий объектов графических документов [ksObject2DNotifyEnum](ksobject2dnotifyenum.html).

2\. Контейнером событий ksDrawingObjectNotify может использоваться объект графического документа [IDrawingObject](idrawingobject.html) и коллекция объектов [IDrawingObjects](idrawingobjects.html).

Подразделы:

(отсутствуют)
