# hideInComponentsMode - Режим скрытия вспомогательной геометрии в компонентах

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - свойства ](ksdocument3d_properties.html) |  Scroll [ [ [ ](ksdocument3d_hidelayoutgeometry.html "К следующему разделу")](ksdocument3d_properties.html "На уровень выше")](ksdocument3d_hideallthreads.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Тип данных: BOOL

Синтаксис:

hideInComponentsMode = Object.hideInComponentsMode | Получить свойство ([* ](1.html))  
---|---  
Object.hideInComponentsMode = hideInComponentsMode | Установить свойство ([* ](1.html))  
hideInComponentsMode = Object.GetHideInComponentsMode() | Получить свойство([**](2.html))  
Object.SetHideInComponentsMode(hideInComponentsMode ) | Установить свойство([**](2.html))  
  
Примечание:

Флаг позволяет для сборки включить режим работы с флагами скрытия вспомогательной геометрии во вставках или в документе.

Если флаг включен, то свойства: [hideAllPlanes](ksdocument3d_hideallplanes.html), [hideAllAxis](ksdocument3d_hideallaxis.html), [hideAllSketches](ksdocument3d_hideallsketches.html), [hideAllPlaces,](ksdocument3d_hideallplaces.html) [hideAllSurfaces](ksdocument3d_hideallsurfaces.html), [hideAllThreads](ksdocument3d_hideallthreads.html), [hideAllCurves](ksdocument3d_hideallcurves.html), [hideAllControlPoints](ksdocument3d_hideallcontrolpoints.html), [hideAllDimensions](ksdocument3d_hidealldimensions.html), [hideAllDesignations](ksdocument3d_hidealldesignations.html), [hideAllAuxiliaryGeom](ksdocument3d_hideallauxiliarygeom.html) управляют признаками скрытия вспомогательной геометрии во вставках.

Подразделы:

(отсутствуют)
