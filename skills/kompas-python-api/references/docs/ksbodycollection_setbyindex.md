# SetByIndex - Заменить объект с указанным индексом в массиве на присланный объект

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbody.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_refresh.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodycollection.html)

Синтаксис Automation:

BOOL SetByIndex(LPDISPATCH body, long index);

Синтаксис COM:

BOOL SetByIndex(LPBODY body, long index);

Входные параметры:

body | \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html) присоединяемого объекта,  
---|---  
index | \- индекс элемента в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
