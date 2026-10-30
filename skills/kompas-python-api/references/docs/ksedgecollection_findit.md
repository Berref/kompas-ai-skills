# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Трехмерное тело ](ca1747705.html) > [Интерфейсы, получаемые от ksFaceDefinition ](ca1747810.html) > [Массив ребер (Интерфейсы ksEdgeCollection, IEdgeCollection) ](ksedgecollection.html) > [IEdgeCollection - методы ](ksedgecollection_methods.html) |  Scroll [ [ [ ](ksedgecollection_first.html "К следующему разделу")](ksedgecollection_methods.html "На уровень выше")](ksedgecollection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksedgecollection.html)

Синтаксис Automation:

long FindIt(LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPEDGEDEFINITION entity);

Входные параметры:

entity | \- указатель на интерфейс компонента [ksEdgeDefinition](ksedgedefinition.html) или [IEdgeDefinition](ksedgedefinition.html).  
---|---  
  
Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Подразделы:

(отсутствуют)
