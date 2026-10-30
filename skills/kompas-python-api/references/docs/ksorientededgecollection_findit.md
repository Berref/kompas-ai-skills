# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Массив ориентированных ребер (Интерфейсы ksOrientedEdgeCollection, IOrientedEdgeCollection) ](ksorientededgecollection.html) > [IOrientedEdgeCollection - методы ](ksorientededgecollection_methods.html) |  Scroll [ [ [ ](ksorientededgecollection_first.html "К следующему разделу")](ksorientededgecollection_methods.html "На уровень выше")](ksorientededgecollection_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksorientededgecollection.html)

Синтаксис Automation:

long FindIt (LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPORIENTEDEDGE entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс компонента [ksOrientedEdge](ksorientededge.html) или [IOrientedEdge](ksorientededge.html).  
---|---  
  
Подразделы:

(отсутствуют)
