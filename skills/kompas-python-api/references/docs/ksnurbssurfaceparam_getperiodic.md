# GetPeriodic - Получить периодичность сплайна

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_nurbsknotcollection.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_getnurbsparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

BOOL GetPeriodic (BOOL paramU);

Синтаксис COM:

BOOL GetPeriodic (BOOL paramU);

Входные параметры:

paramU | TRUE | \- для параметра U,  
---|---|---  
paramU | FALSE | \- для параметра V.  
  
Возвращаемое значение:

TRUE | \- сплайн периодический,  
---|---  
FALSE | \- сплайн непериодический.  
  
Примечание:

Значение paramU позволяет выбрать параметр представления поверхности U или V, для которого выполняется метод.

Подразделы:

(отсутствуют)
