# hideAllSketches - Скрыть\показать эскизы

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_hideallsurfaces.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_hideallplanes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- скрыть конструктивные эскизы,  
---|---  
FALSE | \- показать конструктивные эскизы.  
  
Синтаксис Automation:

iDocument3D.hideAllSketches | Получить свойство ([* ](1.html))  
---|---  
iDocument3D.hideAllSketches = hideAllSketches | Установить свойство ([* ](1.html))  
hideAllSketches = iDocument3D.GetHideAllSketches() | Получить свойство ([**](2.html))  
iDocument3D.SetHideAllSketches(hideAllSketches ) | Установить свойство ([**](2.html))  
  
Примечание:

В зависимости от флага [hideInComponentsMode](ksdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
