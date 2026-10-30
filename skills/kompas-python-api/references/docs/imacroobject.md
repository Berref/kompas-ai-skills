# Интерфейс IMacroObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) |  Scroll [ [ [ ](imacroobject_props.html "К следующему разделу")](bb2346750.html "На уровень выше")](imacroobjects_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс нетипизированного макроэлемента.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IMacroObject](imacroobject.html)

[IAnnotativeContainer](iannotativecontainer.html)

[IDrawingContainer](idrawingcontainer.html)

[IBuildingContainer](ibuildingcontainer.html)

[ISymbols2DContainer](isymbols2dcontainer.html)

[IPropertyKeeper](ipropertykeeper.html)

Описание:

Интерфейс позволяет задавать параметры макроэлемента.

Примечание:

1\. Интерфейс можно получить, используя свойство коллекции макроэлементов [IMacroObjects::MacroObject](imacroobjects_macroobject.html) или метод [IMacroObjects::Add](imacroobjects_add.html).

2\. После задания параметров макроэлемента требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& IID, void** pif) ](recomendation.html)у данного интерфейса можно получить дополнительные интерфейсы:

•интерфейс контейнера аннотационных объектов [IAnnotativeContainer](iannotativecontainer.html),

•интерфейс контейнера объектов вида графического документа [IDrawingContainer](idrawingcontainer.html),

•интерфейс контейнера объектов СПДС [IBuildingContainer](ibuildingcontainer.html),

•интерфейс контейнера условных обозначений [ISymbols2DContainer](isymbols2dcontainer.html),

•интерфейс получения/редактирования значения свойств [IPropertyKeeper](ipropertykeeper.html).

Подразделы:

[IMacroObject - свойства ](imacroobject_props.html)

[IMacroObject - методы ](imacroobject_methods.html)
