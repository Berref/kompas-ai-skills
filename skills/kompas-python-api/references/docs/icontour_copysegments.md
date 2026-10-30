# CopySegments - Объекты вида для добавления в контур в виде SAFEARRAY'я DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - методы ](icontour_methods.html) |  Scroll [ [ [ ](icontour_removecontourgaps.html "К следующему разделу")](icontour_methods.html "На уровень выше")](icontour_copycurve.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Синтаксис Automation:

BOOL CopySegments( VARIANT Val,

BOOL DeleteSource );

Синтаксис COM:

HRESULT CopySegments( [in] VARIANT Val,

[in] VARIANT_BOOL DeleteSource,

[out, retval] VARIANT_BOOL * PVal );

Входные параметры:

Val | \- массив SAFEARRAY типа VT_ARRAY | VT_DISPATCH, содержащий объекты вида (отрезки, дуги и т. п.) для добавления в контур,  
---|---  
DeleteSource | \- удалить исходные объекты.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
