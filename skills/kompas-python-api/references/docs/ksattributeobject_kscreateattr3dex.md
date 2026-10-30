# ksCreateAttr3DEx - Cоздать атрибут по номеру типа атрибута из библиотеки libname

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kscreateattrtype.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kscreateattr3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateAttr3DEx](kscreateattr3dex.html).

Синтаксис Automation:

ksAttribute3D * ksCreateAttr3DEx (LPDISPATCH pObj,

LPDISPATCH pSourcePart,

LPDISPATCH attr,

double attrID,

BSTR libname);

Входные параметры:

[pObj](pobj.html) | \- указатель на объект для которого создается атрибут,  
---|---  
sourcePart | \- указатель на интерфейс вставки детали [IPart,](kspart.html)  
attr | \- указатель на структуру параметров атрибута [ksAttribute](structksattribute.html),  
attrID | \- уникальный номер типа атрибута,  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется в документе.  
  
Возвращаемое значение:

Указатель на атрибут [IAttribute3D](ksattribute3d.html) | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если libname = NULL - тип атрибута берется в документе.

2\. pObj - может быть равен:

•NULL или указателю на интерфейс 3d документа [IDocument3D](ksdocument3d.html) \- создается атрибут у документа,

•указателю на интерфейс коллекции объектов дерева [IFeatureCollection](ksfeaturecollection.html) \- атрибут групповой,

•указателю на интерфейс объекта дерева [IFeature](ksfeature.html) \- атрибут у определенного объекта.

3\. Атрибут можно добавить ко всем объектам дерева построений, кроме верхнего компонентов, сопряжений, группы сопряжений.

4\. sourcePart - может быть:

•NULL - атрибут будет создан в текущем документе,

•указателю на интерфейс детали или подсборки вставленной в сборку [IPart](kspart.html) \- атрибут будет создан в документе-источнике,

•если sourcePart == pObj создается атрибут документа в источнике.

Подразделы:

(отсутствуют)
