# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMateConstraint3D ](imateconstraint3d.html) > [IMateConstraint3D - методы ](imateconstraint3d_methods.html) > [Интерфейс IUnionsComponents ](iunionscomponents.html) > [IUnionsComponents - методы ](iunionscomponents_methods.html) |  Scroll [ [ [ ](imateinterval.html "К следующему разделу")](iunionscomponents_methods.html "На уровень выше")](iunionscomponents_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunionscomponents.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IUnionComponents ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IUnionComponents](iunioncomponents.html).  
---|---  
  
Примечания:

Метод позволяет создать новый интерфейс операции объединения компонентов.

После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
