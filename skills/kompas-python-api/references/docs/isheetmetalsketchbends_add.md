# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalSketchBends ](isheetmetalsketchbends.html) > [ISheetMetalSketchBends - методы ](isheetmetalsketchbends_methods.html) |  Scroll [ [ [ ](isheetmetalsketchbend.html "К следующему разделу")](isheetmetalsketchbends_methods.html "На уровень выше")](isheetmetalsketchbends_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalsketchbends.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalSketchBend ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalSketchBend](isheetmetalsketchbend.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции cгиб по эскизу.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
