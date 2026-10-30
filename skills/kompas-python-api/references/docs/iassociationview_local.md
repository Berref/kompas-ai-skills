# Local - Местный вид

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_projectionmatrix.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_hiddenlinesvisible.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: BOOL

Синтаксис Automation:

Local = Object.Local | Получить свойство ([* ](1.html))  
---|---  
Object.Local = Local | Установить свойство ([* ](1.html))  
Local = Object.GetLocal() | Получить свойство ([**](2.html))  
Object.SetLocal( Local ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Local( &Local ) | Получить свойство,  
---|---  
Object.put_Local( Local ) | Установить свойство.  
  
Примечание:

Включает полное изображение вида или усеченное (местный вид).

Требует предварительного создания местного вида с помощью команды [IAssociationView::CreateLocalView](iassociationview_createlocalview.html)

Подразделы:

(отсутствуют)
