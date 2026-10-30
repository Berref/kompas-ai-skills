# hideAllThreads - Скрыть\показать обозначения резьбы

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_hideincomponentsmode.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_hideallsurfaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных; BOOL

Значения свойства:

TRUE | \- скрыть поверхности,  
---|---  
FALSE | \- показать поверхности.  
  
Синтаксис Automation:

hideAllThreads = iDocument3D.hideAllThreads | Получить свойство ([* ](1.html))  
---|---  
iDocument3D.hideAllThreads = hideAllThreads | Установить свойство ([* ](1.html))  
hideAllThreads = iDocument3D.GetHideAllThreads() | Получить свойство ([**](2.html))  
iDocument3D.SetHideAllThreads(hideAllThreads) | Установить свойство ([**](2.html))  
  
Примечание:

В зависимости от флага [hideInComponentsMode](ksdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
