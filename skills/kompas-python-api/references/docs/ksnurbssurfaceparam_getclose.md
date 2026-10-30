# GetClose - Получить тип замыкания сплайна

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Параметры NURBS-поверхности (Интерфейсы ksNurbsSurfaceParam, INurbsSurfaceParam) ](ksnurbssurfaceparam.html) > [ksNurbsSurfaceParam - методы ](ksnurbssurfaceparam_methods.html) |  Scroll [ [ [ ](ksnurbssurfaceparam_getdegree.html "К следующему разделу")](ksnurbssurfaceparam_methods.html "На уровень выше")](ksnurbssurfaceparam_getboundaryuvnurbs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksnurbssurfaceparam.html)

Синтаксис Automation:

BOOL GetClose (BOOL paramU);

Синтаксис COM:

BOOL GetClose (BOOL paramU);

Входные параметры:

paramU | TRUE | \- для параметра U,  
---|---|---  
paramU | FALSE | \- для параметра V.  
  
Возвращаемое значение:

TRUE | \- сплайн замкнутый,  
---|---  
FALSE | \- сплайн разомкнутый.  
  
Примечание:

Значение paramU позволяет выбрать параметр представления поверхности U или V, для которого выполняется метод.

Подразделы:

(отсутствуют)
