# Интерфейс IContour

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](icontour_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](istraightslot_setpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс контура.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IContour](icontour.html)

Описание:

Позволяет создавать и редактировать контур.

Примечание:

1\. Интерфейс можно получить у интерфейса мультилинии с помощью свойства [IMultiline::BaseContour](imultiline_basecontour.html).

2\. Интерфейс IContour является дополнительным для интерфейса [IDrawingContour](idrawingcontour.html). Его можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html) у мультилинии.

Подразделы:

[IContour - свойства ](icontour_props.html)

[IContour - методы ](icontour_methods.html)
