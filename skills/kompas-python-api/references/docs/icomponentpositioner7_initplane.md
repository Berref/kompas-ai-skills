# InitPlane - Установить плоскость

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IComponentPositioner7](icomponentpositioner7.html) > [IComponentPositioner7 - методы](icomponentpositioner7_methods.html) |  Scroll [ [ [ ](icomponentpositioner7_initplanebyplacement.html "К следующему разделу")](icomponentpositioner7_methods.html "На уровень выше")](icomponentpositioner7_initaxisbypoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](icomponentpositioner7.html)

Синтаксис Automation:

BOOL InitPlane( IModelObject * Plane );

Синтаксис COM:

HRESULT InitPlane( IModelObject * Plane, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Plane | \- указатель на интерфейс конструктивной плоскости или плоской поверхности [IModelObject](imodelobject.html).  
---|---  
  
Подразделы:

(отсутствуют)
