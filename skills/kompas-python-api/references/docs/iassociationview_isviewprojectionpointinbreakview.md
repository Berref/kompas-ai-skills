# IsViewProjectionPointInBreakView - Видна ли проекция точки на виде с разрывами

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_restorestyles.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_getprojectionpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

BOOL IsViewProjectionPointInBreakView( double X, double Y, double Z );

Синтаксис COM:

HRESULT IsViewProjectionPointInBreakView( double X, double Y, double Z, BOOL * Result );

Входные параметры:

Contour | \- указатель на замкнутую кривую.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y, Z | \- координаты точки в 3D документе.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
