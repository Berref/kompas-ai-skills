# PlaceFeatureAfter - Поставить объект дерева после другого объекта дерева

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_rasterformatparam.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_partcollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL PlaceFeatureAfter( LPDISPATCH obj, LPDISPATCH afterObj );

Синтаксис COM:

BOOL PlaceFeatureAfter( LPFEATURE obj, LPFEATURE afterObj );

Входные параметры:

obj | \- указатель на перемещаемый объект дерева [ksFeature](ksfeature.html) или [IFeature](ksfeature.html),  
---|---  
afterObj | \- указатель на объект дерева, после которого нужно установить заданный объект [ksFeature](ksfeature.html) или [IFeature](ksfeature.html),  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
