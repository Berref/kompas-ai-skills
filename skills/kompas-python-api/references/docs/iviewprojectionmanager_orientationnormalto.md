# OrientationNormalTo - Нормаль к...

[API интерфейсов. Версия 7](applicate.html) > [Управление изображением модели](view_managment.html) > [Интерфейс IViewProjectionManager](iviewprojectionmanager.html) > [IViewProjectionManager - методы](iviewprojectionmanager_methods.html) |  Scroll [ [ [ ](iviewprojectionmanager_orientationnormaltoandaling.html "К следующему разделу")](iviewprojectionmanager_methods.html "На уровень выше")](iviewprojectionmanager_addunfoldprojection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iviewprojectionmanager.html)

Синтаксис Automation:

BOOL OrientationNormalTo( IModelObject * NormalObject );

Синтаксис COM:

HRESULT OrientationNormalTo( IModelObject * NormalObject, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

NormalObject | \- указатель на плоский объект [IModelObject](imodelobject.html).  
---|---  
  
Примечания:

В качестве плоского объекта может использоваться:

•плоская грань,

•координатная или вспомогательная плоскость,

•эскиз.

Версия Компас v23

Подразделы:

(отсутствуют)
