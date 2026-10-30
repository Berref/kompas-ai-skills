# SelectionBandMode - Режим использования прямоугольной рамки для выделения объектов

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProcess3D ](iprocess3d.html) > [IProcess3D - свойства ](iprocess3d__propers.html) |  Scroll [ [ [ ](iprocess3d_takeprocessobject.html "К следующему разделу")](iprocess3d__propers.html "На уровень выше")](iprocess3d_placement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprocess3d.html)

Тип данных: из перечисления [ksSelectionBandMode](ksselectionbandmode.html)

Синтаксис Automation:

SelectionBandMode = Object.SelectionBandMode | Получить свойство ([* ](1.html))  
---|---  
Object.SelectionBandMode = SelectionBandMode | Установить свойство ([* ](1.html))  
SelectionBandMode = Object.GetSelectionBandMode() | Получить свойство ([**](2.html))  
Object.SetSelectionBandMode( SelectionBandMode ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SelectionBandMode( &SelectionBandMode) | Получить свойство  
---|---  
Object.put_SelectionBandMode( SelectionBandMode ) | Установить свойство  
  
Примечание:

Свойство позволяет включить режим группового выделения объектов рамкой в процессе.

При групповом селектировании рамкой будет посылаться событие [ksProcess3DNotify::ProcessingGroupObjects.](ksprocess3dnotify_processinggroupobjects.html)

Подразделы:

(отсутствуют)
