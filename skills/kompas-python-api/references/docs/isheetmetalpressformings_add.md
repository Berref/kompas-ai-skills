# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalPressFormings ](isheetmetalpressformings.html) > [ISheetMetalPressFormings - методы ](isheetmetalpressformings_methods.html) |  Scroll [ [ [ ](isheetmetalpressforming.html "К следующему разделу")](isheetmetalpressformings_methods.html "На уровень выше")](isheetmetalpressformings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalpressformings.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum Type );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum Type, ISheetMetalPressForming * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalPressForming](isheetmetalpressforming.html).  
---|---  
  
Входные параметры:

Type | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операций Открытая или Закрытая штамповка.

2\. Допустимыми значениями Type являются o3d_sheetMetalDrawnCutout (Закрытая штамповка), o3d_sheetMetalDimpleCutout (Открытая штамповка)

3\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
