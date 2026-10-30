# Add - Добавить объект в конец массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы копирования ](int_copy.html) > [Интерфейс массива удаленных индексов для операций копирования и массивов компонентов (ksDeletedCopyCollection и IDeletedCopyCollection) ](ksdeletedcopycollection.html) > [ksDeletedCopyCollection - методы ](ksdeletedcopycollection_methods.html) |  Scroll [ [ [ ](ksdeletedcopycollection_addat.html "К следующему разделу")](ksdeletedcopycollection_methods.html "На уровень выше")](ksdeletedcopycollection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdeletedcopycollection.html)

Синтаксис Automation:

BOOL Add (long index1, long index2);

Синтаксис COM:

BOOL GetByIndex (long index, long * index1, long * index2);

Входные параметры:

index1, index2 | \- индексы удаленной копии в узоре.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
