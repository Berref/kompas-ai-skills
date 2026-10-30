# HiddenLinesStyle - Cтиль невидимых линий

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_hiddenlinesvisible.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_hiddenlines.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: long

Синтаксис Automation:

HiddenLinesStyle = Object.HiddenLinesStyle | Получить свойство ([* ](1.html))  
---|---  
Object.HiddenLinesStyle = HiddenLinesStyle | Установить свойство ([* ](1.html))  
HiddenLinesStyle = Object.GetHiddenLinesStyle() | Получить свойство ([**](2.html))  
Object.SetHiddenLinesStyle( HiddenLinesStyle ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_HiddenLinesStyle( &HiddenLinesStyle ) | Получить свойство,  
---|---  
Object.put_HiddenLinesStyle( HiddenLinesStyle ) | Установить свойство.  
  
Примечание:

Позволяет установить системный ([ksCurveStyleEnum](kscurvestyleenum.html)) или пользовательский стиль линий для отображения невидимых линий

Для использования данного свойства требуется включение передачи невидимых линий ([IAssociationView::HiddenLines](iassociationview_hiddenlines.html)) и включение отображения невидимых линий ([IAssociationView::HiddenLinesVisible](iassociationview_hiddenlinesvisible.html)).

Подразделы:

(отсутствуют)
