# HiddenLines - Передавать невидимые линии в вид

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IDrawingObject ](idrawingobject.html) > [IDrawingObject - методы ](idrawingobject_methods.html) > [Интерфейс IView ](iview.html) > [IView - свойства ](iview_props.html) > [Интерфейс IAssociationView ](iassociationview.html) > [IAssociationView - свойства ](iassociationview_props.html) |  Scroll [ [ [ ](iassociationview_hiddenlinesstyle.html "К следующему разделу")](iassociationview_props.html "На уровень выше")](iassociationview_explodedview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iassociationview.html)

Тип данных: long

Синтаксис Automation:

HiddenLines = Object.HiddenLines | Получить свойство ([* ](1.html))  
---|---  
Object.HiddenLines = HiddenLines | Установить свойство ([* ](1.html))  
HiddenLines = Object.GetHiddenLines() | Получить свойство ([**](2.html))  
Object.SetHiddenLines( HiddenLines ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_HiddenLines( &HiddenLines ) | Получить свойство,  
---|---  
Object.put_HiddenLines( HiddenLines ) | Установить свойство.  
  
Позволяет получить и установить признак отображения невидимых линий при проецировании.

Примечание:

Невидимые линии хранятся в виде вне зависимости от того, включена их отрисовка или нет ([IAssociationView::HiddenLinesVisible](iassociationview_hiddenlinesvisible.html)).

Если отрисовка этих линий не требуется, отключите опцию Невидимые линии — это уменьшит размер файла чертежа.

Рекомендуется отключать опцию Невидимые линии при построении ассоциативных видов сборок, содержащих более 1000 компонентов.

Подразделы:

(отсутствуют)
