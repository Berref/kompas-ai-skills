# Интерфейс IOleDrawingObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) |  Scroll [ [ [ ](ioledrawingobject_props.html "К следующему разделу")](bb2331024.html "На уровень выше")](iinsertionview_viewnumber.html "К предыдущему разделу")  
---|---  
  
Интерфейс OLE-объекта.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IOleDrawingObject](ioledrawingobject.html)

Описание:

Интерфейс позволяет задавать параметры OLE-объекта.

Примечание:

1\. Интерфейс можно получить у коллекции OLE-объектов, используя свойство [IOleDrawingObjects::OleDrawingObject](ioledrawingobjects_oledrawingobject.html) или метод [IOleDrawingObjects::Add](ioledrawingobjects_add.html).

2\. После задания параметров OLE-объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. OLE-объект можно создать двумя способами:

•внедрить телом в документ (для этого требуется задать свойство [IOleDrawingObject::ClassId](ioledrawingobject_classid.html)),

•вставить по ссылке из файла (для этого требуется задать свойство [IOleDrawingObject::FileName](ioledrawingobject_filename.html)).

Подразделы:

[IOleDrawingObject - свойства ](ioledrawingobject_props.html)

[IOleDrawingObject - методы ](ioledrawingobject_methods.html)
