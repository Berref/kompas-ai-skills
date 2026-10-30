# SubFeatureCollection - Получить массив объектов, входящих в данный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_variablecollection.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_isvalid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

LPDISPATCH SubFeatureCollection (BOOL through, BOOL libObject);

Синтаксис COM:

LPFEATURECOLLECTION SubFeatureCollection (BOOL through, BOOL libObject);

Входные параметры:

Through | TRUE | \- выдавать все объекты, включая скрытые,  
---|---|---  
libObject | TRUE | \- выдавать состав библиотечных элементов.  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksFeatureCollection](ksfeaturecollection.html) или [IFeatureCollection](ksfeaturecollection.html).  
---|---  
  
Подразделы:

(отсутствуют)
