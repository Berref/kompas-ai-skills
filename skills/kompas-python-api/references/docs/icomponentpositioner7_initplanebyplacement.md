# InitPlaneByPlacement - Установить плоскость по СК

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IComponentPositioner7](icomponentpositioner7.html) > [IComponentPositioner7 - методы](icomponentpositioner7_methods.html) |  Scroll [ [ [ ](icomponentpositioner7_initplanebypoints.html "К следующему разделу")](icomponentpositioner7_methods.html "На уровень выше")](icomponentpositioner7_initplane.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](icomponentpositioner7.html)

Синтаксис Automation:

BOOL InitPlaneByPlacement( IPlacement3D * Placement );

Синтаксис COM:HRESULT InitPlaneByPlacement( IPlacement3D * Placement, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Placement | \- указатель на интерфейс[IPlacement3D](iplacement3d.html) системы координат, задающей плоскость.  
---|---  
  
Подразделы:

(отсутствуют)
