# AddAt - Добавить в массив объект с заданным индексом

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив объектов Дерева построения (Интерфейсы ksFeatureCollection, IFeatureCollection) ](ksfeaturecollection.html) > [ksFeatureCollection - методы ](ksfeaturecollection_methods.html) |  Scroll [ [ [ ](ksfeaturecollection_addbefore.html "К следующему разделу")](ksfeaturecollection_methods.html "На уровень выше")](ksfeaturecollection_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeaturecollection.html)

Синтаксис Automation:

BOOL AddAt (ksFeature* obj, long index );

Синтаксис COM:

BOOL AddAt (LPFEATURE obj, long index );

Входные параметры:

obj | \- указатель на интерфейс компонента [ksFeature](ksfeature.html) или [IFeature](ksfeature.html),  
---|---  
index | \- индекс нового элемента.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

При добавлении тела в макроэлемент в макроэлемент добавляются все операции данного тела на момент создания макроэлемента. Само тело в макроэлемент не добавляется.

Подразделы:

(отсутствуют)
