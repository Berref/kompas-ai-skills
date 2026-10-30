# AddIntersectionOf - Добавить в эскиз пересечение с объектом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_addprojectionof.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

VARIANT AddIntersectionOf( IKompasAPIObject * Object, long LinesStyle, ksAnnotationSymbolEnum PointsStyle, BOOL Extended );

Синтаксис COM:

HRESULT AddIntersectionOf( IKompasAPIObject * Object, long LinesStyle, ksAnnotationSymbolEnum PointsStyle, BOOL Extended, VARIANT * Result );

Возвращаемое значение:

| \- Массив созданных проекционных объектов в виде в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

Object | \- указатель на объект,  
---|---  
LinesStyle | \- стиль линий,  
PointsStyle | \- стиль точек,  
Extended | \- учитывать продолжение.  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
