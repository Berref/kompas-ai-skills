# InitBendObjects - Инициализация объектов сгиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalRib ](isheetmetalrib.html) > [ISheetMetalRib - методы ](isheetmetalrib_methods.html) |  Scroll [ [ [ ](isheetmetalsketchbends.html "К следующему разделу")](isheetmetalrib_methods.html "На уровень выше")](isheetmetalrib_calculateoptimalparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetalrib.html)

Синтаксис Automation:

BOOL InitBendObjects( IModelObject * BendObject, IModelObject * BendFace, IModelObject * BendEdge );

Синтаксис COM:

HRESULT InitBendObjects( IModelObject * BendObject, IModelObject * BendFace, IModelObject * BendEdge, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

BendObject | \- операция листового тела - сгиб (Сгиб, Сгиб по линии, Сгиб по эскизу),  
---|---  
BendFace | \- грань сгиба,  
BendEdge | \- ребро сгиба.  
  
Подразделы:

(отсутствуют)
