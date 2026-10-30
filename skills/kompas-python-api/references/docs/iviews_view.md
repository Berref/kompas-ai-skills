# View - Вид, заданный по имени, ссылке или по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс IViews ](iviews.html) > [IViews - свойства ](iviews_props.html) |  Scroll [ [ [ ](iviews_viewbynumber.html "К следующему разделу")](iviews_props.html "На уровень выше")](iviews_activeview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviews.html)

Тип данных: указатель на интерфейс вида [IView](iview.html)

Синтаксис Automation:

View = iObject.View (Index) | Получить свойство ([* ](1.html))  
---|---  
View = iObject.GetView (Index) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_View (Index, &View) | Получить свойство  
---|---  
  
Входные параметры:

index | \- индекс вида в коллекции, ссылка на вид или имя вида; тип VARIANT.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
