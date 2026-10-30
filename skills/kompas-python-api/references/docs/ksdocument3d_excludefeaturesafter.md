# ExcludeFeaturesAfter - Исключить\включить объекты после заданного

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_featurecollection.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_entitycollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL ExcludeFeaturesAfter( LPDISPATCH obj,

BOOL exclude );

Синтаксис COM:

BOOL ExcludeFeaturesAfter( LPFEATURE obj,

BOOL exclude );

Входные параметры:

obj | \- указатель на интерфейс объекта дерева [ksFeature](ksfeature.html) или [IFeature](ksfeature.html), после которого нужно исключить из расчета объекты,  
---|---  
exclude | \- TRUE - выключить объекты, \- FALSE - включить объекты.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
