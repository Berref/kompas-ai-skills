# IsInitialObject - Проверка - является ли объект исходным для массива

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_issuitableobject.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_getexternallocalcooordinatesystem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

BOOL IsInitialObject( IModelObject * Object );

Синтаксис COM:

HRESULT IsInitialObject( IModelObject * Object, BOOL * Result );

Возвращаемое значение:

TRUE | \- объект является исходным,  
---|---  
FALSE | \- объект не является исходным.  
  
Входные параметры:

Object | \- указатель на объект.  
---|---  
  
Подразделы:

(отсутствуют)
