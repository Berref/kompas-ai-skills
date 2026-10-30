# AddBefore - Добавить объект перед указанным объектом в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbodycollection_clear.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_addat.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodycollection.html)

Синтаксис Automation:

BOOL AddBefore(LPDISPATCH body, LPDISPATCH base);

Синтаксис COM:

BOOL AddBefore(LPBODY body, LPBODY base);

Входные параметры:

body | \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html) добавляемого объекта,  
---|---  
base | \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html) базового объекта.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатели на интерфейсы добавляемого и базового объекта body и base не должны быть равны 0.

Подразделы:

(отсутствуют)
