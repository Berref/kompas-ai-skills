# DeleteEdge - Удаление ребра линейчатой поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - методы ](iruledsurface_methods.html) |  Scroll [ [ [ ](iruledsurface_getedgepointparam.html "К следующему разделу")](iruledsurface_methods.html "На уровень выше")](iruledsurface_addnewedge.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iruledsurface.html)

Синтаксис Automation:

BOOL DeleteEdge( long Index )

Синтаксис COM:

HRESULT DeleteEdge( long Index, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

Index - индекс удаляемого ребра.

Метод позволяет удалить ребро, заданное по индексу.

Примечания:

1\. Оставшиеся ребра нумеруются заново.

2\. Удаление ребер невозможно, если в списке остались два ребра.

Подразделы:

(отсутствуют)
