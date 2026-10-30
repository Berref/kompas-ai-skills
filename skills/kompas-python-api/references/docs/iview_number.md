# Number - Номер вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_objectcount.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: long

Синтаксис Automation:

Number = iObject.Number | Получить свойство ([* ](1.html))  
---|---  
iObject.Number = Number | Установить свойство ([* ](1.html))  
Number = iObject.GetNumber() | Получить свойство ([**](2.html))  
iObject.SetNumber (Number) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Number (&Number) | Получить свойство  
---|---  
iObject->put_Number (Number) | Установить свойство  
  
Примечание:

Номер вида "0" зарезервирован для системного вида. Номер должен быть уникальным в документе. Для нового вида, полученного методом [IViews::Add](iviews_add.html), можно задать номер "-1" или не задавать номер. В этом случае при вызове метода [IDrawingObject::Update](idrawingobject_update.html) для данного вида номер будет задан автоматически.

Подразделы:

(отсутствуют)
