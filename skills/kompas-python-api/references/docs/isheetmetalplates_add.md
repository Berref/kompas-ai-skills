# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalPlates ](isheetmetalplates.html) > [ISheetMetalPlates - методы ](isheetmetalplates_methods.html) |  Scroll [ [ [ ](isheetmetalplate.html "К следующему разделу")](isheetmetalplates_methods.html "На уровень выше")](isheetmetalplates_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalplates.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalPlate * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalPlate](isheetmetalplate.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции “пластина”.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
