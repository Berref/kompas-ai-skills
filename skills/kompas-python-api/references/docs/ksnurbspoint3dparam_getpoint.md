# GetPoint - Получить координаты базовой точки

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры точки для трехмерных NURBS(Интерфейсы ksNurbsPoint3dParam, INurbsPoint3dParam) ](ksnurbspoint3dparam.html) > [INurbsPoint3dParam - методы ](ksnurbspoint3dparam_methods.html) |  Scroll [ [ [ ](ksrotatedparam.html "К следующему разделу")](ksnurbspoint3dparam_methods.html "На уровень выше")](ksnurbspoint3dparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksnurbspoint3dparam.html)

Синтаксис Automation:

BOOL GetPoint (double * x, double *y, double *z);

Синтаксис COM:

BOOL GetPoint (double * x, double *y, double *z);

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

x, y, z | \- координаты базовой точки.  
---|---  
  
Подразделы:

(отсутствуют)
