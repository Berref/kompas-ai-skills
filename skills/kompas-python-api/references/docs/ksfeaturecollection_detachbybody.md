# DetachByBody - Удалить указанный объект из массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Массив объектов Дерева построения (Интерфейсы ksFeatureCollection, IFeatureCollection) ](ksfeaturecollection.html) > [ksFeatureCollection - методы ](ksfeaturecollection_methods.html) |  Scroll [ [ [ ](ksfeaturecollection_detachbyindex.html "К следующему разделу")](ksfeaturecollection_methods.html "На уровень выше")](ksfeaturecollection_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeaturecollection.html)

Синтаксис Automation:

BOOL DetachByBody (LPDISPATCH obj);

Синтаксис COM:

BOOL DetachByBody (LPFEATURE obj);

Входные параметры:

obj | \- указатель на интерфейс удаляемого объекта [ksFeature](ksfeature.html) или [IFeature](ksfeature.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатель на интерфейс удаляемого объекта obj не должен быть 0.

Подразделы:

(отсутствуют)
