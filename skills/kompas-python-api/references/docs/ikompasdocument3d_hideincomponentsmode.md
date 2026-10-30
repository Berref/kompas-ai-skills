# HideInComponentsMode - Режим скрытия вспомогательной геометрии в компонентах

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - свойства ](ikompasdocument3d_props.html) |  Scroll [ [ [ ](ikompasdocument3d_perspective.html "К следующему разделу")](ikompasdocument3d_props.html "На уровень выше")](ikompasdocument3d_hideallthreads.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Тип данных: BOOL

Синтаксис Automation:

HideInComponentsMode = Object.HideInComponentsMode | Получить свойство ([* ](1.html))  
---|---  
Object.HideInComponentsMode = HideInComponentsMode | Установить свойство ([* ](1.html))  
HideInComponentsMode = Object.GetHideInComponentsMode() | Получить свойство ([**](2.html))  
Object.SetHideInComponentsMode( HideInComponentsMode ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_HideInComponentsMode( &HideInComponentsMode ) | Получить свойство  
---|---  
Object.put_HideInComponentsMode( HideInComponentsMode ) | Установить свойство  
  
Примечание:

Флаг позволяет для сборки включить режим работы с флагами скрытия вспомогательной геометрии во вставках или в документе.

Если флаг включен, то свойства: [HideAllPlanes](ikompasdocument3d_hideallplanes.html), [HideAllAxis](ikompasdocument3d_hideallaxis.html), [HideAllSketches](ikompasdocument3d_hideallsketches.html), [HideAllPlaces](ikompasdocument3d_hideallplaces.html), [HideAllSurfaces](ikompasdocument3d_hideallsurfaces.html), [HideAllThreads](ikompasdocument3d_hideallthreads.html), [HideAllCurves](ikompasdocument3d_hideallcurves.html), [HideAllControlPoints](ikompasdocument3d_hideallcontrolpoints.html), [HideAllDimensions](ikompasdocument3d_hidealldimensions.html), [HideAllDesignations](ikompasdocument3d_hidealldesignations.html), [HideAllAuxiliaryGeom](ikompasdocument3d_hideallauxiliarygeom.html)

управляют признаками скрытия вспомогательной геометрии во вставках.

Подразделы:

(отсутствуют)
