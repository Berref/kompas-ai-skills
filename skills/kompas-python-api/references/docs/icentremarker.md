# Интерфейс ICentreMarker

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](icentremarker_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](ibrokenline_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения центра.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ICentreMarker](icentremarker.html)

[IAxisLineParam](iaxislineparam.html)

Описание:

Интерфейс позволяет задавать параметры обозначения центра.

Примечание:

1\. Интерфейс можно получить у коллекции обозначений центра, используя свойство [ICentreMarkers::CentreMarker](icentremarkers_centremarker.html) или метод [ICentreMarkers::Add](icentremarkers_add.html).

2\. После задания параметров обозначения центра требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительный интерфейс [IAxisLineParam](iaxislineparam.html).

Подразделы:

[CentreMarker - свойства ](icentremarker_props.html)
