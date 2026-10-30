# GetArea - Получить площадь поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getareaex.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_curveintersection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

double GetArea (long bitVector);

Синтаксис COM:

double GetArea (unsigned long bitVector);

Входные параметры:

bitVector | \- единицы измерения в интервале [ST_MIX_MM..ST_MIX_M].  
---|---  
  
Возвращаемое значение:

площадь поверхности | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
