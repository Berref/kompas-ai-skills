# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalClosedCorners ](isheetmetalclosedcorners.html) > [ISheetMetalClosedCorners - методы ](isheetmetalclosedcorners_methods.html) |  Scroll [ [ [ ](isheetmetalclosedcorner.html "К следующему разделу")](isheetmetalclosedcorners_methods.html "На уровень выше")](isheetmetalclosedcorners_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalclosedcorners.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add( ISheetMetalClosedCorner ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalClosedCorner](isheetmetalclosedcorner.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операции Замыкание углов.

2\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
