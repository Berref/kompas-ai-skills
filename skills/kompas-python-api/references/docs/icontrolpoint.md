# Интерфейс IControlPoint

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) |  Scroll [ [ [ ](icontrolpoint_points.html "К следующему разделу")](bc2284488.html "На уровень выше")](iconjunctivepoint_setdirectionobject2.html "К предыдущему разделу")  
---|---  
  
Интерфейс контрольной точки.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IPoint3D](ipoint3d.html)

[IControlPoint](icontrolpoint.html)

[ILocalCSObject](ilocalcsobject.html)

Примечание:

1\. Интерфейс можно получить, используя свойство [IControlPoints::ControlPoint](icontrolpoints_controlpoint.html) или [IModelObjects::Item](imodelobjects_item.html) или метод [IControlPoints::Add](icontrolpoints_add.html).

2\. Интерфейс наследует у интерфейса [IPoint3D](ipoint3d.html) пространственной точки все методы и свойства для позиционирования, за исключением следующих:

[Symbol](ipoint3d_symbol.html)() - невозможно установить значения свойства, поскольку стиль отображения точки постоянный; получаемое значение свойства во всех случаях будет одинаковым, равным ksCirclePoint из перечисления [ksAnnotationSymbolEnum](ksannotationsymbolenum.html).

3\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[IControlPoint - свойства ](icontrolpoint_points.html)
