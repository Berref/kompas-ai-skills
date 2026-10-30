# CopyCurve - Добавить сегмент

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - методы ](icontour_methods.html) |  Scroll [ [ [ ](icontour_copysegments.html "К следующему разделу")](icontour_methods.html "На уровень выше")](icontour_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Синтаксис Automation:

BOOL CopyCurve( LPDISPATCH Curve,

BOOL DeleteSource );

Синтаксис COM:

HRESULT CopyCurve( [in] IDrawingObject * Curve,

[in] VARIANT_BOOL DeleteSource,

[out, retval] VARIANT_BOOL* Result );

Входные параметры:

Curve | \- объект для добавления в контур,  
---|---  
DeleteSource | \- удалить исходный объект.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

После добавления сегментов в контур требуется вызов метода [IDrawingObject::Update](idrawingobject_update.html), в котором эти сегменты будут добавлены в 2D кривую. (При условии совпадения точек сегментов с точностью до 1e-3).

Подразделы:

(отсутствуют)
