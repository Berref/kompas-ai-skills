# Интерфейс IConjunctivePoint

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) |  Scroll [ [ [ ](iconjunctivepoint_props.html "К следующему разделу")](bc2284488.html "На уровень выше")](bc2284488.html "К предыдущему разделу")  
---|---  
  
Интерфейс присоединительной точки.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IPoint3D](ipoint3d.html)

[IConjunctivePoint](iconjunctivepoint.html)

[ILocalCSObject](ilocalcsobject.html)

Примечание:

1\. Интерфейс можно получить, используя свойство [IConjunctivePoints::ConjunctivePoint](iconjunctivepoints_conjunctivepoint.html) или [IModelObjects::Item](imodelobjects_item.html) или метод [IConjunctivePoints::Add](iconjunctivepoints_add.html).

2\. Интерфейс наследует у интерфейса [IPoint3D](ipoint3d.html) пространственной точки все методы и свойства для позиционирования, за исключением следующих:

[Symbol](ipoint3d_symbol.html)() - невозможно установить значения свойства, поскольку стиль отображения точки постоянный; получаемое значение свойства во всех случаях будет одинаковым, равным ksCirclePoint из перечисления [ksAnnotationSymbolEnum](ksannotationsymbolenum.html).

3\. С помощью метода [IUnknown::QueryInterface](recomendation.html) у интерфейса можно получить интерфейс подчиненного объекта ЛСК [ILocalCSObject](ilocalcsobject.html).

Подразделы:

[IConjunctivePoint - свойства ](iconjunctivepoint_props.html)

[IConjunctivePoint - методы ](iconjunctivepoint_methods.html)
