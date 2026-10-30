# hideAllPlanes - Скрыть\показать конструктивные плоскости

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_hideallsketches.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_hideallplaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksdocument3d.html).

Тип данных: BOOL

Значения свойства:

TRUE | \- скрыть конструктивные плоскости,  
---|---  
FALSE | \- показать конструктивные плоскости.  
  
Синтаксис Automation:

hideAllPlanes = iDocument3D.hideAllPlanes | Получить свойство ([* ](1.html))  
---|---  
iDocument3D.hideAllPlanes = hideAllPlanes | Установить свойство ([* ](1.html))  
hideAllPlanes = iDocument3D.GetHideAllPlanes() | Получить свойство ([**](2.html))  
iDocument3D.SetHideAllPlanes( hideAllPlanes ) | Установить свойство ([**](2.html))  
  
Примечание:

В зависимости от флага [hideInComponentsMode](ksdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
