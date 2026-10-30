# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IMateConstraint3D ](imateconstraint3d.html) > [IMateConstraint3D - методы ](imateconstraint3d_methods.html) > [Интерфейс IMoldCavities ](imoldcavities.html) > [IMoldCavities - методы ](imoldcavities_methods.html) |  Scroll [ [ [ ](iunioncomponents.html "К следующему разделу")](imoldcavities_methods.html "На уровень выше")](imoldcavities_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imoldcavities.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( IMoldCavity ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IMoldCavity](imoldcavity.html).  
---|---  
  
Примечания:

Метод позволяет создать новый интерфейс операции вычитания компонентов.

После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
