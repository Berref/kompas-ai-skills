# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRestoredSurfaces ](irestoredsurfaces.html) > [IRestoredSurfaces - методы ](irestoredsurfaces_methods.html) |  Scroll [ [ [ ](icloudpointssurface.html "К следующему разделу")](irestoredsurfaces_methods.html "На уровень выше")](irestoredsurfaces_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irestoredsurfaces.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IRestoredSurface * * Result );

Возвращаемое значение:

  
| \- Указатель на интерфейс [IRestoredSurface](irestoredsurface.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции восстановления поверхности.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
