# Интерфейс IDrawingContour

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](idrawingcontour_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](iconiccurve_setpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс контура.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IDrawingContour](idrawingcontour.html)

[IContour](icontour.html)

Примечание:

1\. Интерфейс позволяет получить и задать свойства объекта "контур".

2\. Получить интерфейс можно, используя свойство [IDrawingContours::DrawingContour](idrawingcontours_drawingcontour.html) или метод [IDrawingContours::Add](idrawingcontours_add.html) интерфейса коллекции контуров.

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

4\. Интерфейс [IContour](icontour.html) являются дополнительным. Его можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IDrawingContour - свойства ](idrawingcontour_props.html)
