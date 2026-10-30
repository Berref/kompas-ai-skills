# SetFacetSize - Изменить ограничение размера ребра для триангуляционной пластины

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [Триангуляция (аппроксимирующая поверхность грани), Интерфейсы ksTessellation, ITessellation ](kstessellation.html) > [ITessellation - методы ](kstessellation_methods.html) |  Scroll [ [ [ ](kstessellation_setneedparams.html "К следующему разделу")](kstessellation_methods.html "На уровень выше")](kstessellation_setfacetsag.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kstessellation.html)

Синтаксис Automation:

BOOL SetFacetSize (double sag);

Синтаксис COM:

BOOL SetFacetSize (double sag);

Входные параметры:

sag | 0 | \- обычная триангуляция (для отображения),  
---|---|---  
sag | >0 | \- триангуляция для прочностных расчетов.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Триангуляционная сетка может быть построена с учетом нескольких параметров:

•Установить ограничение размера ребра для триангуляционной пластины [ksTessellation::SetFacetSize](kstessellation_setfacetsize.html).

•Установить ограничение прогиба поверхности триангуляционной пластины [ksTessellation::SetFacetSag](kstessellation_setfacetsag.html).

•Установить ограничение углового отклонения поверхности [ksTessellation::SetFacetAngle](kstessellation_setfacetangle.html).

Если ни один из параметров не задан (равны 0), возвращаются параметры рассчитанной в модели сетки.

2\. В Компас при расчете триангуляции ограничение размера ребра рассчитывается в зависимости от габаритов модели.

Получить значение рассчитанной величины ограничения размера ребра можно с помощью метода [IPart7::GetMaxSag](ipart7_getmaxsag.html).

3\. Рекомендуемое значение шага ребра для расчетов - до 2% от максимального значения габарита.

Подразделы:

(отсутствуют)
