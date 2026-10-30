# SetParamByVertex - Установить параметры вершины по парамерам вершины другого объекта

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс параметров вершины ломаной Интерфейсы ksPolyLineVertexParam, IPolygonalLineVertexParam) ](kspolylinevertexparam.html) > [IPolygonalLineVertexParam - методы ](kspolylinevertexparam_methods.html) |  Scroll [ [ [ ](kspolylinevertexparam_setparamvertex.html "К следующему разделу")](kspolylinevertexparam_methods.html "На уровень выше")](kspolylinevertexparam_setparambydistance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspolylinevertexparam.html)

Синтаксис Automation:

BOOL SetParamByVertex (ksEntity * vertex, double radius);

Синтаксис COM:

BOOL SetParamByVertex (LPENTITY vertex, double radius);

Входные параметры:

vertex | \- указатель на интерфейс параметров вершины [ksEntity](ksentity.html) или [IEntity](ksentity.html),  
---|---  
radius | \- радиус.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
