# hideAllPlaces - Скрыть\показать начала координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_hideallplanes.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_hidealldesignations.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- скрыть начала координат,  
---|---  
FALSE | \- показать начала координат.  
  
Синтаксис Automation:

iDocument3D.hideAllPlaces | Получить свойство ([* ](1.html))  
---|---  
iDocument3D.hideAllPlaces = hideAllPlaces | Установить свойство ([* ](1.html))  
hideAllPlaces = iDocument3D.GetHideAllPlaces() | Получить свойство ([**](2.html))  
iDocument3D.SetHideAllPlaces(hideAllPlaces) | Установить свойство([**](2.html))  
  
Примечание:

В зависимости от флага [hideInComponentsMode](ksdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
