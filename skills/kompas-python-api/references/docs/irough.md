# Интерфейс IRough

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](irough_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](idrawingtext_y.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения шероховатости.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IRough](irough.html)

[IRoughParams](iroughparams.html)

Описание:

Интерфейс позволяет получить и задать свойства обозначения шероховатости.

Интерфейс можно получить у коллекции обозначений шероховатости, используя свойство [IRoughs::Rough](iroughs_rough.html) или метод [IRoughs::Add](iroughs_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейс [IRoughParams](iroughparams.html) является дополнительным. Его можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IRough - свойства ](irough_props.html)
