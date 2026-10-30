# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalShoulders ](isheetmetalshoulders.html) > [ISheetMetalShoulders - методы ](isheetmetalshoulders_methods.html) |  Scroll [ [ [ ](isheetmetalshoulder.html "К следующему разделу")](isheetmetalshoulders_methods.html "На уровень выше")](isheetmetalshoulders_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalshoulders.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalShoulder * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalShoulder](isheetmetalshoulder.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операций Буртик.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
