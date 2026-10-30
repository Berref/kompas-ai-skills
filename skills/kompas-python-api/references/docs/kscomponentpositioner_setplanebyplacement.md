# SetPlaneByPlacement - Задать плоскость по системе координат

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс управления положением компонентов в сборке (Интерфейсы ksComponentPositioner, IComponentPositioner) ](kscomponentpositioner.html) > [IComponentPositioner - методы ](kscomponentpositioner_methods.html) |  Scroll [ [ [ ](kscomponentpositioner_setplanebypoints.html "К следующему разделу")](kscomponentpositioner_methods.html "На уровень выше")](kscomponentpositioner_setplane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscomponentpositioner.html)

Синтаксис Automation:

BOOL SetPlaneByPlacement (ksPlacement * plane);

Синтаксис COM:

BOOL SetPlaneByPlacement (LPPLACEMENT plane);

Входные параметры:

plane | \- указатель на интерфейс [ksPlacement](ksplacement.html) или [IPlacement](ksplacement.html) системы координат, задающей плоскость.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Система координат, задающая плоскость, должна быть определена относительно сборки.

Подразделы:

(отсутствуют)
