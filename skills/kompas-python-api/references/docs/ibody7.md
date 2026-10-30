# Интерфейс IBody7

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Твердое тело ](bc2297187.html) |  Scroll [ [ [ ](ibody7_props.html "К следующему разделу")](bc2297187.html "На уровень выше")](bc2297187.html "К предыдущему разделу")  
---|---  
  
Интерфейс твердого тела.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IBody7](ibody7.html)

[IMassInertiaParam7](imassinertiaparam7.html)

[IPropertyKeeper](ipropertykeeper.html)

Описание:

Позволяет получить интерфейс твердого тела. Тело является результатом выполнения операций (например, операции выдавливания). Представляет собой область, ограниченную замкнутой поверхностью.

Примечание:

1\. Интерфейс можно получить у интерфейса дерева с помощью метода [IFeature7::ResultBodies](ifeature7_resultbodies.html).

2\. Интерфейс можно получить у интерфейса области применения для тел документа в операции с помощью метода [IChooseBodies7::Bodies](ichoosebodies7_bodies.html).

3\. Имеет дополнительные интерфейсы [IMassInertiaParam7](imassinertiaparam7.html), [IColorParam7](icolorparam7.html), [IFeature7](ifeature7.html), [IPropertyKeeper](ipropertykeeper.html), которые можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IBody7 - свойства ](ibody7_props.html)

[IBody7 - методы ](ibody7_methods.html)
