# DeleteVertex - Удалить вершину с указанным индексом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - методы ](ipolyline_methods.html) |  Scroll [ [ [ ](ipolyline_errorindexes.html "К следующему разделу")](ipolyline_methods.html "На уровень выше")](ipolyline_addvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Синтаксис Automation:

BOOL DeleteVertex( long Index );

Синтаксис COM:

HRESULT DeleteVertex([in] long Index,

[out, retval] VARIANT_BOOL * Result );

Входные параметры:

Index | \- индекс вершины.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
