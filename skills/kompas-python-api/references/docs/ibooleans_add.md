# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IBooleans ](ibooleans.html) > [IBooleans - методы ](ibooleans_methods.html) |  Scroll [ [ [ ](ichamfers.html "К следующему разделу")](ibooleans_methods.html "На уровень выше")](ibooleans_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibooleans.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IBoolean ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IBoolean](iboolean.html).  
---|---  
  
Примечания:

Метод позволяет создать новый интерфейс булевой операции.

После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
