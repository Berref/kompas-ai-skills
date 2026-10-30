# FindFace - Найти грань по точке в чертеже

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_findfaceedges.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_getprojectionobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

LPDISPATCH FindFace( double X, double Y, IKompasDocument3D * Document3D );

Синтаксис COM:

HRESULT FindFace( double X, double Y, IKompasDocument3D * Document3D, IModelObject * * Result );

Возвращаемое значение:

| \- интерфейс объекта модели [IModelObject](imodelobject.html).  
---|---  
  
Входные параметры:

X, Y | \- координаты точки,  
---|---  
Document3D | \- указатель на интерфейс документа [IKompasDocument3D](ikompasdocument3d.html).  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
