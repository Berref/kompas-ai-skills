# GetNurbsPoints3DParams - Получить параметры точек для Nurbs 3D

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [Параметры трехмерных NURBS (Интерфейсы ksNurbs3dParam,INurbs3dParam) ](ksnurbs3dparam.html) > [INurbs3dParam - методы ](ksnurbs3dparam_methods.html) |  Scroll [ [ [ ](ksnurbs3dparam_nurbsknotcollection.html "К следующему разделу")](ksnurbs3dparam_methods.html "На уровень выше")](ksnurbs3dparam_getminmaxparameters.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbs3dparam.html)

Синтаксис Automation:

BOOL GetNurbsPoints3DParams( BOOL unClamped, VARIANT * points, VARIANT * weights, VARIANT * knots );

Синтаксис COM:

BOOL GetNurbsPoints3DParams( BOOL unClamped, VARIANT * points, VARIANT * weights, VARIANT * knots );

Входные параметры:

unClamped | \- true - вернуть параметры точек для замкнутого представления, \- false - вернуть параметры точек для разомкнутого представления.  
---|---  
  
Выходные параметры:

points | \- координаты точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
---|---  
weights | \- веса точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8,  
knots | \- узлы точек - массив SafeArray вещественных чисел VT_ARRAY | VT_R8.  
  
Примечания:

Координаты точек в полученном массиве лежат в следующей последовательности:

x0, y0, z0, x1, y1, z1, ...xi, yi, zi.

Подразделы:

(отсутствуют)
