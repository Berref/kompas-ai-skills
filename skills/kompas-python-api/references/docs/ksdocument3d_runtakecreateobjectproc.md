# RunTakeCreateObjectProc - Запустить подчиненный режим создания объектов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_save.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_removemateconstraint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL RunTakeCreateObjectProc( long processType, LPDISPATCH takeObject, BOOL needCreateTakeObj, BOOL lostTakeObj )

Синтаксис COM:

BOOL RunTakeCreateObjectProc( long processType, LPUNKNOWN takeObject, BOOL needCreateTakeObj, BOOL lostTakeObj );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

ProcessType | \- тип подпроцесса,  
---|---  
TakeObject | \- указатель на интерфейс редактируемого в подпроцессе объекта.  
NeedCreateTakeObj | \- необходимость создания объекта в подпроцессе,  
LostTakeObj | \- TRUE - фиксировать параметры создаваемого объекта.  
  
Функция позволяет запустить следующие подпроцессы

prPoint3D | Точка 3D  
---|---  
prAxisByDirection | Ось через вершину по объекту  
prCAxis2Points | Ось по двум точкам  
prCAxis2Planes | Ось по двум плоскостям  
prCAxisConeface | Ось конической грани  
prCAxisEdge | Ось, проходящая через ребро  
prContour3D | Контур 3D  
prLocalCoordinateSystem | Локальная система координат  
prIsoparamCurve | Изопараметрическая кривая  
prEquidistant3D | Эквидистанта 3D  
prCPlaneOffset | Смещённая плоскость  
prCPlane3Points | Плоскость по 3-м точкам  
prCPlaneAngle | Плоскость под углом  
prCPlaneEdgePoint | Плоскость через ребро и вершину  
prCPlaneParallel | Плоскость через вершину параллельно другой плоскости  
prCPlanePerpendicular | Плоскость через вершину перпендикулярно ребру  
prCPlaneNormalToSurface | Нормальная плоскость  
prCPlaneTangentToSurface | Касательная плоскость  
prCPlaneLineToEdge | Плоскость через ребро параллельно/перпендикулярно другому ребру  
prCPlaneLineToFlat | Плоскость через ребро параллельно/перпендикулярно грани  
prCPlaneMiddle | Средняя плоскость  
prCPlaneTangentAtPoint | Плоскость, касательная к грани в точке  
prCPlaneAtCurve | Плоскость через плоскую кривую  
prMateParallel | Сопряжения компонентов - Параллельность  
prMatePerpendicular | Сопряжения компонентов - Перпендикулярность  
prMateOnDistance | Сопряжения компонентов - На расстоянии  
prMateOnAngle | Сопряжения компонентов - Под углом  
prMateTangent | Сопряжения компонентов - Касание  
prMateConcentric | Сопряжения компонентов - Соосность  
prMateCoincident | Сопряжения компонентов - Совпадение  
prMateSymmetry | Сопряжения компонентов - Симметрия  
prMateDependent | Сопряжения компонентов - Зависимое положение  
  
Подразделы:

(отсутствуют)
