# ProjectionMatrix - Матрица ассоциативного вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_projectionname.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_local.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: VARIANT

Синтаксис Automation:

ProjectionMatrix = Object.ProjectionMatrix | Получить свойство ([* ](1.html))  
---|---  
Object.ProjectionMatrix = ProjectionMatrix | Установить свойство ([* ](1.html))  
ProjectionMatrix = Object.GetProjectionMatrix() | Получить свойство ([**](2.html))  
Object.SetProjectionMatrix( ProjectionMatrix ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ProjectionMatrix( &ProjectionMatrix ) | Получить свойство,  
---|---  
Object.put_ProjectionMatrix( ProjectionMatrix ) | Установить свойство.  
  
Примечание

Матрица представляет собой массив SAFEARRAY double (VT_ARRAY | VT_R8)

В массиве будут лежать 16 элементов, которые представляют собой матрицу размера 4х4.

Подразделы:

(отсутствуют)
