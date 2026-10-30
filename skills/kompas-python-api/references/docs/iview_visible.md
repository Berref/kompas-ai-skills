# Visible - Состояние вида - видимый или погашенный

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) |  Scroll [ [ [ ](iview_x.html "К следующему разделу")](iview_props.html "На уровень выше")](iview_viewtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview.html)

Тип данных: BOOL

Синтаксис Automation:

Visible = iObject.Visible | Получить свойство ([* ](1.html))  
---|---  
iObject.Visible = Visible | Установить свойство ([* ](1.html))  
Visible = iObject.GetVisible() | Получить свойство ([**](2.html))  
iObject.SetVisible (Visible) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Visible (&Visible) | Получить свойство  
---|---  
iObject->put_Visible (Visible) | Установить свойство  
  
Примечание:

1\. Позволяет получить и установить свойство вида - видимый или погашенный.

2\. Свойство вступает в силу после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

(отсутствуют)
