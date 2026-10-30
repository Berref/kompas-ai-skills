# BaseView - Опорный вид

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_bendlinesstyle.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_baseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: указатель на интерфейс вида [IView](iview.html)

Синтаксис Automation:

BaseView = Object.BaseView | Получить свойство ([* ](1.html))  
---|---  
Object.BaseView = BaseView | Установить свойство ([* ](1.html))  
BaseView = Object.GetBaseView() | Получить свойство ([**](2.html))  
Object.SetBaseView( BaseView ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BaseView( &BaseView ) | Получить свойство,  
---|---  
Object.put_BaseView( BaseView ) | Установить свойство.  
  
Примечание:

Свойство используется при создании проекционного вида.

Позволяет установить вид, относительно которого выполняется производная проекция.

Базовый вид должен быть ассоциативным.

Подразделы:

(отсутствуют)
