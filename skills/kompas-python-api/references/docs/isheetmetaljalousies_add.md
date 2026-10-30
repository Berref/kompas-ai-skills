# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalJalousies ](isheetmetaljalousies.html) > [ISheetMetalJalousies - методы ](isheetmetaljalousies_methods.html) |  Scroll [ [ [ ](isheetmetaljalousie.html "К следующему разделу")](isheetmetaljalousies_methods.html "На уровень выше")](isheetmetaljalousies_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetaljalousies.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalJalousie * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalJalousie](isheetmetaljalousie.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции Жалюзи.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
