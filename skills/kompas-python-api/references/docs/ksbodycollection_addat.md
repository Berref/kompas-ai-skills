# AddAt - Добавить объект с заданным индексом в массив

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейс массива трехмерных тел (Интерфейсы ksBodyCollection, IBodyCollection) ](ksbodycollection.html) > [IBodyCollection - методы ](ksbodycollection_methods.html) |  Scroll [ [ [ ](ksbodycollection_addbefore.html "К следующему разделу")](ksbodycollection_methods.html "На уровень выше")](ksbodycollection_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ksbodycollection.html)

Синтаксис Automation:

BOOL AddAt(LPDISPATCH body, long index);

Синтаксис COM:

BOOL AddAt(LPBODY body, long index);

Входные параметры:

body | \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html),  
---|---  
index | \- индекс в массиве.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Указатель на интерфейс добавляемого объекта body не должен быть равен 0.

Подразделы:

(отсутствуют)
