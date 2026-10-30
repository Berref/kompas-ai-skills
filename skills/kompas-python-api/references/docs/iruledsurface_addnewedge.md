# AddNewEdge - Добавление ребра линейчатой поверхности после указанного индексом

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - методы ](iruledsurface_methods.html) |  Scroll [ [ [ ](iruledsurface_deleteedge.html "К следующему разделу")](iruledsurface_methods.html "На уровень выше")](iruledsurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iruledsurface.html)

Синтаксис Automation:

BOOL AddNewEdge( long IndexAt );

Синтаксис COM:

HRESULT AddNewEdge( long IndexAt, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

IndexAt - индекс ребра, после которого нужно вставить новое ребро.

Метод позволяет вставить новое ребро перед заданным. Новое ребро будет иметь следующий по порядку номер.

Подразделы:

(отсутствуют)
