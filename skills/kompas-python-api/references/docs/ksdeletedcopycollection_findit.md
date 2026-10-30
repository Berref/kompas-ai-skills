# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Интерфейс массива удаленных индексов для операций копирования и массивов компонентов (ksDeletedCopyCollection и IDeletedCopyCollection) ](ksdeletedcopycollection.html) > [ksDeletedCopyCollection - методы ](ksdeletedcopycollection_methods.html) |  Scroll [ [ [ ](ksdeletedcopycollection_first.html "К следующему разделу")](ksdeletedcopycollection_methods.html "На уровень выше")](ksdeletedcopycollection_detachbyindex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdeletedcopycollection.html)

Синтаксис Automation:

long FindIt (long index1, long index2);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt ( long index1, long index2);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
0xffffffff | \- если элемент не найден.  
  
Входные параметры:

index1, index2 | \- индексы удаленной копии в узоре.  
---|---  
  
Подразделы:

(отсутствуют)
