# HideAllPlanes - Скрыть/показать конструктивные плоскости

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallsketches.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallplaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- конструктивные плоскости скрыты,  
---|---  
FALSE | \- конструктивные плоскости показаны.  
  
Синтаксис Automation:

BOOL HideAllPlanes = iObject.HideAllPlanes | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllPlanes = HideAllPlanes | Установить свойство ([* ](1.html))  
BOOL HideAllPlanes = iObject.GetHideAllPlanes() | Получить свойство ([**](2.html))  
iObject.SetHideAllPlanes (HideAllPlanes) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllPlanes (&HideAllPlanes) | Получить свойство  
---|---  
iObject->put_HideAllPlanes (HideAllPlanes) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
