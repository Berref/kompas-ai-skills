# Select - Выделить атрибуты данного типа или с данными ключами

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [Интерфейс массива атрибутов объектов модели (Интерфейсы ksAttribute3DCollection, IAttribute3DCollection) ](ksattribute3dcollection.html) > [IAttribute3DCollection - методы ](ksattribute3dcollection_methods.html) |  Scroll [ [ [ ](ksattribute3d.html "К следующему разделу")](ksattribute3dcollection_methods.html "На уровень выше")](ksattribute3dcollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattribute3dcollection.html)

Синтаксис

BOOL Select (long key1,

long key2,

long key3,

long key4,

double numb,

int objType);

Входные параметры:

key1, key2, key3, key4 | \- ключи для поиска по ключам либо 0,  
---|---  
numb | \- номер типа атрибута для поиска по номеру либо 0,  
objType | \- тип объекта: все объекты дерева построений, кроме компонентов, сопряжений, группы сопряжений.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
