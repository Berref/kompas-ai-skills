# HideAllThreads - Резьбы

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideincomponentsmode.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallsurfaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- резьбы скрыты,  
---|---  
FALSE | \- резьбы показаны.  
  
Синтаксис Automation:

BOOL HideAllThreads = iObject.HideAllThreads | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllThreads = HideAllThreads | Установить свойство ([* ](1.html))  
BOOL HideAllThreads = iObject.GetHideAllThreads() | Получить свойство ([**](2.html))  
iObject.SetHideAllThreads (HideAllThreads) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllThreads (&HideAllThreads) | Получить свойство  
---|---  
iObject->put_HideAllThreads (HideAllThreads) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
