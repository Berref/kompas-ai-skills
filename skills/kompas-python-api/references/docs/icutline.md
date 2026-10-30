# Интерфейс ICutLine

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](icutline_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](ilinearcentres_deletecentrebypoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс линии разреза/сечения.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ICutLine](icutline.html)

Примечание:

1\. Интерфейс позволяет получить и задать свойства объекта "линия разреза/сечения"

2\. Получить интерфейс можно, используя свойство [ICutLines::CutLine](icutlines_cutline.html) или метод [ICutLines::Add](icutlines_add.html) интерфейса коллекции линий разреза/сечения.

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[ICutLine - свойства ](icutline_props.html)
