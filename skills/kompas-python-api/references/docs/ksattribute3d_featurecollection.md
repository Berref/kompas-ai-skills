# FeatureCollection - Получить массив объектов заданного типа, имеющих данный атрибут

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Интерфейс массива атрибутов объектов модели (Интерфейсы ksAttribute3DCollection, IAttribute3DCollection) ](ksattribute3dcollection.html) > [Работа с атрибутами объектов модели (Интерфейсы ksAttribute3D, IAttribute3D) ](ksattribute3d.html) > [IAttribute3D - методы ](ksattribute3d_methods.html) |  Scroll [ [ [ ](ksattribute3d_getnametype.html "К следующему разделу")](ksattribute3d_methods.html "На уровень выше")](ksattribute3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattribute3d.html)

Синтаксис Automation:

ksFeatureCollection* FeatureCollection(int objType);

Синтаксис COM:

LPFEATURECOLLECTION FeatureCollection(int objType);

Входные параметры:

objType | \- [тип трехмерного объекта](obj3dtype.html).  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksFeatureCollection](ksfeaturecollection.html). | \- массив, содержащий объекты дерева построений, на которые установлен данный атрибут, и которые имеют заданный тип.  
---|---  
  
Примечание:

Если objType = o3d_unknown - выдавать все объекты.

Подразделы:

(отсутствуют)
