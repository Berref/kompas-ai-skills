# HideAllAxis - Скрыть/показать конструктивные оси

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_hideallcontrolpoints.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallauxiliarygeom.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- конструктивные оси скрыты,  
---|---  
FALSE | \- конструктивные оси показаны.  
  
Синтаксис Automation:

BOOL HideAllAxis = iObject.HideAllAxis | Получить свойство ([* ](1.html))  
---|---  
iObject.HideAllAxis = HideAllAxis | Установить свойство ([* ](1.html))  
BOOL HideAllAxis = iObject.GetHideAllAxis() | Получить свойство ([**](2.html))  
iObject.SetHideAllAxis (HideAllAxis) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_HideAllAxis (&HideAllAxis) | Получить свойство  
---|---  
iObject->put_HideAllAxis (HideAllAxis) | Установить свойство  
  
Примечание:

В зависимости от флага [HideInComponentsMode](ikompasdocument3d_hideincomponentsmode.html) позволяет скрыть или показать все вспомогательные объекты в документе или, если документ является сборкой, во вставках.

Подразделы:

(отсутствуют)
