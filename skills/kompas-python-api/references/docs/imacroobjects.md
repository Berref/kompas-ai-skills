# Интерфейс IMacroObjects

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Макрообъекты ](bb2346750.html) |  Scroll [ [ [ ](imacroobjects_props.html "К следующему разделу")](bb2346750.html "На уровень выше")](bb2346750.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции макроэлементов.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[IDrawingObjects](idrawingobjects.html)

[IMacroObjects](imacroobjects.html)

[IAnnotativeContainer](iannotativecontainer.html)

Описание:

Позволяет создавать и получать макроэлементы.

Примечание:

1\. Получить интерфейс можно, используя метод контейнера графических объектов [IDrawingContainer::MacroObjects](idrawingcontainer_macroobjects.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить дополнительный интерфейс [IAnnotativeContainer](iannotativecontainer.html).

Подразделы:

[IMacroObjects - свойства ](imacroobjects_props.html)

[IMacroObjects - методы ](imacroobjects_methods.html)
