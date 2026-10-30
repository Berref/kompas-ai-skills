# OrientationNormalToAndAling - Повернуть нормаль и выровнять

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - методы](iviewprojectionmanager_methods.html) |  Scroll [ [ [ ](iviewprojectionmanager_setmatrix3d.html "К следующему разделу")](iviewprojectionmanager_methods.html "На уровень выше")](iviewprojectionmanager_orientationnormalto.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Синтаксис Automation:

BOOL OrientationNormalToAndAling( IModelObject * NormalObject, BOOL Inverse, BOOL Horizontally, IModelObject * DirectionObject );

Синтаксис COM:

HRESULT OrientationNormalToAndAling( IModelObject * NormalObject, BOOL Inverse, BOOL Horizontally, IModelObject * DirectionObject, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NormalObject | \- указатель на плоский объект [IModelObject](imodelobject.html) (плоская грань, координатная или вспомогательная плоскость, эскиз),  
---|---  
Inverse | \- направление,  
Horizontally | \- TRUE - горизонтально, FALSE - вертикально,  
DirectionObject | \- направляющий объект.  
  
Примечания:

В качестве плоского объекта может использоваться:

•плоская грань,

•координатная или вспомогательная плоскость,

•эскиз.

Направляющим объектом может быть:

•линия (пространственная кривая, линия эскиза, ребро), проекцией которой на выбранный плоский объект является прямая,

•плоский объект (плоскость, плоская грань, эскиз), который пересекается с выбранным плоским объектом (в случае выбора грани или эскиза, построенного на грани, пересечение должно быть в пределах этой грани).

В соответствии с выбранным вариантом модель после указания направляющего объекта повернется так, чтобы его проекция на выбранный ранее плоский объект (линия пересечения этих объектов) заняла горизонтальное или вертикальное положение.

Версия Компас v23

Подразделы:

(отсутствуют)
