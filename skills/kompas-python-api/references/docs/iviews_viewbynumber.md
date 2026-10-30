# ViewByNumber - Вид, заданный по номеру

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс IViews ](iviews.html) > [IViews - свойства ](iviews_props.html) |  Scroll [ [ [ ](iviews_methods.html "К следующему разделу")](iviews_props.html "На уровень выше")](iviews_view.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviews.html)

Тип данных: указатель на интерфейс вида [IView](iview.html)

Синтаксис Automation:

View = iObject.ViewByNumber (number) | Получить свойство ([* ](1.html))  
---|---  
View = iObject.GetViewByNumber (number) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ViewByNumber (number, &View) | Получить свойство  
---|---  
  
Входные параметры:

number | \- номер вида; тип long.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
