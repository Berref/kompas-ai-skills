# SetEdgePointParam - Изменение положения точки ребра

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLinearRuledShell ](isheetmetallinearruledshell.html) > [ISheetMetalLinearRuledShell - методы ](isheetmetallinearruledshell_methods.html) |  Scroll [ [ [ ](isheetmetalrib.html "К следующему разделу")](isheetmetallinearruledshell_methods.html "На уровень выше")](isheetmetallinearruledshell_getedgepointparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinearruledshell.html)

Синтаксис Automation :

BOOL SetEdgePointParam( long EdgeIndex, BOOL StartPoint, double X, double Y, double Z, double * T, IModelObject * AssociateVertex );

Синтаксис COM :

HRESULT SetEdgePointParam( long EdgeIndex, BOOL StartPoint, double X, double Y, double Z, double * T, IModelObject * AssociateVertex, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

EdgeIndex | \- индекс ребра.  
---|---  
StartPoint | \- TRUE - начальная точка, \- FALSE - конечная точка.  
X, Y, Z | \- координаты.  
T | \- параметр кривой.  
AssociateVertex | \- ассоциативный объект  
  
Подразделы:

(отсутствуют)
