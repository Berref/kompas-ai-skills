# AddBefore - Добавить объект перед указанным объектом в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив объектов Дерева построения (Интерфейсы ksFeatureCollection, IFeatureCollection) ](ksfeaturecollection.html) > [ksFeatureCollection - методы ](ksfeaturecollection_methods.html) |  Scroll [ [ [ ](ksfeaturecollection_attributecollection.html "К следующему разделу")](ksfeaturecollection_methods.html "На уровень выше")](ksfeaturecollection_addat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeaturecollection.html)

Синтаксис Automation:

BOOL AddBefore (ksFeature* obj, ksFeature* base);

Синтаксис COM:

BOOL AddBefore (LPFEATURE obj, LPFEATURE base);

Входные параметры:

obj | \- указатель на интерфейс компонента [ksFeature](ksfeature.html) или [IFeature](ksfeature.html),  
---|---  
base | \- указатель на элемент массива.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
