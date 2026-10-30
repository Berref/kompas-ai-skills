# GetProjectionPoint - Получить координаты точки на виде по 3D координатам модели

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_isviewprojectionpointinbreakview.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_createlocalview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

BOOL GetProjectionPoint( double X, double Y, double Z, double * Xv, double * Yv );

Синтаксис COM:

HRESULT GetProjectionPoint( double X, double Y, double Z, double * Xv, double * Yv, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки в 3D документе.  
---|---  
  
Выходные параметры:

Xv, Yv | \- координаты проекции точки.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
