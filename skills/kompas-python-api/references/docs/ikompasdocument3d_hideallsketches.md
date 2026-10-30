# HideAllSketches - Скрыть/показать эскизы

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallsurfaces.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallplanes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- эскизы скрыты,  
---|---  
FALSE | \- эскизы показаны.  
  
Синтаксис Automation:

BOOL HideAllSketches = iObject.HideAllSketches | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllSketches = HideAllSketches | Установить свойство ([* ](1.html))  
BOOL HideAllSketches = iObject.GetHideAllSketches() | Получить свойство ([**](2.html))  
iObject.SetHideAllSketches (HideAllSketches) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllSketches (&HideAllSketches) | Получить свойство  
---|---  
iObject->put_HideAllSketches (HideAllSketches) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
