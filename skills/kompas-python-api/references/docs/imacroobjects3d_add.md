# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Макрообъекты 3D ](bc2753948.html) > [Интерфейс IMacroObjects3D ](imacroobjects3d.html) > [IMacroObjects3D - методы ](imacroobjects3d_methods.html) |  Scroll [ [ [ ](imacroobject3d.html "К следующему разделу")](imacroobjects3d_methods.html "На уровень выше")](imacroobjects3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imacroobjects3d.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IMacroObject3D ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IMacroObject3D](imacroobject3d.html).  
---|---  
  
Примечания:

Метод позволяет создать новый интерфейс макрообъекта.

После получения нового интерфейса нужно задать параметры объекта и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
