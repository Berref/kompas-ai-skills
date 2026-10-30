# SetBuildingObject - Установить объект относительно которого ведется построение

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_setparambydistance.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_setassociation.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис Automation:

BOOL SetBuildingObject (ksEntity * object);

Синтаксис COM:

BOOL SetBuildingObject (LPENTITY object);

Входные параметры:

object | \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html)  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Задать объект, относительно которого ведется построение, можно для типа построения [ksLineBuildingType](kslinebuildingtype.html), равного ksLBTParallel и ksLBTPerpendicular.

Подразделы:

(отсутствуют)
