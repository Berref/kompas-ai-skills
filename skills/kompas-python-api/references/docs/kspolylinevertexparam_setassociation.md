# SetAssociation - Установить ассоциированную вершину

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_setbuildingobject.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_getvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис Automation:

BOOL SetAssociation (ksEntity * vertex);

Синтаксис COM:

BOOL SetAssociation( LPENTITY vertex);

Входные параметры:

vertex | \- указатель на интерфейс объекта [ksEntity](ksentity.html) или [IEntity](ksentity.html), если нужно установить ассоциацию,  
---|---  
NULL | \- если нужно снять ассоциацию.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Объект должен быть вершиной o3d_vertex.

Подразделы:

(отсутствуют)
