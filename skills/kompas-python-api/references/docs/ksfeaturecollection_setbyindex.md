# SetByIndex - Заменить объект с указанным индексом в массиве на присланный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив объектов Дерева построения (Интерфейсы ksFeatureCollection, IFeatureCollection) ](ksfeaturecollection.html) > [ksFeatureCollection - методы ](ksfeaturecollection_methods.html) |  Scroll [ [ [ ](ksvariablecollection.html "К следующему разделу")](ksfeaturecollection_methods.html "На уровень выше")](ksfeaturecollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeaturecollection.html)

Синтаксис Automation:

BOOL SetByIndex (ksFeature* obj, long index);

Синтаксис COM:

BOOL SetByIndex (LPFEATURE obj, long index);

Входные параметры:

obj | \- указатель на интерфейс компонента [ksFeature](ksfeature.html) или [IFeature](ksfeature.html),  
---|---  
index | \- индекс элемента в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
