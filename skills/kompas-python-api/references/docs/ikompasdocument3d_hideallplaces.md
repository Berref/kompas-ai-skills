# HideAllPlaces - Скрыть/показать начала координат

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallplanes.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hidealldimensions.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- начала координат скрыты,  
---|---  
FALSE | \- начала координат показаны.  
  
Синтаксис Automation:

BOOL HideAllPlaces = iObject.HideAllPlaces | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllPlaces = HideAllPlaces | Установить свойство ([* ](1.html))  
BOOL HideAllPlaces = iObject.GetHideAllPlaces() | Получить свойство ([**](2.html))  
iObject.SetHideAllPlaces (HideAllPlaces) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllPlaces (&HideAllPlaces) | Получить свойство  
---|---  
iObject->put_HideAllPlaces (HideAllPlaces) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
