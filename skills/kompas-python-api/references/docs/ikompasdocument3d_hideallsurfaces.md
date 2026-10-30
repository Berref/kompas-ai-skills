# HideAllSurfaces - Скрыть/показать поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallthreads.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallsketches.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- поверхности скрыты,  
---|---  
FALSE | \- поверхности показаны.  
  
Синтаксис Automation:

BOOL HideAllSurfaces = iObject.HideAllSurfaces | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllSurfaces = HideAllSurfaces | Установить свойство ([* ](1.html))  
BOOL HideAllSurfaces = iObject.GetHideAllSurfaces() | Получить свойство ([**](2.html))  
iObject.SetHideAllSurfaces (HideAllSurfaces) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllSurfaces (&HideAllSurfaces) | Получить свойство  
---|---  
iObject->put_HideAllSurfaces (HideAllSurfaces) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
