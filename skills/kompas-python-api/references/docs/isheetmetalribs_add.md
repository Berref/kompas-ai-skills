# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalRibs ](isheetmetalribs.html) > [ISheetMetalRibs - методы ](isheetmetalribs_methods.html) |  Scroll [ [ [ ](isheetmetalruledshell.html "К следующему разделу")](isheetmetalribs_methods.html "На уровень выше")](isheetmetalribs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalribs.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalRib ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalRib](isheetmetalrib.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции Пластина.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
