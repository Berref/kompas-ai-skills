# HideAllControlPoints - Скрыть/показать контрольные точки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallcurves.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- контрольные точки скрыты,  
---|---  
FALSE | \- контрольные точки показаны.  
  
Синтаксис Automation:

BOOL HideAllControlPoints = iObject.HideAllControlPoints | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllControlPoints = HideAllControlPoints | Установить свойство ([* ](1.html))  
BOOL HideAllControlPoints = iObject.GetHideAllControlPoints() | Получить свойство ([**](2.html))  
iObject.SetHideAllControlPoints (HideAllControlPoints) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllControlPoints (&HideAllControlPoints) | Получить свойство  
---|---  
iObject->put_HideAllControlPoints (HideAllControlPoints) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
