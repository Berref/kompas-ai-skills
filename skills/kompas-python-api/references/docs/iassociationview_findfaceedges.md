# FindFaceEdges - Получить массив SAFEARRAY ассоциативных объектов ребер грани по точке в чертеже

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - методы ](iassociationview_methods.html) |  Scroll [ [ [ ](iassociationview_setprojectionobjects.html "К следующему разделу")](iassociationview_methods.html "На уровень выше")](iassociationview_findface.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Синтаксис Automation:

VARIANT FindFaceEdges( double X, double Y );

Синтаксис COM :

HRESULT FindFaceEdges( double X, double Y, VARIANT * Result );

Возвращаемое значение:

| \- объект (VT_DISPATCH) или Список объектов VT_ARRAY | VT_DISPATCH, VT_EMPTY - если объекты не найдены.  
---|---  
  
Входные параметры:

X, Y | \- координаты точки.  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
