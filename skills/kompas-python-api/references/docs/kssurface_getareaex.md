# GetAreaEx - Получить площадь грани (ST_MIX_MM..ST_MIX_M - единицы измерения)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getboundaryuvnurbs.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_getarea.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

double GetAreaEx( long bitVector, double angleTolerance );

Синтаксис COM:

double GetAreaEx (unsigned long bitVector, double angleTolerance );

Входные параметры:

bitVector | \- [единицы измерения](lentypes.html) в интервале [ST_MIX_MM..ST_MIX_M],  
---|---  
angleTolerance | \- ограничение углового отклонения при аппроксимации оболочки треугольными пластинами  
  
Возвращаемое значение:

площадь грани | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
