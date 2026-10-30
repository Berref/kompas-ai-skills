# EntityCollection - Получить массив объектов (грани, ребра, вершины)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект Дерева построения (Интерфейсы ksFeature, IFeature) ](ksfeature.html) > [IFeature - методы ](ksfeature_methods.html) |  Scroll [ [ [ ](ksfeature_getobject.html "К следующему разделу")](ksfeature_methods.html "На уровень выше")](ksfeature_bodycollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfeature.html)

Синтаксис Automation:

ksEntityCollection * EntityCollection (short objType);

Синтаксис COM:

LPENTITYCOLLECTION EntityCollection (short objType);

Входные параметры:

objType | \- [тип объектов](obj3dtype.html) (грани, ребра, вершины).  
---|---  
  
Возвращаемое значение:

указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html) | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
