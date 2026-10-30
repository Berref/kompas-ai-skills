# Интерфейс IBase

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](ibase_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](iaxisline_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения базы.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBase](ibase.html)

Примечание:

1\. Интерфейс позволяет получить и задать свойства объекта "база".

2\. Получить интерфейс можно, используя свойство [IBases::Base](ibases_base.html) или метод [IBases::Add](ibases_add.html) интерфейса коллекции обозначений базы.

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IBase - свойства ](ibase_props.html)
