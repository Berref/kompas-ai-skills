# GetMinMaxParameters - Получить параметры поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_getnurbsparams.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_getedgescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

BOOL GetMinMaxParameters (BOOL closedV, BOOL closedU, double * uMin, double * uMax, double * vMin, double * vMax)

Синтаксис COM:

BOOL GetMinMaxParameters (BOOL closedV, BOOL closedU, double * uMin, double * uMax, double * vMin, double * vMax)

Входные параметры:

closedV | \- TRUE - получение параметров для замкнутого по V представления, \- FALSE - получение параметров для разомкнутого по V представления,  
---|---  
closedU | \- TRUE - получение параметров для замкнутого по U представления, \- FALSE - получение параметров для разомкнутого по V представления.  
  
Выходные параметры:

uMin | \- значение минимального параметра по U,  
---|---  
uMax | \- значение максимального параметра по U,  
vMin | \- значение минимального параметра по V,  
vMax | \- значение максимального параметра по V.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
