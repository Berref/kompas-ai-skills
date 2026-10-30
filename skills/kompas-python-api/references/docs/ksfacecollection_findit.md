# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Массив граней (Интерфейсы ksFaceCollection, IFaceCollection) ](ksfacecollection.html) > [IFaceCollection - методы ](ksfacecollection_methods.html) |  Scroll [ [ [ ](ksfacecollection_getbyindex.html "К следующему разделу")](ksfacecollection_methods.html "На уровень выше")](ksfacecollection_first.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksfacecollection.html)

Синтаксис Automation:

long FindIt (LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt(LPFACEDEFINITION entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс компонента [ksFaceDefinition](ksfacedefinition.html) или [IFaceDefinition](ksfacedefinition.html).  
---|---  
  
Подразделы:

(отсутствуют)
