# GetGroupObjectsGeometry - Получить общий список подключенной геометрии к объектам в группе

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс IGroupObjectsManager](igroupobjectsmanager.html) > [IGroupObjectsManager - методы](igroupobjectsmanager_methods.html) |  Scroll [ [ [ ](ispecificationbaseobject.html "К следующему разделу")](igroupobjectsmanager_methods.html "На уровень выше")](igroupobjectsmanager_findgroupobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](igroupobjectsmanager.html)

Синтаксис Automation:

VARIANT GetGroupObjectsGeometry( ISpecificationBaseObject * GroupObjec );

Синтаксис COM:

HRESULT GetGroupObjectsGeometry( ISpecificationBaseObject * GroupObjec, VARIANT * Result );

Возвращаемое значение:

| \- Массив SafeArray типа VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

BaseObject | \- групповой объект спецификации [ISpecificationBaseObject](ispecificationbaseobject.html).  
---|---  
  
Примечание:

У базового объекта СП может быть установлена геометрия, которая ассоциируется с данным объектом. 

Для 2D документа – это массив [IDrawingObject](idrawingobject.html). 

Для 3D документа – это массив объектов:

•[IPart7](ipart7.html) (может быть один компонент),

•[IBody7](ibody7.html) (тела верхнего уровня сборки),

•[IPositionLeader](ipositionleader.html) (обозначения позиций верхнего уровня сборки).

Получить можно всегда массив объектов. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Установить можно как массив, так и одиночный объект. При установке геометрии старая геометрия очищается.

Подразделы:

(отсутствуют)
