# Add - Добавить элемент в конец массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [IViewProjectionCollection - методы ](ksviewprojectioncollection_methods.html) |  Scroll [ [ [ ](ksviewprojectioncollection_addunfoldprojection.html "К следующему разделу")](ksviewprojectioncollection_methods.html "На уровень выше")](ksviewprojectioncollection_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojectioncollection.html)

Синтаксис Automation:

BOOL Add (LPDISPATCH projection);

Синтаксис COM:

BOOL Add (LPVIEWPROJECTION projection);

Входные параметры:

projection | \- указатель на интерфейс [ksViewProjection](ksviewprojection.html) или [IViewProjection](ksviewprojection.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Добавить в массив можно только проекцию с индексом vp_None. После добавления проекция становится текущей и ей присваивается новый индекс, равный ее индексу в массиве. После добавления проекции редактирование ее параметров невозможно.

Подразделы:

(отсутствуют)
