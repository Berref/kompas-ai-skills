# AddVertex - Создание новой вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISplineOnSurface ](isplineonsurface.html) > [ISplineOnSurface - методы ](isplineonsurface_methods.html) |  Scroll [ [ [ ](isplineonsurface_clear.html "К следующему разделу")](isplineonsurface_methods.html "На уровень выше")](isplineonsurface_addpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isplineonsurface.html)

Синтаксис Automation:

BOOL AddVertex( long IndexAt,

double U,

double V,

double W,

IModelObject * AssociationObject );

Синтаксис COM:

HRESULT AddVertex( long IndexAt,

double U,

double V,

double W,

IModelObject * AssociationObject,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

IndexAt | \- индекс вершины, перед которой нужно добавить новую,  
---|---  
U | \- координата по U в %,  
V | \- координата по V в %,  
W | \- вес,  
AssociationObject | \- ассоциативная вершина.  
  
Подразделы:

(отсутствуют)
