# GetByIndex - Получить указатель на интерфейс объекта в массиве по индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbodycollection_getcount.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_first.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodycollection.html)

Синтаксис Automation:

LPDISPATCH GetByIndex (long index);

Синтаксис COM:

LPBODY GetByIndex (long index);

Входной параметр:

index | \- номер объекта в массиве.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html).  
---|---  
  
Подразделы:

(отсутствуют)
