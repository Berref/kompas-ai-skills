# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalBendedStraightens ](isheetmetalbendedstraightens.html) > [ISheetMetalBendedStraightens - методы ](isheetmetalbendedstraightens_methods.html) |  Scroll [ [ [ ](isheetmetalbendunfoldparameters.html "К следующему разделу")](isheetmetalbendedstraightens_methods.html "На уровень выше")](isheetmetalbendedstraightens_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalbendedstraightens.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum Type );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum Type, ISheetMetalBendedStraighten * * Result );

Возвращаемое значение:

| \- указатель на интерфейс [ISheetMetalBendedStraighten](isheetmetalbendedstraighten.html).  
---|---  
  
Входные параметры:

Type | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Примечания:

1\. Метод позволяет создать новый интерфейс операций Согнуть / Разогнуть.

2\. Допустимыми значениями Type являются o3d_sheetMetalBendStraighten (Согнуть), o3d_sheetMetalBendBended (Разогнуть)

3\. После получения нового интерфейса нужно задать параметры операции и вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

(отсутствуют)
