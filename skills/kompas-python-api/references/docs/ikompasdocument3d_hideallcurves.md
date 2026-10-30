# HideAllCurves - Скрыть/показать пространственные кривые

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hidealldesignations.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallcontrolpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- пространственные кривые скрыты,  
---|---  
FALSE | \- пространственные кривые показаны.  
  
Синтаксис Automation:

BOOL HideAllCurves = iObject.HideAllCurves | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllCurves = HideAllCurves | Установить свойство ([* ](1.html))  
BOOL HideAllCurves = iObject.GetHideAllCurves() | Получить свойство ([**](2.html))  
iObject.SetHideAllCurves (HideAllCurves) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllCurves (&HideAllCurves) | Получить свойство  
---|---  
iObject->put_HideAllCurves (HideAllCurves) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
