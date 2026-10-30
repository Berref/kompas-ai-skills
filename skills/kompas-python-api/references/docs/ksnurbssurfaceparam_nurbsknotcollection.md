# NurbsKnotCollection - Получить указатель на интерфейс массива узлов для NURBS-поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_nurbspoint3dcollcollection.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_getperiodic.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

LPDISPATCH GetKnotCollection (BOOL paramU);

Синтаксис COM:

LPNURBSKNOTCOLLECTION GetKnotCollection (BOOL paramU);

Входные параметры:

paramU | TRUE | \- для параметра U,  
---|---|---  
paramU | FALSE | \- для параметра V.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksNurbsKnotCollection](ksnurbsknotcollection.html) или [INurbsKnotCollection](ksnurbsknotcollection.html).  
---|---  
  
Примечание:

Значение paramU позволяет выбрать параметр представления поверхности U или V, для которого выполняется метод.

Подразделы:

(отсутствуют)
