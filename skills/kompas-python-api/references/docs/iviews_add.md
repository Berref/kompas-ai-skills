# Add - Создать вид (добавляет вид в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObjects ](idrawingobjects.html) > [IDrawingObjects - свойства ](idrawingobjects_props.html) > [Интерфейс IViews ](iviews.html) > [IViews - методы ](iviews_methods.html) |  Scroll [ [ [ ](iviews_addstandartviews.html "К следующему разделу")](iviews_methods.html "На уровень выше")](iviews_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iviews.html)

Синтаксис Automation:

LPDISPATCH Add (long ViewType);

Синтаксис COM:

HRESULT Add ([in] LtViewType ViewType, [out, retval] IView** Result);

Входные параметры:

ViewType | \- тип создаваемого вида из перечисления [LtViewType](ltviewtype.html).  
---|---  
  
Возвращаемое значение:

| \- Указатель на интерфейс вида [IView](iview.html).  
---|---  
  
Примечание:

1\. Системный вид создается автоматически при создании документа. Создавать второй системный вид (тип vt_System) нельзя.

2\. После вызова этого метода вид будет добавлен в коллекцию, но в документе не появится.

3\. Для отображения вида в документе нужно задать его параметры и вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
