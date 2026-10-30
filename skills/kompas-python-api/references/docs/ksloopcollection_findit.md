# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы дополнительных элементов ](int_additional.html) > [Массив циклов грани (Интерфейсы ksLoopCollection, ILoopCollection) ](ksloopcollection.html) > [ILoopCollection - методы ](ksloopcollection_methods.html) |  Scroll [ [ [ ](ksloopcollection_first.html "К следующему разделу")](ksloopcollection_methods.html "На уровень выше")](ksloopcollection_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksloopcollection.html)

Синтаксис Automation:

long FindIt (LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPLOOP entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве.  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс компонента [ksLoop](ksloop.html) или [ILoop](ksloop.html).  
---|---  
  
Подразделы:

(отсутствуют)
