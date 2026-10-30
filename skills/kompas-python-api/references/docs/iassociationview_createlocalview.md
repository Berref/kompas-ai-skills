# CreateLocalView - Местный вид

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_getprojectionpoint.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

BOOL CreateLocalView( LPDISPATCH Contour );

Синтаксис COM:

HRESULT CreateLocalView( IDrawingObject * Contour, BOOL * Result );

Входные параметры:

Contour | \- указатель на замкнутую кривую.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Границей местного вида может являться любой замкнутый контур (окружность, эллипс, замкнутая кривая Безье и т.п.).

Если в опорном виде нет замкнутого контура, создайте его

Необходимым условием корректного построения местного вида является расположение ограничивающего его контура именно в опорном виде.

Переключение между полным и усеченным отображением вида осуществляется с помощью свойства [IAssociationView::Local](iassociationview_local.html).

Подразделы:

(отсутствуют)
