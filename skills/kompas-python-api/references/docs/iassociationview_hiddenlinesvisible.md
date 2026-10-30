# HiddenLinesVisible - Показывать невидимые линии

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_local.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_hiddenlinesstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: long

Синтаксис Automation:

HiddenLinesVisible = Object.HiddenLinesVisible | Получить свойство ([* ](1.html))  
---|---  
Object.HiddenLinesVisible = HiddenLinesVisible | Установить свойство ([* ](1.html))  
HiddenLinesVisible = Object.GetHiddenLinesVisible() | Получить свойство ([**](2.html))  
Object.SetHiddenLinesVisible( HiddenLinesVisible ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_HiddenLinesVisible( &HiddenLinesVisible ) | Получить свойство,  
---|---  
Object.put_HiddenLinesVisible( HiddenLinesVisible ) | Установить свойство.  
  
Свойство позволяет получить и установить признак отображения невидимых линий.

Примечание:

Для использования данного свойства требуется включение передачи невидимых линий ([IAssociationView::HiddenLines](iassociationview_hiddenlines.html)).

Подразделы:

(отсутствуют)
