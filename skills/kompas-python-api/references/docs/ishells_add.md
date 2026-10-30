# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IShells ](ishells.html) > [IShells - методы ](ishells_methods.html) |  Scroll [ [ [ ](isplines3d.html "К следующему разделу")](ishells_methods.html "На уровень выше")](ishells_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ishells.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IShell ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IShell](ishell.html).  
---|---  
  
Примечания:

Метод позволяет создать новый интерфейс операции оболочка.

После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
